/**
 * @file TimelineDlg.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_TIMELINEDLG_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_TIMELINEDLG_H


class Timeline;

/**
 * Timeline dialog box
 */
class TimelineDlg final : public wxDialog
{
private:
	/// Point to timeline
	Timeline* mTimeline;
	/// Number of frames in the animation
	int mNumberOfFrames;
	/// Frame rate in the animation
	int mFrameRate;
public:

	TimelineDlg(wxWindow* parent, Timeline* timeline);

	void OnOK(wxCommandEvent& event);
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_TIMELINEDLG_H
