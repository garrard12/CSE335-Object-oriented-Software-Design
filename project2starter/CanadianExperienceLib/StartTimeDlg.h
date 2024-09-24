/**
 * @file StartTimeDlg.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_STARTTIMEDLG_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_STARTTIMEDLG_H

class Picture;
/** Generates the Dlg box to set the time*/
class StartTimeDlg : public wxDialog
{
private:
	/// The picture to draw
	std::shared_ptr<Picture> mPicture;
	/// The Time to start the machien
	double mStartTime = 0 ;
	/// The machine we want changed
	int mMachine = 0;

public:

	StartTimeDlg(wxWindow* parent,std::shared_ptr<Picture> picture);

	void OnOK(wxCommandEvent& event);
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_STARTTIMEDLG_H
