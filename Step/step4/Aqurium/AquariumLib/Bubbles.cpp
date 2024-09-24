/**
 * @file Bubbles.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "Aquarium.h"
#include "Bubbles.h"

using namespace std;

/// Fish Filename
const wstring FishImageName = L"images/bubbles.png";

/**
 * Constructor
 * @param aquarium  Aquarium this fish is a member of
 */
 //find out why we do the Item thing at the end
 Bubbles::Bubbles(Aquarium *aquarium) : Fish(aquarium,FishImageName)
 {
 }

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* Bubbles::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);
	itemNode->AddAttribute(L"XSpeed",wxString::FromDouble(GetXSpeed()));
	itemNode->AddAttribute(L"YSpeed",wxString::FromDouble(GetYSpeed()));
	itemNode->AddAttribute(L"type", L"bubble");
	return itemNode;
}

/**
 * The fish gets faster and faster in the X direstion while moving left
 */
void Bubbles::makeFishDifferent()
{
	if (GetXSpeed() < 0){
		SetXSpeed(GetXSpeed() * 1.05);
	}

}