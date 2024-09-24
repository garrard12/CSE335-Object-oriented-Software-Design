/**
 * @file Aquarium.h
 * @author Auden Garrard
 *
 * Declaration of the Aquarium class
 */

#ifndef AQUARIUM_AQUARIUMLIB_AQUARIUM_H
#define AQUARIUM_AQUARIUMLIB_AQUARIUM_H

//give acesse to unique pointers
#include <memory>

/**
 * Objects of this class is to set up the background of Aquarium.
 */
class Aquarium
{
private:
	/// Background image to use
	std::unique_ptr<wxBitmap> mBackground;
public:
	void OnDraw(wxDC *dc);
	Aquarium();

};

#endif //AQUARIUM_AQUARIUMLIB_AQUARIUM_H
