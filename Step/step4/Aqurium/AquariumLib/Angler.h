/**
 * @file Angler.h
 * @author Auden Garrard
 *
 * Class for a fish of type Angler
 */

#ifndef AQUARIUM_AQUARIUMLIB_ANGLER_H
#define AQUARIUM_AQUARIUMLIB_ANGLER_H

#include "Fish.h"


/**
 * Class for a fish of type Angler
 */
class Angler : public Fish
{
public:
	/// Default constructor (disabled)
	Angler() = delete;
	
	/// Copy constructor (disabled)
	Angler(const Angler &) = delete;
	
	/// Assignment operator
	void operator=(const Angler &) = delete;
	
	Angler(Aquarium* aquarium);

	wxXmlNode* XmlSave(wxXmlNode* node) override;


	void makeFishDifferent() override;

};

#endif //AQUARIUM_AQUARIUMLIB_ANGLER_H
