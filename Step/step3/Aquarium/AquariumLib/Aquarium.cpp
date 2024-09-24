/**
 * @file Aquarium.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "Aquarium.h"
#include "FishBeta.h"

#include <algorithm>

using namespace std;

/// Initial fish X location
const int InitialX = 200;

/// Initial fish Y location
const int InitialY = 200;

/// Distance other fish run when gus passes gas
const double GasRunDistance = 50;

/// Checks to see if Delta is zero
const double DeltaCheck = 0;

/// Initial vector value
const double InitialVector = 0;

/// The number of pixel the fish needs to move
const int MoveFish = 10;

/**
* Aquarium Constructor
*/
Aquarium::Aquarium()
{
	mBackground = make_unique<wxBitmap>(L"images/background1.png", wxBITMAP_TYPE_ANY);
}

/**
 * Draw the aquarium
 * @param dc The device context to draw on
*/
void Aquarium::OnDraw(wxDC *dc)
{
	//Add this as the first line so that it can have stuff drawn on it
	dc->DrawBitmap(*mBackground, 0, 0);

	wxFont font(wxSize(0, 20),
				wxFONTFAMILY_SWISS,
				wxFONTSTYLE_NORMAL,
				wxFONTWEIGHT_NORMAL);
	dc->SetFont(font);
	dc->SetTextForeground(wxColour(0, 64, 0));
	dc->DrawText(L"Under the Sea!", 10, 10);

	for (auto item :mItems)
	{
		item->Draw(dc);
	}
}


/**
 * Add an item to the aquarium
 * @param item New item to add
 */
void Aquarium::Add(std::shared_ptr<Item> item)
{
	int updatedX = InitialX;;
	int updatedY = InitialY;
	//Set the fish location initial the 200 location
	item->SetLocation(updatedX, updatedY);

	for (int i = 0; i < mItems.size();i++)
	{
		for (int j = i; j >= 0 ;j--)
		{
			//add 0 test case to get by the second one
			//This finds distance to another object and see how it works
			//This is call the item before it
			if(mItems[j]->DistanceTo(item) <= 1)
			{
				updatedX += MoveFish;
				updatedY += MoveFish;
				item->SetLocation(updatedX, updatedY);
			}
		}
	}
	// Add it to the list
	mItems.push_back(item);
}

/**
 * Take the last touched Item and moves it to the end of the list
 * @param item Item an pointer to item in the aquarium
 */
void Aquarium::UpdateList(std::shared_ptr<Item> item)
{
	//finds the location of item in the list
	auto loc = find(begin(mItems), end(mItems), item);
	//if item is not found then iterator will be at the end of the list so
	if (loc != end(mItems))
	{
		mItems.erase(loc);
	}
	//push the item back to the end of the list
	mItems.push_back(item);
}

/**
 * Test an x,y click location to see if it clicked
 * on some item in the aquarium.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Aquarium::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}
	return  nullptr;
}

/**
 * Iterates over all fish besides the fish in the list
 * and call DoubleClickTest on them
 *
 * @param item The last fish grabbed
 */
void Aquarium::DoubleClickTest(std::shared_ptr<Item> item)
{
	for(auto fish : mItems)
	{
		if(item == fish){
			continue;
		}

		//Get the distance locations of the fish and Gus
		auto gussX = item->GetX();
		auto gussY = item->GetY();

		auto fishX = fish->GetX();
		auto fishY = fish->GetY();

		//Finds the vector from the other fish to Gus
		auto deltaX = fishX - gussX;
		auto deltaY = fishY - gussY;

		//If fish is on top of Gus move x and y by 50 pixels
		if ( deltaY == DeltaCheck && deltaX == DeltaCheck)
		{
			fish->SetLocation(fishX + GasRunDistance, fishY + GasRunDistance);
			continue;
		}

		//computes the distance to the other fish
		auto vectorLength = sqrt((deltaX * deltaX) + (deltaY * deltaY));

		//Caculate the distance need to move the Fish
		auto movementVectorX = deltaX  * GasRunDistance / vectorLength;
		auto movementVectorY = deltaY * GasRunDistance / vectorLength;

		//Sets the new location of the fish
		auto newLocationX = movementVectorX + fishX;
		auto newLocationY = movementVectorY + fishY;
		fish->SetLocation(newLocationX,newLocationY);
	}
}


