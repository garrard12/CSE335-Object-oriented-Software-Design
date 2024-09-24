/**
 * @file Item.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "Item.h"
#include "Aquarium.h"

using namespace std;

/**
 * Destructor
 */
 Item::~Item()
 {
 }

/**
 * Constructor
 * @param aquarium The aquarium this item is a member of
 * @param filename The name of the fish
 */
Item::Item(Aquarium *aquarium,const std::wstring &filename) : mAquarium(aquarium)
{
	mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
	mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}

/**
 * Compute the distance from this item to another item
 * @param item Item we are computing the distance to
 * @return Distance in pixels
 */
double Item::DistanceTo(std::shared_ptr<Item> item)
{
	auto dx = item->GetX() - GetX();
	auto dy = item->GetY() - GetY();
	return sqrt(dx * dx + dy * dy);
}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit else false
 */
bool Item::HitTest(int x, int y)
{
	double wid = mItemBitmap->GetWidth();
	double hit = mItemBitmap->GetHeight();

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
	return !mItemImage->IsTransparent((int)testX, (int)testY);
}
/**
 * Draw the Bubbles fish
 * @param dc Device context to draw on
 */
void Item::Draw(wxDC *dc)
{
	double wid = mItemImage->GetWidth();
	double hit = mItemImage->GetHeight();
	dc->DrawBitmap(*mItemBitmap,
				   int(GetX() - wid / 2),
				   int(GetY() - hit / 2));
}

/**
 * Save this item to an XML node
 * @param node The parent node we are going to be a child of
 * @return wxXmlNode that we saved the item into
 */
wxXmlNode *Item::XmlSave(wxXmlNode *node)
{
	auto itemNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"item");
	node->AddChild(itemNode);

	// Saves the location of the fish
	itemNode->AddAttribute(L"x", wxString::FromDouble(mX));
	itemNode->AddAttribute(L"y", wxString::FromDouble(mY));

	return itemNode;
}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void Item::XmlLoad(wxXmlNode *node)
{
	node->GetAttribute(L"x", L"0").ToDouble(&mX);
	node->GetAttribute(L"y", L"0").ToDouble(&mY);
}

/**
 * Set the mirror status
 * @param m New mirror flag
 */
void Item::SetMirror(bool m) {
	if(m != mMirror)
	{
		mMirror = m;
		if(mMirror)
		{
			mItemBitmap = make_unique<wxBitmap>(mItemImage->Mirror());
		}
		else
		{
			mItemBitmap = make_unique<wxBitmap>(*mItemImage);
		}
	}
}