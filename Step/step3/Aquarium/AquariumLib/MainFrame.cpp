/**
 * @file MainFrame.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "MainFrame.h"
#include "AquariumView.h"
#include "ids.h"


/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
	Create(nullptr, wxID_ANY, L"Aquarium",
		   wxDefaultPosition,  wxSize( 1000,800 ));

	// Create a sizer that will lay out child windows vertically
	// one above each other
	auto sizer = new wxBoxSizer( wxVERTICAL );

	// Create the view class object as a child of MainFrame
	mAquariumView = new AquariumView();
	mAquariumView->Initialize(this);

	// Add it to the sizer
	sizer->Add(mAquariumView,1, wxEXPAND | wxALL );

	// Set the sizer for this frame
	SetSizer( sizer );

	// Layout (place) the child windows.
	Layout();

	CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	auto menuBar = new wxMenuBar( );

	auto fileMenu = new wxMenu();
	auto helpMenu = new wxMenu();
	auto fishMenu = new wxMenu();


	menuBar->Append(fileMenu, L"&File" );
	menuBar->Append(fishMenu, L"&Add Fish");
	menuBar->Append(helpMenu, L"&Help");

	//This add the drop down menu
	fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
	fishMenu->Append(IDM_ADDFISHBETA, L"&Beta Fish", L"Add a Beta Fish");
	fishMenu->Append(IDM_ADDFISHANGEL,L"&Angler Fish",L"Add a Angler Fish");
	fishMenu->Append(IDM_ADDFISHBUBBLES,L"&Bubbles fish",L"Add a Bubble Fish");
	fishMenu->Append(IDM_ADDFISHGUS,L"&Gus Fish", L"&Add a Gus Fish");
	helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");


	// These Binds the function to menu bars so it can be excuted
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);


	SetMenuBar(menuBar);
}

/**
 * Exit menu option handlers
 * @param event Mouse event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}

/**
* About menu option handler
 * @param event Mouse event
*/
void MainFrame::OnAbout(wxCommandEvent &event)
{
	wxMessageBox(L"Welcome to the Aquarium!",
				 L"About Aquarium",
				 wxOK,
				 this);
}