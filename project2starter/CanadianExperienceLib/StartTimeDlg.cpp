/**
 * @file StartTimeDlg.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "StartTimeDlg.h"
#include "Picture.h"

#include <wx/xrc/xmlres.h>
#include <wx/valnum.h>

/// Machine one
const int MachineOne = 1;
/// Machine two
const int MachineTwo = 2;
/**
 * Constructor
 * @param parent The parent window we will center in
 * @param picture Pointer to the timeline we are editing
 */
StartTimeDlg::StartTimeDlg(wxWindow* parent,std::shared_ptr<Picture> picture)
{
	wxXmlResource::Get()->LoadDialog(this, parent, L"SetStartTime");

	mPicture = picture;

	mStartTime = picture->GetStartTimeMachineOne();

	Bind(wxEVT_BUTTON, &StartTimeDlg::OnOK, this, wxID_OK);

	auto numFramesCtrl = XRCCTRL(*this, "StartTime", wxTextCtrl);
	wxIntegerValidator<double> numFramesValidator(&mStartTime);
	numFramesValidator.SetRange(1, 10000);
	numFramesCtrl->SetValidator(numFramesValidator);

	auto frameRateCtrl = XRCCTRL(*this, "Machine", wxTextCtrl);
	wxIntegerValidator<int> frameRateValidator(&mMachine);
	frameRateValidator.SetRange(1, 2);
	frameRateCtrl->SetValidator(frameRateValidator);
}
/**
* Handle an OK button press
* @param event Button event
*/
void StartTimeDlg::OnOK(wxCommandEvent& event)
{
	if (Validate() && TransferDataFromWindow() )
	{
		if(mMachine == MachineOne)
		{
			mPicture->SetStartTimeMachineOne(mStartTime);
		}
		else
		{
			mPicture->SetStartTimeMachineTwo(mStartTime);
		}
		EndModal(wxID_OK);
	}
}