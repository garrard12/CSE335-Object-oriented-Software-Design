/**
 * @file TileWater.h
 * @author Charles Owen
 *
 * A Water tile
 */

#ifndef CITY_TILEWATER_H
#define CITY_TILEWATER_H

#include "Tile.h"

/**
 * A water tile
 */
class TileWater: public Tile {
public:
    TileWater(City* city);

    /// Default constructor (disabled)
    TileWater() = delete;

    /// Copy constructor (disabled)
    TileWater(const TileWater &) = delete;

    /// Assignment operator
    void operator=(const TileWater &) = delete;

    virtual wxXmlNode* XmlSave(wxXmlNode* node) override;

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(TileVisitor* visitor) override { visitor->VisitWater(this); }
};

#endif //CITY_TILEWATER_H
