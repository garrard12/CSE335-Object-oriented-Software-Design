/**
 * @file WhiteScreen.h
 * @author Auden Garrard
 *
 * Declaration of the WhiteScreen class
 */

#ifndef AUDENAUDENGARRARD_AUDENAUDENGARRARDLIB_WHITESCREEN_H
#define AUDENAUDENGARRARD_AUDENAUDENGARRARDLIB_WHITESCREEN_H
/**
 * Displays the green screen on to the window including the drawing
 */
class WhiteScreen : public wxWindow
{
private:
	void OnPaint (wxPaintEvent& event);
public:
	void Initialize(wxFrame* parent);
};

#endif //AUDENAUDENGARRARD_AUDENAUDENGARRARDLIB_WHITESCREEN_H
