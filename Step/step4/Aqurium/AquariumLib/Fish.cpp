/**
 * @file Fish.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "Aquarium.h"
#include "Fish.h"

using namespace std;

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 50;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedX = 20;

/// How many pixels we between the fish
/// and the wall
const double PixelRange = 10;

/// The number two
double const NumberTwo = 2;


/**
 * Constructor
 * @param aquarium The aquarium we are in
 * @param filename Filename for the image we use
 */
Fish::Fish(Aquarium *aquarium, const std::wstring &filename) :
	Item(aquarium, filename)
{
	std::uniform_real_distribution<> distribution(MinSpeedX, MaxSpeedX);
	mSpeedX = distribution(aquarium->GetRandom());
	mSpeedY = distribution(aquarium->GetRandom());
}

/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */
void Fish::Update(double elapsed)
{
	SetLocation(GetX() + mSpeedX * elapsed,
				GetY() + mSpeedY * elapsed);

	makeFishDifferent();

	//Calculation for the bottom floor and
	double wallRight = GetAquarium()->GetWidth() - PixelRange - GetWidth() / NumberTwo;
	double wallBottom = GetAquarium()->GetHeight() - PixelRange - GetWidth() / NumberTwo;

	//For the left and right wall
	if (mSpeedX > 0 && GetX() >= wallRight)
	{
		//makeFishDifferent();
		mSpeedX = -mSpeedX;
		SetMirror(true);
	}
	if (mSpeedX < 0 && GetX() < (PixelRange  + GetWidth() / NumberTwo))
	{
		mSpeedX = -mSpeedX;
		SetMirror(false);
	}

	//For the top and bottom walls
	if (mSpeedY > 0  && GetY() >  wallBottom)
	{
		mSpeedY = -mSpeedY;
	}
	if(mSpeedY < 0 && GetY() < (PixelRange  + GetWidth() / NumberTwo))
	{
		mSpeedY = -mSpeedY;
	}
}