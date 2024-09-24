/**
 * @file ViewTimeline.cpp
 * @author Charles B. Owen
 */

#include "pch.h"

#include <wx/dcbuffer.h>
#include <wx/xrc/xmlres.h>
#include <sstream>

#include "ViewTimeline.h"
#include "Picture.h"
#include "Timeline.h"
#include "TimelineDlg.h"
#include "AnimChannel.h"
#include "AnimChannelAngle.h"
#include "Actor.h"

using namespace std;

/// Y location for the top of a tick mark
const int TickTop = 15;

/// The spacing between ticks in the timeline
const int TickSpacing = 4;

/// The length of a short tick mark
const int TickShort = 10;

/// The length of a long tick mark
const int TickLong = 20;

/// Size of the tick mark labels
const int TickFontSize = 15;

/// Space to the left of the scale
const int BorderLeft = 10;

/// Space to the right of the scale
const int BorderRight = 10;

/// Filename for the pointer image
const std::wstring PointerImageFile = L"/pointer.png";

/**
 * Constructor
 * @param parent The main wxFrame object
 * @param imagesDir The path to the image
 */
ViewTimeline::ViewTimeline(wxFrame* parent, wstring imagesDir) :
	wxScrolledCanvas(parent,        // Parent class
            wxID_ANY,   // Id (don't Car)
            wxDefaultPosition,  //Use the default position
            wxSize(100, Height), // Set the height to 90 pixels
            wxBORDER_SIMPLE)			// Draw  a border around the view
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);

	mPointerImage = make_unique<wxImage>(imagesDir + PointerImageFile,wxBITMAP_TYPE_ANY);


	parent->Bind(wxEVT_COMMAND_MENU_SELECTED,
				 &ViewTimeline::OnEditTimelineProperties, this,
				 XRCID("EditTimelineProperties"));

    Bind(wxEVT_PAINT, &ViewTimeline::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &ViewTimeline::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &ViewTimeline::OnLeftUp, this);
    Bind(wxEVT_MOTION, &ViewTimeline::OnMouseMove, this);

	parent->Bind(wxEVT_COMMAND_MENU_SELECTED,&ViewTimeline::OnSetKeyframe,
				 this, XRCID("SetKeyframe"));
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &ViewTimeline::OnDeleteKeyframe,
				 this, XRCID("DeleteKeyframe"));
//	parent->Bind(wxEVT_UPDATE_UI,&ViewTimeline::OnSetKeyframe,this, XRCID("SetKeyframe"));
//	parent->Bind(wxEVT_UPDATE_UI,&ViewTimeline::OnDeleteKeyframe,
//				 this, XRCID("DeleteKeyframe"));
}


/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void ViewTimeline::OnPaint(wxPaintEvent& event)
{
	Timeline* timeline = GetPicture()->GetTimeline();
	auto size = GetPicture()->GetSize();
	SetVirtualSize( timeline->GetNumFrames() * TickSpacing + BorderLeft + BorderRight, 0);
	SetScrollRate(1, 0);

    wxAutoBufferedPaintDC dc(this);
	DoPrepareDC(dc);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));

	mPointerBitmap = graphics->CreateBitmapFromImage(*mPointerImage);

	// Set the color of the pen
	wxPen pen(*wxBLACK);
	graphics->SetPen(pen);

	wxFont numberFont(TickFontSize,
					  wxFONTFAMILY_SWISS,
					  wxFONTSTYLE_NORMAL,
					  wxFONTWEIGHT_BOLD);
	graphics->SetFont(numberFont,*wxBLACK);

	// Draw all the needed ticks
	for(int i = 0; i < timeline->GetNumFrames();i++)
	{
		int xLocation  = BorderLeft + TickSpacing * i;
		// Is this tick a land on a second
		bool onSecond = (i % timeline->GetFrameRate()) == 0;
		if(onSecond)
		{
			// the second that they are on
			std::wstringstream str;
			str << i / timeline->GetFrameRate();
			std::wstring wstr = str.str();
			double w,h;

			//Get the dimensions of the text being drawn
			graphics->GetTextExtent(wstr, &w, &h);
			graphics->StrokeLine(xLocation, TickTop + TickLong, xLocation,  TickTop);
			graphics->DrawText(wstr,xLocation - w / 2,TickTop+TickLong);
		}
		else
		{
			graphics->StrokeLine(xLocation, TickTop + TickShort, xLocation, TickTop);
		}
	}

	// Draw the pointer for the timeline
	double xLocaction = BorderLeft + timeline->GetCurrentTime() * TickSpacing * timeline->GetFrameRate();
	graphics->DrawBitmap(mPointerBitmap,
						 xLocaction - mPointerImage->GetWidth() / 2 , TickTop,
						 mPointerImage->GetWidth(),
						 mPointerImage->GetHeight());

}

/**
 * Handle the left mouse button down event
 * @param event
 */
void ViewTimeline::OnLeftDown(wxMouseEvent &event)
{
	auto click = CalcUnscrolledPosition(event.GetPosition());

	int x = click.x;

	// Get the timeline
	Timeline *timeline = GetPicture()->GetTimeline();

	int pointerX = (int)(timeline->GetCurrentTime() *
		timeline->GetFrameRate() * TickSpacing + BorderLeft);

	mMovingPointer = x >= pointerX - mPointerImage->GetWidth() / 2 &&
		x <= pointerX + mPointerImage->GetWidth() / 2;
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
	auto click = CalcUnscrolledPosition(event.GetPosition());

	// Are we moving the pointer
	if(mMovingPointer && event.LeftIsDown())
	{
		Timeline *timeline = GetPicture()->GetTimeline();

		// Calc the time that is wanted
		double time = double(click.x  - BorderLeft) / timeline->GetFrameRate() / TickSpacing;

		if(time < 0)
		{
			GetPicture()->SetAnimationTime(0);
		}else if(time > timeline->GetDuration())
		{
			GetPicture()->SetAnimationTime(timeline->GetDuration());
			//GetPicture()->SetAnimationTime(time);
		}
		else
		{
			GetPicture()->SetAnimationTime(time);
		}
	}
}
/**
 * Force an update of this window when the picture changes.
 */
void ViewTimeline::UpdateObserver()
{
	Refresh();
	Update();
}
/**
 * Handle an Edit>Timeline Properties... menu option
 * @param event The menu event
 */
void ViewTimeline::OnEditTimelineProperties(wxCommandEvent& event)
{

	TimelineDlg dlg(this->GetParent(),GetPicture()->GetTimeline());
	if(dlg.ShowModal() == wxID_OK)
	{
		// The dialog box has changed the Timeline settings
		UpdateObserver();
	}
}
/**
 * Delete a key frame
 * @param event The menu event
 */
void ViewTimeline::OnDeleteKeyframe(wxCommandEvent &event)
{
	auto picture = GetPicture();
	for(auto actor : *picture)
	{
		actor->DeleteKeyframe();
	}

}
/**
 * Set a Key frame
 * @param event The menu event
 */
void ViewTimeline::OnSetKeyframe(wxCommandEvent &event)
{
	auto picture = GetPicture();
	for (auto actor : *picture)
	{
		actor->SetKeyframe();
	}
}
