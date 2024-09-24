/**
 * @file ActualMachineSystem.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_ACTUALMACHINESYSTEM_H
#define CANADIANEXPERIENCE_MACHINELIB_ACTUALMACHINESYSTEM_H

#include "MachineSystem.h"
class Machine;
struct ma_engine;
/**
 * The override class for MachineSystem
 */
class ActualMachineSystem : public MachineSystem
{
private:
	/// The miniaudio engine
	ma_engine* mAudioEngine;
	/// The resources directory
	std::wstring mResourcesDir;
	/// The Machine that is being built
	std::shared_ptr<Machine> mMachine;
	/// The framerate of the machine
	double mFramerate = 0;
	/// The time that the machine is on
	double mTime = 0;

public:

	ActualMachineSystem(ma_engine* audio,std::wstring resourceDir);

	void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;

	double GetMachineTime() override;

	int GetMachineNumber() override;

	void SetMachineNumber(int machine) override;

	void SetFrameRate(double rate) override;

	void SetMachineFrame(int frame) override;

	wxPoint GetLocation() override;

	void SetLocation(wxPoint location) override;

};
#endif //CANADIANEXPERIENCE_MACHINELIB_ACTUALMACHINESYSTEM_H
