/**
 * @file ScreenApp.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "ScreenApp.h"
#include <MainFrame.h>
/**
 * Initialize the application.
 * @return false if the screen can't populate otherwise true
 */
bool ScreenApp::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	auto frame = new MainFrame();
	frame->Initialize();
	frame->Show(true);

	return true;
}