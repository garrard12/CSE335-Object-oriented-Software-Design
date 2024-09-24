/**
 * @file MachineDrawable.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "MachineDrawable.h"
#include "Actor.h"
#include "Timeline.h"
#include <machine-api.h>

/**
 * Constroster
 * @param name The name of the machine
 * @param resourcesDir The image resource of the machine
 * @param audioEngine The audio engine to the machine
 */
MachineDrawable::MachineDrawable(const std::wstring &name,std::wstring resourcesDir, ma_engine *audioEngine) : Drawable(name)
{
	MachineSystemFactory machine(resourcesDir,audioEngine);
	mMachineSystem = machine.CreateMachineSystem();
}

/**
 * The machine is not move able
 * @param pos The posstion of the mouse being clicked
 * @return False
 */
bool MachineDrawable::HitTest(wxPoint pos)
{
	return false;
}
/**
 * Draws the machine class
 * @param graphics The graphic to be drawn
 */
void MachineDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
	//
	// Tells the machine what time to start On
	//
	if(GetAngleChannel()->GetTimeline()->GetCurrentTime() >= mStartTime && mStartTime != 0)
	{
		mMachineSystem->SetFrameRate(GetAngleChannel()->GetTimeline()->GetFrameRate());
		mMachineSystem->SetMachineFrame( GetAngleChannel()->GetTimeline()->GetCurrentFrame() - mFrame);
	}
	else if (GetAngleChannel()->GetTimeline()->GetCurrentTime() >= mStartTime)
	{
		mMachineSystem->SetFrameRate(GetAngleChannel()->GetTimeline()->GetFrameRate());
		mMachineSystem->SetMachineFrame(GetAngleChannel()->GetTimeline()->GetCurrentFrame());
	}

	//
	// Draw the Machine class
	//
	double scale = 0.75f;
	graphics->PushState();
	graphics->Translate(mPlacedPosition.x, mPlacedPosition.y);
	graphics->Scale(scale, scale);
	mMachineSystem->SetLocation(wxPoint(mPlacedPosition.x,mPlacedPosition.y));
	mMachineSystem->DrawMachine(graphics);
	graphics->PopState();
}
/**
 * Creates the dialog box
 * @param parent The window to make the box
 * @return If the Dialog box should be return
 */
int MachineDrawable::CreatDialogBox(wxWindow* parent)
{
	MachineDialog dlg(parent,mMachineSystem);
	return dlg.ShowModal();
}
/**
 * Gets the machine number
 * @param num The machine number
 */
void MachineDrawable::SetMachineNum(int num)
{
	mMachineSystem->SetMachineNumber(num);
}
/**
 * Return the machine number
 * @return The machine numebr
 */
int MachineDrawable::GetMachineNum()
{
	mMachineSystem->GetMachineNumber();
}
/**
 * The start time of the machine in secs
 * @param start The start time of the machine
 */
void MachineDrawable::SetStartTime(double start)
{
	mStartTime = start;
	mFramerate = start * GetAngleChannel()->GetTimeline()->GetNumFrames();
	//Cacluate the frame that is should start at
	mFrame = start *  GetAngleChannel()->GetTimeline()->GetFrameRate();
}

