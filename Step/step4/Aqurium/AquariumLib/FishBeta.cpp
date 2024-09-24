/**
 * @file FishBeta.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "FishBeta.h"
#include "Aquarium.h"

using namespace std;


/// Fish filename
const wstring FishBetaImageName = L"images/beta.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishBeta::FishBeta(Aquarium *aquarium) : Fish(aquarium, FishBetaImageName)
{
}
/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* FishBeta::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);
	itemNode->AddAttribute(L"XSpeed",wxString::FromDouble(GetXSpeed()));
	itemNode->AddAttribute(L"YSpeed",wxString::FromDouble(GetYSpeed()));
	itemNode->AddAttribute(L"type", L"beta");
	return itemNode;
}
/**
 * Seeds up the beta fish until it is going faster then 75
 */
void FishBeta::makeFishDifferent()
{
	if(abs(GetYSpeed()) < 75)
	{
		SetYSpeed(GetYSpeed() * 1.2);
	}
}




