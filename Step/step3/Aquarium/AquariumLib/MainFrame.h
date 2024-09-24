/**
 * @file MainFrame.h
 * @author Auden Garrard
 *
 * The top-level (main) frame of the application
 */

#ifndef AQUARIUM_AQUARIUMLIB_MAINFRAME_H
#define AQUARIUM_AQUARIUMLIB_MAINFRAME_H

class AquariumView;

/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame
{
private:
	/// A Pointer to AquariumView
	AquariumView *mAquariumView;

	void OnExit(wxCommandEvent& event);

	void OnAbout(wxCommandEvent& event);
public:
	void Initialize();

};

#endif //AQUARIUM_AQUARIUMLIB_MAINFRAME_H
