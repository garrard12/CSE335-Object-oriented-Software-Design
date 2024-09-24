/**
 * @file Angler.h
 * @author Auden Garrard
 *
 * Class for a fish of type Angler
 */

#ifndef AQUARIUM_AQUARIUMLIB_ANGLER_H
#define AQUARIUM_AQUARIUMLIB_ANGLER_H

#include "Item.h"


/**
 * Class for a fish of type Angler
 */
class Angler : public Item
{
private:
	/// The underlying Angler fish image
	std::unique_ptr<wxImage> mAnglerImage;

	/// The bitmap we can display for Angler fish
	std::unique_ptr<wxBitmap> mAnglerBitMap;

public:
	/// Default constructor (disabled)
	Angler() = delete;
	
	/// Copy constructor (disabled)
	Angler(const Angler &) = delete;
	
	/// Assignment operator
	void operator=(const Angler &) = delete;
	
	Angler(Aquarium* aquarium);

	void Draw(wxDC *dc) override;

	bool HitTest(int x, int y) override;
};

#endif //AQUARIUM_AQUARIUMLIB_ANGLER_H
