/**
 * @file HeadTop.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HEADTOP_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HEADTOP_H

#include "ImageDrawable.h"
#include "AnimChannelPosition.h"
/**
 * Draw the head of image
 */
class HeadTop : public ImageDrawable
{
private:
	/// Where the center of the head is
	wxPoint mEye = wxPoint(0,0);

	wxPoint TransformPoint(wxPoint p);

	void DrawEye(wxPoint eye,std::shared_ptr<wxGraphicsContext> graphics);

	void DrawEyebrow(wxPoint brow,std::shared_ptr<wxGraphicsContext> graphics);

	/// To animate the position of the channel
	AnimChannelPosition mChannel;

public:
	HeadTop(const std::wstring &name, const std::wstring &filename);

	/**
	 * Is the item drawable
	 * @return True for this item to be drawn
	 */
	bool IsMovable() override { return true;};

	void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	/**
	 * Set the center of head
	 * @param eye The location of the ceter
	 */
	void SetEye(wxPoint eye) { mEye = eye;}

	void SetTimeline(Timeline *timeline) override;

	void SetKeyframe() override;

	void GetKeyframe() override;

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HEADTOP_H
