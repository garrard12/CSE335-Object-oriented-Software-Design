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

	/// Any item we are currently dragging
	std::shared_ptr<Item> mGrabbedItem;

	/// Any item we double click on
	std::shared_ptr<Item> mDoubleClickedItem;

	/// The timer that allows for animation
	wxTimer mTimer;

	/// Stopwatch used to measure elapsed time
	wxStopWatch mStopWatch;

	/// The last stopwatch time
	long mTime = 0;

	void OnPaint(wxPaintEvent& event);

	void OnAddFishBetaFish(wxCommandEvent & event);

	void OnAddFishAnglerFish(wxCommandEvent & event);

	void OnAddFishBubblesFish(wxCommandEvent &event);

	void OnAddCastle(wxCommandEvent &event);

	void OnFileSaveAs(wxCommandEvent &event);

	void OnFileOpen(wxCommandEvent& event);

	void OnTimer(wxTimerEvent &event);

public:
	void Initialize(wxFrame* parent);

	void OnMouseMove(wxMouseEvent &event);

	void OnLeftUp(wxMouseEvent &event);

	void OnLeftDown(wxMouseEvent &event);

	void OnDoubleClick(wxMouseEvent &event);


};

#endif //AQUARIUM_AQUARIUMLIB_AQUARIUMVIEW_H
