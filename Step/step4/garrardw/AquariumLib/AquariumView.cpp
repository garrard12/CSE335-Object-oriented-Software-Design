/**
 * @file AquariumView.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "AquariumView.h"
#include <wx/dcbuffer.h>
#include "ids.h"
#include "FishBeta.h"
#include "Angler.h"
#include "Bubbles.h"
#include "Castle.h"

using namespace std;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void AquariumView::Initialize(wxFrame* parent)
{
	Create(parent, wxID_ANY);
	SetBackgroundColour(*wxWHITE);
	SetBackgroundStyle(wxBG_STYLE_PAINT);

	//Binds to Add images to the Aquarium
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishBetaFish,
				 this, IDM_ADDFISHBETA);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishAnglerFish,
				 this, IDM_ADDFISHANGEL);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishBubblesFish,
				 this, IDM_ADDFISHBUBBLES);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED,&AquariumView::OnAddCastle,this,IDM_Castle);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED,&AquariumView::OnFileSaveAs,this,wxID_SAVEAS);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED,&AquariumView::OnFileOpen,this,wxID_OPEN);

	//Mouse events
	Bind(wxEVT_LEFT_DOWN, &AquariumView::OnLeftDown, this);
	Bind(wxEVT_LEFT_UP, &AquariumView::OnLeftUp, this);
	Bind(wxEVT_MOTION, &AquariumView::OnMouseMove, this);
	Bind(wxEVT_PAINT, &AquariumView::OnPaint, this);
	Bind(wxEVT_TIMER,&AquariumView::OnTimer,this);

	//The timers for the animation
	mTimer.SetOwner(this);
	mTimer.Start(FrameDuration);
	mStopWatch.Start();
}

/**
 * Paint event, draws the window
 * @param event Paint event object
*/
void AquariumView::OnPaint(wxPaintEvent& event)
{
	// Compute the time that has elapsed
	// since the last call to OnPaint.
	// Make sure this is the first thing that Goes in here
	// Keeps track of time even in debug mode
	auto newTime = mStopWatch.Time();
	auto elapsed = (double)(newTime - mTime) * 0.001;
	mTime = newTime;

	mAquarium.Update(elapsed);

	wxAutoBufferedPaintDC dc(this);

	wxBrush background(*wxWHITE);
	dc.SetBackground(background);
	dc.Clear();

	mAquarium.OnDraw(&dc);
}
/**
 * Menu handler for Add Fish Beta Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishBetaFish(wxCommandEvent& event)
{
	auto fish = std::make_shared<FishBeta>(&mAquarium);
	mAquarium.Add(fish);
	//This makes the image appear onto the screen
	Refresh();
}

/**
 * Menu handler for Add Fish Angler Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishAnglerFish(wxCommandEvent &event)
{
	auto fish = std::make_shared<Angler>(&mAquarium);
	mAquarium.Add(fish);
	//This makes the image appear onto the screen
	Refresh();
}

/**
 * Menu handler for Add Fish Bubbles
 * @param event Mouse event
 */
void AquariumView::OnAddFishBubblesFish(wxCommandEvent &event)
{
	auto fish = std::make_shared<Bubbles>(&mAquarium);
	mAquarium.Add(fish);
	//This makes the image appear onto the screen
	Refresh();
}
/**
 * Menu handler for Add Castle
 * @param event Mouse event
 */
void AquariumView::OnAddCastle(wxCommandEvent &event)
{
	auto castle = std::make_shared<Castle>(&mAquarium);
	mAquarium.Add(castle);
	Refresh();
}

/**
 * Menu handler for Add Castle
 * @param event Mouse event
 */
void AquariumView::OnFileSaveAs(wxCommandEvent &event)
{
	//The pop up window for saving a file
	wxFileDialog saveFileDialog(this, L"Save Aquarium file", L"", L"",
								L"Aquarium Files (*.aqua)|*.aqua", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	//If the user decides to cancel the save option
	if (saveFileDialog.ShowModal() == wxID_CANCEL)
	{
		return;
	}
	//grabs the path the file is being saved to
	auto filename = saveFileDialog.GetPath();
	mAquarium.Save(filename);
}


/**
 * File>Open menu handler
 * @param event Menu event
 */
void AquariumView::OnFileOpen(wxCommandEvent& event)
{
	wxFileDialog loadFileDialog(this, L"Load Aquarium file", L"", L"",
								L"Aquarium Files (*.aqua)|*.aqua", wxFD_OPEN);
	if (loadFileDialog.ShowModal() == wxID_CANCEL)
	{
		return;
	}

	auto filename = loadFileDialog.GetPath();
	mAquarium.Load(filename);
	Refresh();
}
/**
 * Handle the left mouse button down event
 * @param event Left mouse button pressed
 */
void AquariumView::OnLeftDown(wxMouseEvent &event)
{
	mGrabbedItem = mAquarium.HitTest(event.GetX(),event.GetY());
	if (mGrabbedItem != nullptr)
	{
		mAquarium.UpdateList(mGrabbedItem);
	}
	Refresh();
}
/**
* Handle the left mouse button down event
* @param event Left mouse button released
*/
void AquariumView::OnLeftUp(wxMouseEvent &event)
{
	OnMouseMove(event);
}

/**
 * Handle the Double click for Gus
 * @param event Double click on Gus
 */
void AquariumView::OnDoubleClick(wxMouseEvent &event)
{
	mDoubleClickedItem = mAquarium.HitTest(event.GetX(),event.GetY());
	if (mDoubleClickedItem != nullptr)
	{
		//Move Fish to the end of the list
		mAquarium.UpdateList(mDoubleClickedItem);
		//This is path is not needed but it gets me down to Gus
		mDoubleClickedItem->DoubleClickTest(mDoubleClickedItem);
	}
	Refresh();
}

/**
* Handle the left mouse button down event
* @param event Mouse movement
*/
void AquariumView::OnMouseMove(wxMouseEvent &event)
{
	// See if an item is currently being moved by the mouse
	if (mGrabbedItem != nullptr)
	{
		// If an item is being moved, we only continue to
		// move it while the left button is down.
		if (event.LeftIsDown())
		{
			mGrabbedItem->SetLocation(event.GetX(), event.GetY());
		}
		else
		{
			// When the left button is released, we release the
			// item.
			mGrabbedItem = nullptr;
		}

		// Force the screen to redraw
		Refresh();
	}
}
/**
 * Refresh the screen to make it appear that an image is moving
 * @param event Timer event that happeneds
 */
void AquariumView::OnTimer(wxTimerEvent &event)
{
	Refresh();
}