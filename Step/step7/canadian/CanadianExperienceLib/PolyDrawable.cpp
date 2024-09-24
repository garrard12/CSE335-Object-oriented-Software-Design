/**
 * @file PolyDrawable.cpp
 * @author Auden Garrard
 */
#include "pch.h"
#include "PolyDrawable.h"
#include "Drawable.h"

/**
 * Constructor
 * @param name The drawable name
 */
PolyDrawable::PolyDrawable(const std::wstring &name) : Drawable(name)
{
}

/**
 * Constructor
 * @param name The name of the image
 * @param filename The name of the file
 */
PolyDrawable::PolyDrawable(const std::wstring &name, const std::wstring &filename):
	Drawable(name)
{
	mImage = std::make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
}
/**
* Draw this drawable
* @param gc Graphics object to draw on
*/
void PolyDrawable::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
	if(!mPoints.empty()) {

		mPath = gc->CreatePath();
		mPath.MoveToPoint(RotatePoint(mPoints[0], mPlacedR) + mPlacedPosition);
		for (auto i = 1; i<mPoints.size(); i++)
		{
			mPath.AddLineToPoint(RotatePoint(mPoints[i], mPlacedR) + mPlacedPosition);		}

		mPath.CloseSubpath();

		wxBrush brush(mColor);
		gc->SetBrush(brush);
		gc->FillPath(mPath);
	}
}
/**
 * Test to see if we have been clicked on by the mouse
 * @param point Position to test
 * @return true if clicked on
 */
bool PolyDrawable::HitTest(wxPoint point)
{
	return mPath.Contains(point.x,point.y);
}
/**
 *
 * @param point
 */
void PolyDrawable::AddPoint(wxPoint point)
{
	mPoints.push_back(point);
}
