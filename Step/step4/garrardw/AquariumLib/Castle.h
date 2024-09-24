/**
 * @file Castle.h
 * @author Auden Garrard
 *
 * Class for the castle
 */

#ifndef AQUARIUM_AQUARIUMLIB_CASTLE_H
#define AQUARIUM_AQUARIUMLIB_CASTLE_H

#include "Item.h"

/**
 * Class for the castle
 */
class Castle : public Item
{
private:

public:
	/// Default constructor (disabled)
	Castle() = delete;

	/// Copy constructor (disabled)
	Castle(const Castle &) = delete;

	/// Assignment operator
	void operator=(const Castle &) = delete;

	Castle(Aquarium* aquarium);

	wxXmlNode* XmlSave(wxXmlNode* node) override;
};

#endif //AQUARIUM_AQUARIUMLIB_CASTLE_H
