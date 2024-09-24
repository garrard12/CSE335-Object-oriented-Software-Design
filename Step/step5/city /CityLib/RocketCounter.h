/**
 * @file RocketCounter.h
 * @author Auden Garrard
 *
 * The visitor for RocketPad
 */

#ifndef CITY_CITYLIB_ROCKETCOUNTER_H
#define CITY_CITYLIB_ROCKETCOUNTER_H

#include "TileVisitor.h"
#include "TileStarshipPad.h"

/** This is the visitor to see if the Rocket is there*/
class RocketCounter : public TileVisitor
{
private:
	/// The number of rockets there are on in the city
	int mNumRocketPad = 0;

public:
	/**
	 * Get the number of Rocket Pad
	 * @return mNumRocketPad Number of Rocket pads
	 */
	int GetNumRockets() const {return mNumRocketPad;}

	void VisitStatShip(TileStarshipPad* tilePad );
};

#endif //CITY_CITYLIB_ROCKETCOUNTER_H
