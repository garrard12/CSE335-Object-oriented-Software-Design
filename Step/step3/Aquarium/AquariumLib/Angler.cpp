/**
 * @file Angler.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "Angler.h"
#include "Aquarium.h"

using namespace std;

/// Fish filename
const wstring FishAnglerImageName = L"images/angler.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
 Angler::Angler(Aquarium *aquarium) : Item(aquarium)
 {
	mAnglerImage = make_unique<wxImage>(FishAnglerImageName,wxBITMAP_TYPE_ANY);
	mAnglerBitMap = make_unique<wxBitmap>(*mAnglerImage);
 }
/**
* Draw Angler fish
* @param dc Device context to draw on
*/
 void Angler::Draw(wxDC *dc)
 {
	 double wid = mAnglerImage->GetWidth();
	 double hit = mAnglerImage->GetHeight();
	 dc->DrawBitmap(*mAnglerBitMap,
					int(GetX() - wid / 2),
					int(GetY() - hit / 2));
 }

/**
 * Tells if the spot you clicked is in side of the fish image by return true
 *
 * @param x x coordinate of the screen
 * @param y Y coordinate of the screen
 * @return True if x and y are in the fish else it's false
 */

 bool Angler::HitTest(int x, int y)
 {
	 double wid = mAnglerImage->GetWidth();
	 double hit = mAnglerImage->GetHeight();

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
	 return !mAnglerImage->IsTransparent((int)testX, (int)testY);
 }


