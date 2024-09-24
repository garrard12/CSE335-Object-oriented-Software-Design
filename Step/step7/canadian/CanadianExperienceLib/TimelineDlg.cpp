/**
 * @file TimelineDlg.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include <wx/xrc/xmlres.h>
#include <wx/valnum.h>

#include "TimelineDlg.h"
#include "Timeline.h"
#include "PictureObserver.h"


/**
* Constructor
* @param parent The parent window we will center in
* @param timeline Pointer to the timeline we are editing
*/
TimelineDlg::TimelineDlg(wxWindow* parent, Timeline* timeline) : mTimeline(timeline)
{
	wxXmlResource::Get()->LoadDialog(this, parent, L"TimelineDlg");

	// initialize the member variables
	mNumberOfFrames = timeline->GetNumFrames();
	mFrameRate = timeline->GetFrameRate();

	// The first param is the dialog box, Second name we gae the control in wxFormBuilder
	// Third is the type of the control
	auto numFramesCtrl = XRCCTRL(*this, "TimelineDlgNumFrames", wxTextCtrl);
	auto frameRateCtrl = XRCCTRL(*this,"TimelineDlgFrameRate",wxTextCtrl);

	//Validators
	wxIntegerValidator<int> numFramesValidator(&mNumberOfFrames);
	numFramesValidator.SetRange(1, 10000);
	numFramesCtrl->SetValidator(numFramesValidator);

	wxIntegerValidator<int> frameRateValidator(&mFrameRate);
	frameRateValidator.SetRange(1, 60);
	frameRateCtrl->SetValidator(frameRateValidator);


	Bind(wxEVT_BUTTON, &TimelineDlg::OnOK, this, wxID_OK);

}


/**
 * Handle an OK button press
 * @param event Button event
 */
void TimelineDlg::OnOK(wxCommandEvent& event)
{
	if ( Validate() && TransferDataFromWindow() )
	{
		// Success! Set values in the class
		mTimeline->SetNumFrames(mNumberOfFrames);
		mTimeline->SetFrameRate(mFrameRate);

		// Close the dialog box
		EndModal(wxID_OK);
	}

}

