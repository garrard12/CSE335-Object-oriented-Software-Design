/**
 * @file ViewTimeline.cpp
 * @author Charles B. Owen
 */

#include "pch.h"

#include <wx/dcbuffer.h>
#include <wx/xrc/xmlres.h>

#include "ViewTimeline.h"




/**
 * Constructor
 * @param parent The main wxFrame object
 */
ViewTimeline::ViewTimeline(wxFrame* parent) :
    wxWindow(parent,        // Parent class
            wxID_ANY,   // Id (don't Car)
            wxDefaultPosition,  //Use the default position
            wxSize(100, Height), // Set the height to 90 pixels
            wxBORDER_SIMPLE)			// Draw  a border around the view
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &ViewTimeline::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &ViewTimeline::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &ViewTimeline::OnLeftUp, this);
    Bind(wxEVT_MOTION, &ViewTimeline::OnMouseMove, this);
}


/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void ViewTimeline::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));

	wxPen pen(wxColour(0, 128, 0), 1);
	graphics->SetPen(pen);
	graphics->DrawRectangle(10, 10, 200, 60);

	wxFont font(wxSize(0, 16),
				wxFONTFAMILY_SWISS,
				wxFONTSTYLE_NORMAL,
				wxFONTWEIGHT_NORMAL);
	graphics->SetFont(font, *wxBLACK);
	graphics->DrawText(L"Timeline!", 15, 15);

	auto time = wxDateTime::Now();
	auto timeStr = time.Format(L"%x %T");
	graphics->DrawText(timeStr, 15, 40);
}

/**
 * Handle the left mouse button down event
 * @param event
 */
void ViewTimeline::OnLeftDown(wxMouseEvent &event)
{

}

/**
* Handle the left mouse button up event
* @param event
*/
void ViewTimeline::OnLeftUp(wxMouseEvent &event)
{
    OnMouseMove(event);
}

/**
* Handle the mouse move event
* @param event
*/
void ViewTimeline::OnMouseMove(wxMouseEvent &event)
{

}
/**
 * Force an update of this window when the picture changes.
 */
void ViewTimeline::UpdateObserver()
{
	Refresh();
}

