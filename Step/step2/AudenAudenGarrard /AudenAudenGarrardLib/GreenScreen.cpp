/**
 * @file GreenScreen.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "GreenScreen.h"
#include <wx/dcbuffer.h>


/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void GreenScreen::Initialize(wxFrame* parent)
{
	Create(parent, wxID_ANY);
	SetBackgroundColour(wxColour(24, 69, 59));
}


