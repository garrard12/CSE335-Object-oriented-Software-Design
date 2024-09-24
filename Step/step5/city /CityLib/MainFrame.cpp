/**
 * @file MainFrame.cpp
 * @author Charles B. Owen
 */
#include "pch.h"
#include "ids.h"

#include "MainFrame.h"

#include "CityView.h"


/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"City", wxDefaultPosition,  wxSize( 1000,800 ));

    auto sizer = new wxBoxSizer( wxVERTICAL );

    mCityView = new CityView();
    mCityView->Initialize(this);

    sizer->Add(mCityView,1, wxEXPAND | wxALL );

    SetSizer( sizer );
    Layout();

    CreateStatusBar();

    auto menuBar = new wxMenuBar( );

    auto fileMenu = new wxMenu();
    auto viewMenu = new wxMenu();
    auto helpMenu = new wxMenu();

    fileMenu->Append(wxID_SAVEAS, "Save &As...\tCtrl-S", L"Save city as...");
    fileMenu->Append(wxID_OPEN, "Open &File...\tCtrl-F", L"Open city file...");
    fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");

    // Recently used files
    mHistory.Load(mConfig);
    mHistory.UseMenu(fileMenu);
    mHistory.AddFilesToMenu();

    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);

    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnFileSaveAs, this, wxID_SAVEAS);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnFileOpen, this, wxID_OPEN);
    Bind(wxEVT_MENU, &MainFrame::OnMRUFile, this, wxID_FILE1, wxID_FILE9);

    menuBar->Append(fileMenu, L"&File" );
    menuBar->Append(viewMenu, L"&View");
    mCityView->AddMenus(this, menuBar, fileMenu, viewMenu);
    menuBar->Append(helpMenu, L"&Help");

    SetMenuBar( menuBar );
}

/**
 * File>Save As menu handler
 * @param event Menu event
 */
void MainFrame::OnFileSaveAs(wxCommandEvent& event)
{
    wxFileDialog saveFileDialog(this, _("Save City file"), "", "",
            "City Files (*.city)|*.city", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    auto filename = saveFileDialog.GetPath();
    mCityView->Save(filename);
    mHistory.AddFileToHistory(filename);
    mHistory.Save(mConfig);
}

/**
 * File>Open menu handler
 * @param event Menu event
 */
void MainFrame::OnFileOpen(wxCommandEvent& event)
{
    wxFileDialog loadFileDialog(this, _("Load City file"), "", "",
            "City Files (*.city)|*.city", wxFD_OPEN);
    if (loadFileDialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    auto filename = loadFileDialog.GetPath();
    mCityView->Load(filename);
    mHistory.AddFileToHistory(filename);
    mHistory.Save(mConfig);
}


/**
 * Handle the File most recerntly used file menu options
 * @param event Menu event
 */
void MainFrame::OnMRUFile(wxCommandEvent& event)
{
    wxString filename(mHistory.GetHistoryFile(event.GetId() - wxID_FILE1));
    if (!filename.empty())
    {
        mCityView->Load(filename);
        mHistory.AddFileToHistory(filename);
        mHistory.Save(mConfig);
    }
}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
  Close(true);
}

/**
 * Application about box menu handler
 */
void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(L"Welcome to the City!",
            L"About the City",
            wxOK | wxCENTRE,
            this);
}

/**
 * Handle a close event. Stop the animation and destroy this window.
 * @param event The Close event
 */
void MainFrame::OnClose(wxCloseEvent& event)
{
    mCityView->Stop();
    Destroy();
}

