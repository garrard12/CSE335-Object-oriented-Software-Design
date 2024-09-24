/**
 * @file Aquarium.h
 * @author Auden Garrard
 *
 * The main aquarium class.
 */

#ifndef AQUARIUM_AQUARIUMLIB_AQUARIUM_H
#define AQUARIUM_AQUARIUMLIB_AQUARIUM_H

//give accese to unique pointers
#include <memory>
class Item;

/**
 * The main aquarium class.
 */
class Aquarium
{
private:
	/// Background image to use
	std::unique_ptr<wxBitmap> mBackground;

	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<Item>> mItems;

public:
	void OnDraw(wxDC *dc);

	Aquarium();

	void Add(std::shared_ptr<Item> item);

	void UpdateList(std::shared_ptr<Item> item);

	std::shared_ptr<Item> HitTest(int x, int y);

	void DoubleClickTest(std::shared_ptr<Item> item);

};

#endif //AQUARIUM_AQUARIUMLIB_AQUARIUM_H
