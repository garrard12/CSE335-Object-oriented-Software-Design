/**
 * @file Bubbles.h
 * @author Auden Garrard
 *
 *  Class for a fish of type Bubbles
 */

#ifndef AQUARIUM_AQUARIUMLIB_BUBBLES_H
#define AQUARIUM_AQUARIUMLIB_BUBBLES_H

#include "Fish.h"

/**
 * Class for a fish of type Bubbles
 */
class Bubbles : public Fish
{

public:

	/// Default constructor (disabled)
	Bubbles() = delete;

	/// Copy constructor (disabled)
	Bubbles(const Bubbles &) = delete;

	/// Assignment operator
	void operator=(const Bubbles &) = delete;

	Bubbles(Aquarium *aquarium);

	wxXmlNode* XmlSave(wxXmlNode* node) override;

	void makeFishDifferent() override;
};


#endif //AQUARIUM_AQUARIUMLIB_BUBBLES_H
