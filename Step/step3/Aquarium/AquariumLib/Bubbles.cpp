/**
 * @file Bubbles.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "Aquarium.h"
#include "Bubbles.h"

using namespace std;

/// Fish Filename
const wstring FishBubblesImageName = L"images/bubbles.png";

/**
 * Constructor
 * @param aquarium  Aquarium this fish is a member of
 */
 //find out why we do the Item thing at the end
 Bubbles::Bubbles(Aquarium *aquarium) : Item(aquarium)
 {
	 mBubblesImage = make_unique<wxImage>(FishBubblesImageName,wxBITMAP_TYPE_ANY);
	 mBubblesBitmap = make_unique<wxBitmap>(*mBubblesImage);
 }

 /**
  * Draw the Bubbles fish
  * @param dc Device context to draw on
  */
void Bubbles::Draw(wxDC *dc)
{
	double wid = mBubblesImage->GetWidth();
	double hit = mBubblesImage->GetHeight();
	dc->DrawBitmap(*mBubblesBitmap,
				   int(GetX() - wid / 2),
				   int(GetY() - hit / 2));
}
/**
 * Tells if the spot you clicked is in side of the fish image by return true
 *
 * @param x x coordinate of the screen
 * @param y Y coordinate of the screen
 * @return True if x and y are in the fish
 */
bool Bubbles::HitTest(int x, int y)
{
	double wid = mBubblesImage->GetWidth();
	double hit = mBubblesImage->GetHeight();

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

	// Test to see if x, y are in the drawn part of the image
	// If the location is transparent, we are not in the drawn
	// part of the image
	return !mBubblesImage->IsTransparent((int)testX, (int)testY);
}
