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
#include "Gus.h"

using namespace std;

/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void AquariumView::Initialize(wxFrame* parent)
{
	Create(parent, wxID_ANY);
	SetBackgroundColour(*wxWHITE);
	SetBackgroundStyle(wxBG_STYLE_PAINT);


	Bind(wxEVT_PAINT, &AquariumView::OnPaint, this);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishBetaFish,
				 this, IDM_ADDFISHBETA);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishAnglerFish,
				 this, IDM_ADDFISHANGEL);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishBubblesFish,
				 this, IDM_ADDFISHBUBBLES);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishGusFish,
				 this, IDM_ADDFISHGUS);
	Bind(wxEVT_LEFT_DOWN, &AquariumView::OnLeftDown, this);
	Bind(wxEVT_LEFT_UP, &AquariumView::OnLeftUp, this);
	Bind(wxEVT_MOTION, &AquariumView::OnMouseMove, this);
	Bind(wxEVT_LEFT_DCLICK,&AquariumView::OnDoubleClick,this);

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
 * Menu handler for Add Fish Gus
 * @param event Mouse event
 */
void AquariumView::OnAddFishGusFish(wxCommandEvent &event)
{
	auto fish = std::make_shared<Gus>(&mAquarium);
	mAquarium.Add(fish);
	//This makes the image appear onto the screen
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