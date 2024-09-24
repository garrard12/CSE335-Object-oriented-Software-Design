/**
 * @file AquariumView.h
 * @author Auden Garrard
 *
 * Declaration of the AquariumView class
 */

#ifndef AQUARIUM_AQUARIUMLIB_AQUARIUMVIEW_H
#define AQUARIUM_AQUARIUMLIB_AQUARIUMVIEW_H

#include "Aquarium.h"

/**
 * Class that displays the Aquarium onto the window
 */
class AquariumView : public wxWindow
{
private:
	/// An object that describes out aquarium
	Aquarium mAquarium;

	void OnPaint(wxPaintEvent& event);
public:
	void Initialize(wxFrame* parent);

};

#endif //AQUARIUM_AQUARIUMLIB_AQUARIUMVIEW_H
