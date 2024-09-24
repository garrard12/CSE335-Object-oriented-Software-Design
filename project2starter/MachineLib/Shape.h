/**
 * @file Shape.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_SHAPE_H
#define CANADIANEXPERIENCE_MACHINELIB_SHAPE_H

#include "Component.h"
#include "Polygon.h"

/**The shape class **/
class Shape : public Component
{
private:
	/// The shape to be drawn
	cse335::Polygon mShape;

public:
	/// Copy constructor (disabled)
	Shape(const Shape &) = delete;

	/// Assignment operator
	void operator=(const Shape &) = delete;

	Shape(){};

	void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

	void UpdateTime(double time ) override;
	/**
	* Create a rectangle
	* @param x Left side X
	* @param y Bottom left Y
	* @param width Width of the rectangle. If not supplied, use an image width
	* @param height Height of the rectangle. If not supplied, use an image height
	*/
	void Rectangle(int x, int y, int width = 0, int height = 0) {mShape.Rectangle(x,y,width,height);};
	/**
     * Set the color of the Shape
     * @param color The want color/shape
    */
	void SetColor(wxColour color){mShape.SetColor(color);}
	/**
	* Set an image we will use as a texture for the polygon
	* @param filename Image filename
	*/
	void SetImage(std::wstring filename) { mShape.SetImage(filename);}

	/**
	 * Get the width of image
	 * @return the width of the image
	 */
	int GetImageWidth(){return mShape.GetImageWidth();}


};

#endif //CANADIANEXPERIENCE_MACHINELIB_SHAPE_H
