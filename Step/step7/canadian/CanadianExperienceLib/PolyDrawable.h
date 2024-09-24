/**
 * @file PolyDrawable.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_POLYDRAWABLE_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_POLYDRAWABLE_H

#include "Drawable.h"
/**
 * A drawable based on polygon images.
 *
 * This class has a list of points and draws a polygon
 * drawable based on those points.
 */
class PolyDrawable : public Drawable
{
private:

	/// The image we are drawing
	std::unique_ptr<wxImage> mImage;
	/// The graphics bitmap we will use
	wxGraphicsBitmap mBitmap;

	/// The polygon color
	wxColour mColor = *wxBLACK;

	/// The array of point objects
	std::vector<wxPoint> mPoints;

	/// The transformed graphics path used
	/// to draw this polygon
	wxGraphicsPath mPath;
public:
	/// Default constructor (disabled)
	PolyDrawable() = delete;

	/// Copy constructor (disabled)
	PolyDrawable(const PolyDrawable &) = delete;

	/// Assignment operator
	void operator=(const PolyDrawable &) = delete;

	PolyDrawable(std::wstring const &name);

	PolyDrawable(std::wstring const &name, const std::wstring &filename);

	void Draw(std::shared_ptr<wxGraphicsContext> gc) override;

	bool HitTest(wxPoint point) override;

	void AddPoint(wxPoint point) ;

	/**
	 * Get the color
	 * @return the color
	 */
	wxColour GetColor(){return mColor;}

	/**
	 * Set the new color
	 * @param color The new color
	 */
	void SetColor(wxColour color){mColor = color;}



};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_POLYDRAWABLE_H
