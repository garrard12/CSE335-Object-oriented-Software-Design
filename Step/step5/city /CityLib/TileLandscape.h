/**
* @file TileLandscape.h
*
* @author Charles B. Owen
*
*  Class that implements a Landscape tile
*/

#pragma once

#include "Tile.h"


/**
*  A Landscape tile
*/
class TileLandscape : public Tile
{
private:

public:
    TileLandscape(City *city);

    ///  Default constructor (disabled)
    TileLandscape() = delete;

    ///  Copy constructor (disabled)
    TileLandscape(const TileLandscape &) = delete;

    wxXmlNode* XmlSave(wxXmlNode* node) override;
    void XmlLoad(wxXmlNode* node) override;

    virtual void Report(std::shared_ptr<MemberReport> report) override;

    void Draw(wxDC* dc) override;

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(TileVisitor* visitor) override { visitor->VisitLandscape(this); }
};

