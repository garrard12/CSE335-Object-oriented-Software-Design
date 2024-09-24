/**
* @file TileBuilding.h
*
* @author Charles B. Owen
*
*  Class that implements a Building tile
*/

#pragma once

#include "Tile.h"


/**
*  A Building tile
*/
class TileBuilding : public Tile
{
private:
    /// The building image file
    std::wstring mBuildingImageFile;

public:
    TileBuilding(City *city);

    ///  Default constructor (disabled)
    TileBuilding() = delete;

    ///  Copy constructor (disabled)
    TileBuilding(const TileBuilding &) = delete;

    wxXmlNode* XmlSave(wxXmlNode* node) override;
    void XmlLoad(wxXmlNode* node) override;

    virtual void Report(std::shared_ptr<MemberReport> report) override;

    void SetImage(const std::wstring& file) override;

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(TileVisitor* visitor) override { visitor->VisitBuilding(this); }
};

