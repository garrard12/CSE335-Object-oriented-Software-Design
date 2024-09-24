/**
 * @file MainFrame.h
 * @author Charles B. Owen
 *
 * The top-level (main) frame of the application
 */
#ifndef _MAINFRAME_H_
#define _MAINFRAME_H_

#include <wx/filehistory.h>
#include <wx/config.h>

class CityView;

/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame
{
private:
    /// View class for our city
    CityView *mCityView;

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent&);
    void OnClose(wxCloseEvent &event);

    /// Application assocated configurations
    wxConfig mConfig;

    /// File history
    wxFileHistory mHistory;

public:
    void Initialize();

    void OnMRUFile(wxCommandEvent& event);

    void OnFileSaveAs(wxCommandEvent& event);

    void OnFileOpen(wxCommandEvent& event);
};

#endif //_MAINFRAME_H_
