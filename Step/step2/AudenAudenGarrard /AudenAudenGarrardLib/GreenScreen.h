/**
 * @file GreenScreen.h
 * @author Auden Garrard
 *
 * Declaration of the GreenScreen class
 */

#ifndef AUDENAUDENGARRARD_AUDENAUDENGARRARDLIB_GREENSCREEN_H
#define AUDENAUDENGARRARD_AUDENAUDENGARRARDLIB_GREENSCREEN_H


/**
 * Displays the green screen on to the window
 */
class GreenScreen : public wxWindow
{
private:

public:
	void Initialize(wxFrame* parent);
};

#endif //AUDENAUDENGARRARD_AUDENAUDENGARRARDLIB_GREENSCREEN_H
