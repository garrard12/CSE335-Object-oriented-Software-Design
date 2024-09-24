/**
 * @file HeadTop.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HEADTOP_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HEADTOP_H

#include "ImageDrawable.h"
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

public:
	HeadTop(const std::wstring &name, const std::wstring &filename);

	/**
	 * Is the item drawable
	 * @return True for this item to be drawn
	 */
	bool IsMovable() override { return true; };

	void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	/**
	 * Set the center of head
	 * @param eye The location of the ceter
	 */
	void SetEye(wxPoint eye) { mEye = eye;}
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HEADTOP_H
