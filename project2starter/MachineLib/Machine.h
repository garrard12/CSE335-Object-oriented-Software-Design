/**
 * @file Machine.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINE_H

#include "ActualMachineSystem.h"

class Component;
/**
 * The Machine that has been built
 */
class Machine
{
private:
	/// The machine is being built
	int mNumber = 0;
	/// The time of the machine
	double mTime = 0;
	/// The location of the machine
	wxPoint mLocation = wxPoint(0,0);
	/// The Frame Rate that it is bing on
	double mFrameRate = 0;
	/// The Frame that is one
	int mFrame = 0;
	/// The directory that hold all the images
	std::wstring mResourcesDir;
	/// All the Component of the machine
	std::vector<std::shared_ptr<Component>> mComponent;

public:
	/// Default constructor (disabled)
	Machine() = delete;

	/// Copy constructor (disabled)
	Machine(const Machine &) = delete;

	/// Assignment operator
	void operator=(const Machine &) = delete;

	Machine(std::wstring resourcesDir);

	void AddComponent(std::shared_ptr<Component> component);

	void Draw(std::shared_ptr<wxGraphicsContext> graphics);

	void UpdateTime(double elapsed);

	/**
	 * Set the Frame of the machine
	 * @param frame The frame of the machine
	 */
	void SetFrame(int frame){mFrame = frame;}
	/**
	 * Get the frame of the machine
	 * @return The frame of the machine
	 */
	int GetFrame() const {return mFrame;}

	/**
	 * Set the Frame rate of the machine
	 * @param frameRate The frame rate of the machine
	 */
	void SetFrameRate(double frameRate) {mFrameRate = frameRate;}

	/**
	 * Get the frame Rate of the machine
	 * @return The frame Rate of the machine
	 */
	double GetFrameRate() const {return mFrameRate;}

	/**
	 * Set the position of the machine
	 * @param position The machine location
	 */
	void SetLocation(wxPoint position) { mLocation = position;}

	/**
	 * Get the location of the machine
	 * @return The location of the machine
	 */
	wxPoint GetLocation() const {return mLocation;}
	/**
	 * Set the time of the machine
	 * @param time The time of the machine
	 */
	void SetTime(double time) { mTime = time;}
	/**
	 * Get the time of the machine
	 * @return The time of the machine
	 */
	double GetTime() const {return mTime;}

	/**
	 * The machine that is being built
	 * @param machineNum The machine that is being built
	 */
	void SetMachineNumber(int machineNum){mNumber = machineNum;}

	/**
	 * THe kind of machine that was built
	 * @return The machine number
	 */
	int GetMachineNumber() const {return mNumber;}


};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
