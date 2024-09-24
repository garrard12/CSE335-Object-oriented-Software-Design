/**
 * @file FishBeta.h
 * @author Auden Garrard
 *
 * Class for a fish of type Beta
 */

#ifndef AQUARIUM_AQUARIUMLIB_FISHBETA_H
#define AQUARIUM_AQUARIUMLIB_FISHBETA_H

#include "Fish.h"

/**
 * Class for a fish of type Beta
 */
class FishBeta : public  Fish
{
public:
	/// Default constructor (disabled)
	FishBeta() = delete;

	/// Copy constructor (disabled)
	FishBeta(const FishBeta &) = delete;

	/// Assignment operator
	void operator=(const FishBeta &) = delete;

	FishBeta(Aquarium* aquarium);

	wxXmlNode* XmlSave(wxXmlNode* node) override;

	void makeFishDifferent() override;
};

#endif //AQUARIUM_AQUARIUMLIB_FISHBETA_H
