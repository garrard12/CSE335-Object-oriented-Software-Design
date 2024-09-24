/**
 * @file DeletePadVisitor.h
 * @author Auden Garrard
 *
 * Header for Deleting a Starship
 */

#ifndef CITY_CITYLIB_DELETEPADVISITOR_H
#define CITY_CITYLIB_DELETEPADVISITOR_H

#include "TileVisitor.h"
#include "Starship.h"
#include "TileStarshipPad.h"
class Tile;

/**
 * A visitor for when we are deleting the pad
 */
class DeletePadVisitor : public TileVisitor
{
private:

	/// The new StarShipLocation
	std::shared_ptr<Starship> mStarShipLocation;

	/// Where the star ship is at
	TileStarshipPad * mTile = nullptr;

	/// The tile that the starship is going
	TileStarshipPad * mNewLocation = nullptr ;
public:

	DeletePadVisitor(TileStarshipPad * starShipTile);

	virtual void VisitStatShip(TileStarshipPad* tileStarShipPad) override;

};

#endif //CITY_CITYLIB_DELETEPADVISITOR_H
