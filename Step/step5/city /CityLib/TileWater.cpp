/**
 * @file TileWater.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "TileWater.h"

/// Garden base image
const std::wstring WaterImage = L"water.png";

/**
 * Constructor
 * @param city City this water object inhabits.
 */
TileWater::TileWater(City* city)
        :Tile(city)
{
    SetImage(WaterImage);
}



/**
 * Save this item to an XML node
 * @param node The node we are going to be a child of
 * @return Allocated node
 */
wxXmlNode* TileWater::XmlSave(wxXmlNode* node)
{
    auto itemNode = Tile::XmlSave(node);

    itemNode->AddAttribute(L"type", L"water");

    return itemNode;
}
