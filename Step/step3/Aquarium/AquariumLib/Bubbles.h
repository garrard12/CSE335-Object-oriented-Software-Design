/**
 * @file Bubbles.h
 * @author Auden Garrard
 *
 *  Class for a fish of type Bubbles
 */

#ifndef AQUARIUM_AQUARIUMLIB_BUBBLES_H
#define AQUARIUM_AQUARIUMLIB_BUBBLES_H

#include "Item.h"

/**
 * Class for a fish of type Bubbles
 */
class Bubbles : public Item
{
private:
	/// The underlying Bubbles Image
	std::unique_ptr<wxImage> mBubblesImage;

	/// The bitmap we can display for this fish
	std::unique_ptr<wxBitmap> mBubblesBitmap;

public:

	/// Default constructor (disabled)
	Bubbles() = delete;

	/// Copy constructor (disabled)
	Bubbles(const Bubbles &) = delete;

	/// Assignment operator
	void operator=(const Bubbles &) = delete;

	Bubbles(Aquarium *aquarium);

	void Draw(wxDC *dc) override;

	bool HitTest(int x, int y) override;

};

#endif //AQUARIUM_AQUARIUMLIB_BUBBLES_H
