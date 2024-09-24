/**
 * @file RocketCounter.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "RocketCounter.h"
#include "TileStarshipPad.h"

/**
 * Visit a StarshipPad object
 * @param StarshipPad StarshipPad we are visiting
 */
void RocketCounter::VisitStatShip(TileStarshipPad* tilePad)
{
	if (tilePad != nullptr)
	{
		mNumRocketPad++;
	}
}

