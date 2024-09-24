/**
 * @file TileVisitor.h
 * @author Auden Garrard
 *
 * Tile visitor base class.
 */

#ifndef CITY__TILEVISITOR_H
#define CITY__TILEVISITOR_H

// Forward references to all tile types
class TileBuilding;
class TileLandscape;
class TileGarden;
class TileWater;
class TileStarshipPad;

/**
 * Tile visitor base class
 */
class TileVisitor
{
protected:
	/**
	 * Constructor
	 * Ensures this is an abstract class
	 */
	TileVisitor() {}

public:
	virtual ~TileVisitor() {}

	/**
	 * Visit a TileBuilding object
	 * @param building Building we are visiting
	 */
	virtual void VisitBuilding(TileBuilding* building) {}

	/**
	 * Visit a TileLandscape object
	 * @param landscape Landscape tile we are visiting
	 */
	virtual void VisitLandscape(TileLandscape* landscape) {}

	/**
	 * Visit a TileGarden object
	 * @param garden Garden we are visiting
	 */
	virtual void VisitGarden(TileGarden* garden) {}

	/**
	 * Visit a water file
	 * @param water Tile object we are visiting
	 */
	virtual void VisitWater(TileWater* water) {}

	/**
	 * Visit a StarShip object
	 * @param StarShip StarShip we are visiting
	 */
	virtual void VisitStatShip(TileStarshipPad* StarShip) {}



};

#endif //CITY__TILEVISITOR_H
