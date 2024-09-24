/**
 * @file AquariumApp.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "AquariumApp.h"
#include <MainFrame.h>

/**
 * Initialize the application.
 * @return false if the screen can't populate otherwise true
 */
bool AquariumApp::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	// Add image type handlers
	wxInitAllImageHandlers();

	auto frame = new MainFrame();
	frame->Initialize();
	frame->Show(true);

	return true;
}