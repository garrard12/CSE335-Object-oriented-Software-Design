/**
 * @file FishBeta.h
 * @author Auden Garrard
 *
 * Class for a fish of type Beta
 */

#ifndef AQUARIUM_AQUARIUMLIB_FISHBETA_H
#define AQUARIUM_AQUARIUMLIB_FISHBETA_H

#include "Item.h"

/**
 * Class for a fish of type Beta
 */
class FishBeta : public  Item
{
private:
	/// The underlying fish Image
	std::unique_ptr<wxImage> mFishImage;

	/// The bitmap we can display for this fish
	std::unique_ptr<wxBitmap> mFishBitmap;

public:
	/// Default constructor (disabled)
	FishBeta() = delete;

	/// Copy constructor (disabled)
	FishBeta(const FishBeta &) = delete;

	/// Assignment operator
	void operator=(const FishBeta &) = delete;

	FishBeta(Aquarium* aquarium);

	void Draw(wxDC *dc) override;

	bool HitTest(int x, int y) override;
};

#endif //AQUARIUM_AQUARIUMLIB_FISHBETA_H
