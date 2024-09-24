/**
 * @file TileStarshipPad.h
 *
 * @author Charles B. Owen
 *
 * Class that implements a Starship pad.
 */

#pragma once

#include "Tile.h"
#include "Starship.h"

/**
 * Class that implements a Starship pad.
 * 
 * This is where Starships take off and land.
*/
class TileStarshipPad : public Tile
{
private:
	/// Pointer to the Starship
	std::shared_ptr<Starship>  mStarship;

public:
    explicit TileStarshipPad(City* city);

    ///  Default constructor (disabled)
    TileStarshipPad() = delete;

    ///  Copy constructor (disabled)
    TileStarshipPad(const TileStarshipPad&) = delete;

    wxXmlNode* XmlSave(wxXmlNode* node) override;

    void Report(std::shared_ptr<MemberReport> report) override;

    bool PendingDelete() override;

    void StarshipIsGone();
    void StarshipHasLanded();

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(TileVisitor* visitor) override { visitor->VisitStatShip(this); }

	void Draw(wxDC* dc) override;

	void Update(double elapsed) override;

	/**
	 * Getter for StarShip
	 * @return The starship
	 */
	std::shared_ptr<Starship> GetStarShip() const {return mStarship;}
	/**
	 * Set for StarShip
	 * @param ship what the new StarShip should be
	 */
	void SetStarShip(std::shared_ptr<Starship> ship){ mStarship = ship;}
};

