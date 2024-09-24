/**
 * @file ImageDrawable.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_IMAGEDRAWABLE_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_IMAGEDRAWABLE_H

#include "Drawable.h"

/**
 * Draws the image of the body
 */
class ImageDrawable : public Drawable
{
private:
	/// The center of the image
	wxPoint mCenter = wxPoint(0,0);
protected:
	/// The image we are drawing
	std::unique_ptr<wxImage> mImage;
	/// The graphics bitmap we will use
	wxGraphicsBitmap mBitmap;
public:

	ImageDrawable(const std::wstring &name, const std::wstring &filename);

	void Draw(std::shared_ptr<wxGraphicsContext> graphics);

	bool HitTest(wxPoint pos);

	/**
	 * Get the center of images
	 * @return The center of the image as wxPoint
	 */
	wxPoint GetCenter() const  {return  mCenter;}

	/**
	 * Sets the center of the image
	 * @param center The center of the image
	 */
	void SetCenter(wxPoint center){mCenter = center;}

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_IMAGEDRAWABLE_H
