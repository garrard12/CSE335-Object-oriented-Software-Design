/**
 * @file Angler.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "Angler.h"
#include "Aquarium.h"

using namespace std;

/// Fish filename
const wstring FishImageName = L"images/angler.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
 Angler::Angler(Aquarium *aquarium) : Fish(aquarium,FishImageName)
 {
 }
/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* Angler::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);

	itemNode->AddAttribute(L"XSpeed",wxString::FromDouble(GetXSpeed()));
	itemNode->AddAttribute(L"YSpeed",wxString::FromDouble(GetYSpeed()));

	itemNode->AddAttribute(L"type", L"angler");
	return itemNode;
}
/**
 * Slows the fish down in the X and Y direction
 */
void Angler::makeFishDifferent()
{
	if (GetXSpeed() < 14){
		SetXSpeed(GetXSpeed() * .3);
	}
	if(GetYSpeed() > 2){
		SetYSpeed(GetY() * .5);
	}

}