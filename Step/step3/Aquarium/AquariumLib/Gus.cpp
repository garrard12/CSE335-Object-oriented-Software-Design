/**
 * @file Gus.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "Gus.h"
#include "Aquarium.h"

using namespace std;

/// Fish filename
const wstring FishGusImageName = L"images/gus.png";

/// Fish filename when gaseous
const wstring FishGaseousGusImageName = L"images/gus-f.png";



/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
Gus::Gus(Aquarium *aquarium) : Item(aquarium)
{
	mGusImage = make_unique<wxImage>(FishGusImageName,wxBITMAP_TYPE_ANY);
	mGusBitMap = make_unique<wxBitmap>(*mGusImage);
}
/**
* Draw Gus fish
* @param dc Device context to draw on
*/
void Gus::Draw(wxDC *dc)
{
	double wid = mGusImage->GetWidth();
	double hit = mGusImage->GetHeight();
	dc->DrawBitmap(*mGusBitMap,
				   int(GetX() - wid / 2),
				   int(GetY() - hit / 2));
}
/**
 * Tells if the spot you clicked is in side of the fish image by return true
 * @param x x coordinate of the screen
 * @param y Y coordinate of the screen
 * @return True if x and y are in the fish
 */
bool Gus::HitTest(int x, int y)
{
	double wid = mGusImage->GetWidth();
	double hit = mGusImage->GetHeight();

	// Make x and y relative to the top-left corner of the bitmap image
	// Subtracting the center makes x, y relative to the image center
	// Adding half the size makes x, y relative to the image top corner
	double testX = x - GetX() + wid / 2;
	double testY = y - GetY() + hit / 2;

	// Test to see if x, y are in the image
	if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
	{
		// We are outside the image
		return false;
	}

	Gus::SingleClickTest();

	// Test to see if x, y are in the drawn part of the image
	// If the location is transparent, we are not in the drawn
	// part of the image
	return !mGusImage->IsTransparent((int)testX, (int)testY);
}

/**
 * Checks to see if the image needs to be converted Gasses Gus
 * @param item the image of Gus
 */
void Gus::DoubleClickTest(std::shared_ptr<Item> item)
{
	auto aquarium= GetAquarium();
	aquarium->DoubleClickTest(item);

	//Changing image
	if(mGus == true)
	{
		//Changes the image of regular gus to Gasses Gus
		mGusImage = make_unique<wxImage>(FishGaseousGusImageName, wxBITMAP_TYPE_ANY);
		mGusBitMap = make_unique<wxBitmap>(*mGusImage);
		mGus = false;
	}

}

/**
 * Converts Gasses Gus back to Gus
 */
void Gus::SingleClickTest()
{
	if (mGus == false)
	{
		mGusImage = make_unique<wxImage>(FishGusImageName,wxBITMAP_TYPE_ANY);
		mGusBitMap = make_unique<wxBitmap>(*mGusImage);
		mGus = true;
	}
}
