/**
 * @file MainDialog.cpp
 * @author Charles B. Owen
 */
#include "pch.h"

#include <wx/xrc/xmlres.h>
#include <wx/stdpaths.h>

#include "MainDialog.h"

/**
 * Constructor
 */
MainDialog::MainDialog()
{
    wxXmlResource::Get()->LoadDialog(this, nullptr, L"MainDialog");
#ifdef WIN32
    SetIcon(wxIcon(L"mainframe", wxBITMAP_TYPE_ICO_RESOURCE));
#endif

    auto mnp = XRCCTRL(*this, "MagicNumberPrompt", wxStaticText);
    mnp->Hide();

    Bind(wxEVT_CLOSE_WINDOW, &MainDialog::OnClose, this);
    Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainDialog::OnOk, this, wxID_OK);
    Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainDialog::OnCloseButton, this, XRCID("CloseButton"));
}

/**
 * Handle a window close event.
 * @param event The EVT_CLOSE_WINDOW event
 */
void MainDialog::OnClose(wxCloseEvent& event)
{
    Destroy();
}

/**
 * Handle a close button press
 * @param event The button press event
 */
void MainDialog::OnCloseButton(wxCommandEvent &event)
{
    Close();
}

/**
 * Handle an OK button press
 * @param event The button press event
 */
void MainDialog::OnOk(wxCommandEvent &event)
{
    auto pluginCodeCtrl = XRCCTRL(*this, "CLionPluginCode", wxTextCtrl);
    auto pluginCodeStr = pluginCodeCtrl->GetValue();
    pluginCodeStr.Trim();
    pluginCodeStr.Trim(false);
    if(pluginCodeStr.empty())
    {
        wxMessageBox(L"You must enter a CLion Plugin Code", "Must Enter Code", wxOK|wxCENTRE, this);
        return;
    }

    const int p = 93719;
    const int a = 21;
    const int b = 37;

    auto y = wxAtol(pluginCodeStr);
    if(y == 0)
    {
        wxMessageBox(L"You must enter a CLion Plugin Code", "Must Enter Code", wxOK|wxCENTRE, this);
        return;
    }

    auto x = ((y & 0xffffff) * a + b) % p;
    auto mnp = XRCCTRL(*this, "MagicNumberPrompt", wxStaticText);
    mnp->Show();

    auto mn = XRCCTRL(*this, "MagicNumber", wxStaticText);
    mn->SetLabel(wxString::Format(wxT("%ld"), x));
}