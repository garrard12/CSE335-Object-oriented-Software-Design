/**
 * @file Gus.h
 * @author Auden Garrard
 *
 * Class for a fish of type Gus
 */

#ifndef AQUARIUM_AQUARIUMLIB_GUS_H
#define AQUARIUM_AQUARIUMLIB_GUS_H

#include "Item.h"

/**
 * Class for a fish of type Gus
 */
class Gus : public Item
{
private:
	/// The underlying Angler fish image
	std::unique_ptr<wxImage> mGusImage;

	/// The bitmap we can display for Angler fish
	std::unique_ptr<wxBitmap> mGusBitMap;

	/// If Gus is showing then true else false
	bool mGus = true;

	void SingleClickTest();

public:
	/// Default constructor (disabled)
	Gus() = delete;

	/// Copy constructor (disabled)
	Gus(const Gus &) = delete;

	/// Assignment operator
	void operator=(const Gus &) = delete;

	Gus(Aquarium* aquarium);

	void Draw(wxDC *dc) override;

	bool HitTest(int x, int y) override;

	void DoubleClickTest(std::shared_ptr<Item> item) override;
};

#endif //AQUARIUM_AQUARIUMLIB_GUS_H
