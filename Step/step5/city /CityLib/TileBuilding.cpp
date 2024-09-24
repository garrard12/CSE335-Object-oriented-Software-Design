/**
 * @file TileBuilding.cpp
 * @author Charles B. Owen
 */

#include "pch.h"
#include <sstream>
#include <iostream>
#include "TileBuilding.h"
#include "City.h"
#include "MemberReport.h"


/**
 * Constructor
 * @param city The city this is a member of
*/
TileBuilding::TileBuilding(City *city) : Tile(city)
{
}

/**
 *  Set the image file to draw
 * @param file The base filename. Blank files are allowed
 */
void TileBuilding::SetImage(const std::wstring& file)
{
    // This save the image supplied to SetImage to
    // a member variable so we can restore save it to XML
    if(!file.empty() && mBuildingImageFile.empty())
    {
        mBuildingImageFile = file;
    }

    Tile::SetImage(file);
}


/**  Save this item to an XML node
* @param node The node we are going to be a child of
* @return Allocated node
*/
wxXmlNode* TileBuilding::XmlSave(wxXmlNode* node)
{
    auto itemNode = Tile::XmlSave(node);

    itemNode->AddAttribute(L"type", L"building");
    itemNode->AddAttribute(L"file", mBuildingImageFile);

    return itemNode;
}


/**
* brief Load the attributes for an item node.
* @param node The Xml node we are loading the item from
*/
void TileBuilding::XmlLoad(wxXmlNode* node)
{
    Tile::XmlLoad(node);
    SetImage(node->GetAttribute(L"file").ToStdWstring());
}



/**
 * Generate a report for this  tile.
 * @param report
*/
void TileBuilding::Report(std::shared_ptr<MemberReport> report)
{
    std::wstringstream str;
    str << L"Building - " << GetFile();

    report->SetReport(str.str());
}
