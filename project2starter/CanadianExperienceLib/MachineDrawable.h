/**
 * @file MachineDrawable.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDRAWABLE_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDRAWABLE_H

#include "Drawable.h"
#include "AnimChannelPoint.h"
#include <machine-api.h>

struct ma_engine;
/**
 * The adapter class to get the machine to draw
 */
class MachineDrawable : public Drawable
{
private:
	/// Machine System object
	std::shared_ptr<MachineSystem> mMachineSystem;

	/// Channel for the head position
	AnimChannelPoint mPositionChannel;
	/// Star time for the machine
	int mStartTime = 0;
//	/// The end time for the machine
//	double mEndTime = 0;
	// The current frame rate
	/// The Start time in Frame rate
	double mFramerate = 0;
	/// The start time in frames
	double mFrame = 0;
public:

	MachineDrawable(const std::wstring &name,std::wstring resourcesDir, ma_engine* audioEngine);

	virtual bool HitTest(wxPoint pos) override;

	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

	int CreatDialogBox(wxWindow* parent);
	/**
	 * Get the start time of the machine
	 * @return The start time of the machine
	 */
	int GetStartTime(){return mStartTime;}

//	double GetEndTime(){return mEndTime;}

	void SetStartTime(double start);

	void SetMachineNum(int num);
	int GetMachineNum();
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDRAWABLE_H
