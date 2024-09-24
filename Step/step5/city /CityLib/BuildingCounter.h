/**
 * @file BuildingCounter.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CITY_CITYLIB_BUILDINGCOUNTER_H
#define CITY_CITYLIB_BUILDINGCOUNTER_H

#include "TileVisitor.h"

/**A vistor to see how many building there are*/
class BuildingCounter : public TileVisitor
{
private:
	/// Buildings counter
	int mNumBuildings = 0;

public:
	/**
	 * Get the number of buildings
	 * @return Number of buildings
	 */
	int GetNumBuildings() const { return mNumBuildings; }

	/**
     * Visit a TileBuilding object
     * @param building Building we are visiting
     */
	void VisitBuilding(TileBuilding* building)
	{
		mNumBuildings++;
	}
};

#endif //CITY_CITYLIB_BUILDINGCOUNTER_H
