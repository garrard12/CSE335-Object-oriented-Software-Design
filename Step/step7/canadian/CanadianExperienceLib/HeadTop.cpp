/**
 * @file HeadTop.cpp
 * @author Auden Garrard
 */
#include "pch.h"
#include "HeadTop.h"
#include "Timeline.h"

/// The off Set to move the eye apart
const int EyeOffSet = 20;

/// How much the eye need to be raised
const int EyebrowOffSetY = 15;

/// Left eyebrow off set
const int LeftEyeOffSet = 27;

/// Right eyebrow off set
const int RightEyeOffset = 12;

/**
 * Constructor
 * @param name The name of the image
 * @param filename The name of the file
 */
HeadTop::HeadTop(const std::wstring &name, const std::wstring &filename) : ImageDrawable(name, filename)
{
	mImage = std::make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
}
/**
 * Draws the Face of the Actor
 * @param graphics The image that want to be drawn
 */
void HeadTop::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
	ImageDrawable::Draw(graphics);

	wxPen eye(*wxBLACK, 2);
	wxBrush eyeInside(*wxBLACK);
	graphics->SetPen(eye);
	graphics->SetBrush(eyeInside);

	// Draw the eys
	wxPoint p1 (mEye.x - EyeOffSet,mEye.y);
	wxPoint p2 (mEye.x + EyeOffSet ,mEye.y);


	wxPoint eye1 = TransformPoint(p1);
	wxPoint eye2 = TransformPoint(p2);
	DrawEye(eye1,graphics);
	DrawEye(eye2,graphics);

	wxPen eyebrowPen(*wxBLACK, 2);
	graphics->SetPen(eyebrowPen);

	// Draw the eyebrows

	wxPoint p3(mEye.x - LeftEyeOffSet, mEye.y - EyebrowOffSetY);
	wxPoint p4(mEye.x + RightEyeOffset, mEye.y - EyebrowOffSetY);

	wxPoint lbrow = TransformPoint(p3);
	wxPoint rbrow = TransformPoint(p4);

	DrawEyebrow(lbrow,graphics);
	DrawEyebrow(rbrow,graphics);
}


/** Transform a point from a location on the bitmap to
*  a location on the screen.
* @param  p Point to transform
* @returns Transformed point
*/
wxPoint HeadTop::TransformPoint(wxPoint p)
{
	// Make p relative to the image center
	p = p - GetCenter();

	// Rotate as needed and offset
	return RotatePoint(p, mPlacedR) + mPlacedPosition;
}
/**
 * Draws the eyes on the Head
 * @param eye Where you want the eyes to go
 * @param graphics The graphic that we want to draw on
 */
void HeadTop::DrawEye(wxPoint eye,std::shared_ptr<wxGraphicsContext> graphics)
{
	float wid = 15.0f;
	float hit = 20.0f;

	graphics->PushState();
	graphics->Translate(eye.x, eye.y);
	graphics->Rotate(-mPlacedR);
	graphics->DrawEllipse(-wid/2, -hit/2, wid, hit);
	graphics->PopState();
}
/**
 * Draw the eyebrows on the to the head
 * @param brow Where we want to eye brow to been drawn
 * @param graphics The graphic that we want to draw on
 */
void HeadTop::DrawEyebrow(wxPoint brow,std::shared_ptr<wxGraphicsContext> graphics)
{
	graphics->StrokeLine(brow.x, brow.y, brow.x + 15, brow.y );
}
/**
 * Add the channel to the timeline
 * @param timeline The timeline that is set
 */
void HeadTop::SetTimeline(Timeline* timeline)
{
	Drawable::SetTimeline(timeline);
	timeline->AddChannel(&mChannel);
}
/**
 * Set the Keyframe
 */
void HeadTop::SetKeyframe()
{
	Drawable::SetKeyframe();
	mChannel.SetKeyframe(GetPosition());
}
/**
 * Get the keyframe
 */
void HeadTop::GetKeyframe()
{
	Drawable::GetKeyframe();
	if (mChannel.IsValid()){
		SetPosition(mChannel.GetPosition());
	}
}

