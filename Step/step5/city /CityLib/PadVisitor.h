/**
 * @file PadVisitor.h
 * @author Auden Garrard
 *
 * Visitor to launch the Rocket
 *
 */

#ifndef CITY_CITYLIB_PADVISITOR_H
#define CITY_CITYLIB_PADVISITOR_H

#include "TileVisitor.h"
#include "Starship.h"

class Tile;

/**
 * Initiates the PadVisitor to find the Rocket
 */
class PadVisitor : public TileVisitor
{
private:

	/// If The pad has the rocket it get assigned here
	std::shared_ptr<Starship> mStarRocketWithPad;

	/// The title that is Requesting the rocket
	std::shared_ptr<Tile> mRequestPad;

	/// Where the rocket is starting
	TileStarshipPad * mStartingPad = nullptr;

	/// Where the rocket is going
	TileStarshipPad * mLandingPad = nullptr;

public:

	PadVisitor(std::shared_ptr<Tile> tile);

	virtual void VisitStatShip(TileStarshipPad* tileStarShipPad) override;

	void LuanchingStarShip();
};

#endif //CITY_CITYLIB_PADVISITOR_H
