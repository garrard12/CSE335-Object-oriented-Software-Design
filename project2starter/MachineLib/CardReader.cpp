/**
 * @file CardReader.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "CardReader.h"
#include "Component.h"
#include "AirSource.h"

using namespace std;

/// Image for the back of the card reader
const std::wstring CardReaderBackImage = L"/images/card-reader-back.png";

/// Image for the front of the card reader
const std::wstring CardReaderFrontImage = L"/images/card-reader-front.png";

// The card actual dimensions are 847 by 379 pixels,
// a size chosen to make the column spacing exactly
// 10 pixels. We draw it much smaller than that on the screen

/// Width to draw the card on the screen in pixels
const int CardWidth = 132;

/// Height to draw the card on the screen in pixels
const int CardLength = 297;

/// Amount of offset the center of the card so it will
/// appear at the right place relative to the card reader.
const int CardOffsetX = 126;

/// Y dimension of the offset
const int CardOffsetY = 65;

// These values are all for the underlying image. They
// can be used for find the punches.

/// Width of a card column in pixels
const int CardColumnWidth = 10;

/// Height of a card row in pixels
const int CardRowHeight = 29;

/// X offset for the first column (left side)
const int CardColumn0X = 24;

/// Y offset to the first row (0's)
/// There are actually two rows above this that can be used
const int CardRow0Y = 78;

/// Width of a punched hole
const int CardPunchWidth = 8;

/// Height of a punched hole
const int CardPunchHit = 20;

/// Any average luminance below this level is considered a punched hole
const double CardPunchLuminance = 0.1;

//
// These values are for the outputs of the card reader,
// where the tubing attaches.
//

/// Y offset to the first card reader output in pixels
const int OutputOffsetY = -92;

/// X offset to the first card reader output in pixels
const int OutputOffsetX = -35;

/// X spacing for the outputs
const double OutputSpacingX = 10.7;

/// Number of air sources
const int NumOfAirSources = 10;
/// The min number of Columns
const int MinNumberOfColumn = 0;
/// The max Number of Column
const int MaxNumberOfColumn = 80;
/// When the note start ending
const double SecondHalfOfNote = .5;

/**
 * Constructor
 * @param resourcesDir The directry of the images
 */
CardReader::CardReader(std::wstring resourcesDir)
		: mResourcesDir(resourcesDir)
{
	// Add the 10 air sources to vector and set the connections
	for (int i = 0; i < NumOfAirSources; i++)
	{
		shared_ptr<AirSource> airSource = make_shared<AirSource>();
		airSource->SetAirSource(this);
		mSources.push_back(airSource);
	}
	//
	// Set up the card reader
	//
	mBack.SetImage(resourcesDir + CardReaderBackImage);
	mBack.Rectangle(-mBack.GetImageWidth() / 2, 0);

	mCard.Rectangle(CardOffsetX, CardOffsetY, CardLength, CardWidth);
	mCard.SetRotation(-0.25);

	mFront.SetImage(resourcesDir + CardReaderFrontImage);
	mFront.Rectangle(-mFront.GetImageWidth() / 2, 0);
}
/**
 * Draws the card reader
 * @param graphics The graphic to draw
 * @param x The x location to the machine
 * @param y The y location to the machine
 */
void CardReader::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
	x += GetX();
	y += GetY();
	mBack.DrawPolygon(graphics, x , y );
	auto cardScale = (double)CardLength / mCard.GetImageWidth();
	mCard.DrawPolygon(graphics, x , y + (mCurrentColumn-1) * cardScale * CardColumnWidth);
	mFront.DrawPolygon(graphics, x , y);

}
/**
 * Moves the card down the machine
 * @param elapsed How much time has passed
 */
void CardReader::UpdateTime(double elapsed)
{
	double beat = elapsed * mBeatsPerMinute / 60.0;
	//
	// remainder will be used for the cylinder
	//
	double remainder = fmod(beat, 1);
	mCurrentColumn = (int)beat;

	//Check to make sure that you are on the valid column
	if(mCurrentColumn > MinNumberOfColumn && mCurrentColumn < MaxNumberOfColumn)
	{
		for(int row = 0; row < NumOfAirSources; row++)
		{
			bool punched = IsPunched(mCurrentColumn, row);
			// Is the the note over
			if(!punched)
			{
				mSources[row]->SendAir(0);
			}
			else
			{
				//
				//  Checks to see is the ram should be retracted
				//
				if(remainder <= SecondHalfOfNote)
				{
					mSources[row]->SendAir(remainder);
				}
				else
				{
					mSources[row]->SendAir(1);
				}
			}
		}
	}

}
/**
 * Determine if a hole is punched in the card.
 * @param column Column on the card, from 0 (left of first column) to 80 (last column)
 * @param row Row on the card, -2 to 9.
 * @return True if hole is punched at column, row
*/
bool CardReader::IsPunched(int column, int row)
{
	auto luminance = mCard.AverageLuminance(CardColumn0X + (column - 1) * CardColumnWidth,
											CardRow0Y + CardRowHeight * row, CardPunchWidth, CardPunchHit);
	return luminance < CardPunchLuminance;
}