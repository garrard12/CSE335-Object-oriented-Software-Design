/**
 * @file ActualMachineSystem.cpp
 * @author Auden Garrard
 */
#include "pch.h"
#include "ActualMachineSystem.h"
#include "Machine.h"
#include "Machine1Factory.h"
#include "Machine2Factory.h"

/// The first Machine
const int MachineOne = 1;
/// The second Machine
const int MachineTwo = 2;

/**
 * Constructor
 * @param audio The audio engine for miniaudio
 * @param resourceDir The resource directory of imagies
 */
ActualMachineSystem::ActualMachineSystem(ma_engine* audio,std::wstring resourceDir)
	:mAudioEngine(audio),mResourcesDir(resourceDir)
{
	SetMachineNumber(1);
}
/**
 * Get the time the Machine is on
 * @return The time of the machine
 */
double ActualMachineSystem::GetMachineTime()
{
	return mTime;
}
/**
 * The graphic to draw
 * @param graphics The graphic if the machine
 */
void ActualMachineSystem::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
	mMachine->Draw(graphics);
//	mMachine->UpdateTime(mTime);
}
/**
 * What machine is being drawn
 * @return The machine being drawn
 */
int ActualMachineSystem::GetMachineNumber()
{
	return mMachine->GetMachineNumber();
}
/**
 * Select what machine to draw
 * @param machine Which machine to draw
 */
void ActualMachineSystem::SetMachineNumber(int machine)
{
	//
	// Decides which machine to make
	//
	if(machine == MachineOne)
	{
		Machine1Factory m1(mResourcesDir,mAudioEngine);
		mMachine = m1.Create();
		// This is causing a segfault
		mMachine->SetMachineNumber(MachineOne);
	}
	if(machine == MachineTwo)
	{
		Machine2Factory m2(mResourcesDir,mAudioEngine);
		mMachine = m2.Create();
		mMachine->SetMachineNumber(MachineTwo);
	}
}
/**
 * Set the Frame Rate
 * @param rate The want rate
 */
void ActualMachineSystem::SetFrameRate(double rate)
{

	mFramerate = rate;
}
/**
 * Set the machine frame
 * @param frame The frame of the machine
 */
void ActualMachineSystem::SetMachineFrame(int frame)
{
	mTime = frame / mFramerate;
	mMachine->SetTime(mTime);
	mMachine->UpdateTime(mTime);
}
/**
 * The location of the machine
 * @return The location of the machine
 */
wxPoint ActualMachineSystem::GetLocation()
{
	return mMachine->GetLocation();
}
/**
 * Set the Location of the machine
 * @param location Where th machine should be
 */
void ActualMachineSystem::SetLocation(wxPoint location)
{
	mMachine->SetLocation(location);
}

