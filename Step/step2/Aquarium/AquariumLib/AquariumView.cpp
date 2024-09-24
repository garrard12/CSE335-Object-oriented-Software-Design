/**
 * @file AquariumView.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "AquariumView.h"
#include <wx/dcbuffer.h>

/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void AquariumView::Initialize(wxFrame* parent)
{
	Create(parent, wxID_ANY);
	SetBackgroundColour(*wxWHITE);
	Bind(wxEVT_PAINT, &AquariumView::OnPaint, this);
	SetBackgroundStyle(wxBG_STYLE_PAINT);

}

/**
 * Paint event, draws the window
 * @param event Paint event object
*/
void AquariumView::OnPaint(wxPaintEvent& event)
{
	wxAutoBufferedPaintDC dc(this);

	wxBrush background(*wxWHITE);
	dc.SetBackground(background);
	dc.Clear();

	mAquarium.OnDraw(&dc);
}