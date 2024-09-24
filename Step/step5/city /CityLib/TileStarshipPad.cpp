/**
 * @file TileStarshipPad.cpp
 *
 * @author Charles B. Owen
 */

#include "pch.h"
#include <sstream>
#include <sstream>
#include <iostream>
#include "City.h"
#include "TileStarshipPad.h"
#include "MemberReport.h"
#include "Starship.h"
#include "RocketCounter.h"
#include "DeletePadVisitor.h"

/// The image to display for the starship pad
const std::wstring StarshipPadImage = L"pad.png";

/// The max numbers of StarShips on the screen
const int MaxNumberOfStarShips = 1;


/** Constructor
* @param city The city this is a member of
*/
TileStarshipPad::TileStarshipPad(City* city) : Tile(city)
{
    SetImage(StarshipPadImage);

	//Visits all the pads and see how many starship there are
	RocketCounter visitor;
	city->Accept(&visitor);
	int cnt = visitor.GetNumRockets(); // This is visiting correct

	// Tells it to draw the function if to many
	if (cnt < MaxNumberOfStarShips)
	{
		mStarship = std::make_shared<Starship>(city);
		mStarship->SetLaunchingPad(this);
	}
}


/**
* Save this item to an XML node
* @param node The node we are going to be a child of
* @return Allocated node
*/
wxXmlNode* TileStarshipPad::XmlSave(wxXmlNode* node)
{
    auto itemNode = Tile::XmlSave(node);

    itemNode->AddAttribute(L"type", L"starship-pad");

    return itemNode;
}


/**
 * Generate a report for this  tile.
 * @param report
*/
void TileStarshipPad::Report(std::shared_ptr<MemberReport> report)
{
    std::wstringstream str;
    str << L"Starship Pad";

    report->SetReport(str.str());
}

/**
 * Indicate that this object is about to be deleted by
 * begin dragged into the trash can. If the function
 * override returns false, the delete will not occur.
 * @return true if okay to delete.
*/
bool TileStarshipPad::PendingDelete()
{
	// Check to see if the pad has Starship
	if (mStarship != nullptr)
	{
		DeletePadVisitor deletePadVisitor(this);
		this->GetCity()->Accept(&deletePadVisitor);
	}
    return true;
}

/**
 * This function is called when the Starship has
 * landed on some other pad. It is no longer accessible to
 * this pad.
*/
void TileStarshipPad::StarshipIsGone()
{
	//This should probably be setting mStarShip to null
	mStarship = nullptr;
}

/**
 * This function is called when the Starship has landed on this
 * pad. This pad should now become the launching pad.
*/
void TileStarshipPad::StarshipHasLanded()
{
	mStarship->SetLaunchingPad(this);
}

/**
 * Draws the rocket on the pad
 * @param dc Device context to draw the tile on
 */
void TileStarshipPad::Draw(wxDC* dc)
{
	// This is up calling the
	Tile::Draw(dc);
	if(mStarship != nullptr)
	{
		mStarship->Draw(this,dc);
	}

}
/**
 * Updates the starship to the given pad
 * @param elapsed The time that went by
 */
void TileStarshipPad::Update(double elapsed)
{
	// This is up calling
	Tile::Update(elapsed);
	//If it is not
	if(mStarship != nullptr){
		mStarship->Update(this,elapsed);
	}

}


