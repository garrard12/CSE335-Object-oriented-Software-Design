/**
 * @file MainDialog.h
 * @author Charles B. Owen
 *
 * The top-level (main) dialog box for the application
 */
#ifndef _MAINFRAME_H_
#define _MAINFRAME_H_

/**
 * The top-level (main) dialog box for the application
 */
class MainDialog final : public wxDialog
{
private:
    void OnClose(wxCloseEvent& event);
    void OnOk(wxCommandEvent& event);
    void OnCloseButton(wxCommandEvent& event);

public:
    MainDialog();
};

#endif //_MAINFRAME_H_
