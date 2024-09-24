/**
 * @file MainFrame.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "MainFrame.h"
#include "GreenScreen.h"
#include "WhiteScreen.h"


/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
	Create(nullptr, wxID_ANY, L"Auden Auden Garrard",
		   wxDefaultPosition,  wxSize( 1000,800 ));

	// Create a sizer that will lay out child windows HORIZONTAL
	// one next to each other
	auto sizer = new wxBoxSizer( wxHORIZONTAL );

	// Create the whiteScreen class object as a child of MainFrame
	auto whiteScreen = new WhiteScreen();
	whiteScreen->Initialize(this);

	// Create the greenScreen class object as a child of MainFrame
	auto greenScreen = new GreenScreen();
	greenScreen->Initialize(this);

	// Add it to the sizer
	sizer->Add(greenScreen,1,wxEXPAND | wxLEFT);
	sizer->Add(whiteScreen,3, wxEXPAND | wxRight);

	// Set the sizer for this frame
	SetSizer(sizer);

	// Layout (place) the child windows.
	Layout();
}




