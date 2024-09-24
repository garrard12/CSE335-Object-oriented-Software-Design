/**
 * @file PadVisitor.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "PadVisitor.h"
#include "TileStarshipPad.h"
/**
 * Constructor for PadVisitor
 * @param tile The tile that is requesting the Pad
 */
PadVisitor::PadVisitor(std::shared_ptr<Tile> tile) : mRequestPad(tile) //this assgined mReeqst
{
};

/**
 * Sees if the pad that was double clicked on has the Rocket
 *
 * @param tileStarShipPad The tile that was double clicked on
 */
void PadVisitor::VisitStatShip(TileStarshipPad* tileStarShipPad)
{
	// The pad that was request by
	if(tileStarShipPad == mRequestPad.get())
	{
		mLandingPad = tileStarShipPad;
	}
	// This Gets the Starship from the pad
	if(tileStarShipPad->GetStarShip() != nullptr)
	{
		mStartingPad = tileStarShipPad;
		mStarRocketWithPad = tileStarShipPad->GetStarShip();
	}
}
/**
 * Launches the Rocket
 */
void PadVisitor::LuanchingStarShip()
{
	// Checks to make sure that these are not true
	if(mLandingPad == nullptr ||  mStartingPad == nullptr || mStarRocketWithPad->InFlight())
	{
		return;
	}
	//Launches the Rocket
	mLandingPad->SetStarShip(mStarRocketWithPad);
	mStarRocketWithPad->SetLandingPad(mLandingPad);
}




