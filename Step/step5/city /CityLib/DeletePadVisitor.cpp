/**
 * @file DeletePadVisitor.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "DeletePadVisitor.h"
#include "TileStarshipPad.h"


/**
 * Constructor
 * @param starShipTile The Tile that the Starship is starting on
 */
DeletePadVisitor::DeletePadVisitor(TileStarshipPad *starShipTile) : mTile(starShipTile)
{}

/**
 * Moves the starship from the deleted Tile to another one
 *
 * @param tileStarShipPad The tile that is being visited
 */
void DeletePadVisitor::VisitStatShip(TileStarshipPad * tileStarShipPad)
{
	// Grabs the starShip from this tile
	if(tileStarShipPad == mTile)
	{
		mStarShipLocation = tileStarShipPad->GetStarShip();
	}

	// Where the star ship is going
	if(tileStarShipPad != mTile)
	{
		mNewLocation = tileStarShipPad;
	}

	//Set the Starship up to move to it's next location
	if(mStarShipLocation != nullptr && mNewLocation != nullptr)
	{
		mNewLocation->SetStarShip(mStarShipLocation);
		mStarShipLocation->SetLaunchingPad(mNewLocation);
	}
}
