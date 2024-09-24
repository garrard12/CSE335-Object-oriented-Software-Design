/**
 * @file WhiteScreen.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "WhiteScreen.h"
#include <wx/dcbuffer.h>

/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void WhiteScreen::Initialize(wxFrame* parent)
{
	Create(parent, wxID_ANY);
	SetBackgroundColour(*wxWHITE);
	Bind(wxEVT_PAINT, &WhiteScreen::OnPaint, this);
	SetBackgroundStyle(wxBG_STYLE_PAINT);


}

/**
 * Paint event, draws the image on to the screen
 * @param event Paint event object
*/
void WhiteScreen::OnPaint(wxPaintEvent& event)
{
	wxAutoBufferedPaintDC dc(this);
	//This make a black thine line
	wxBrush background(*wxWHITE);
	dc.SetBackground(background);
	dc.Clear();

	/*
	 * The last thing in the code goes on top
	 * Leafs: rgba(2,119,8,255) Arc
	 * Tree: rgba(199,121,44,255) / 121,60,0,255 rectangle
	 * Sand: rgb(215,189,76) rectangle
	 * water: 0,161,232,255) rectangle
	 * sun : rgba(250,250,91,255) circle with lines
	 * The screen is 800 pixel tall by 750 wid
	 */

	//The water
	wxBrush brush(wxColour(0,161,232,255));
	dc.SetBrush(brush);

	dc.DrawRectangle(750, 800, -500,-100);

	//Sand
	brush = wxColour(215,189,76);
	dc.SetBrush(brush);
	//The bottom layer
	dc.DrawRectangle(0, 699, 250,120);
	//second layer
	dc.DrawRectangle(0,630,220,70);

	//Tree
	wxBrush treeColor = wxColour(117, 41, 4) ;
	//brush = wxColour(199,121,44,255) ;
	dc.SetBrush(treeColor);
	//number one (Counting from gound up)
	dc.DrawRectangle(80,580,75,50);
	//number 2
	dc.DrawRectangle(95,530,75,50);
	//number 3
	dc.DrawRectangle(115,480,75,50);
	//number 4
	dc.DrawRectangle(135,430,75,50);
	//number 5
	dc.DrawRectangle(155,380,75,50);
	//number 6
	dc.DrawRectangle(177,330,75,50);


	//Leafs
	wxBrush leafs = wxColour(2,119,8,255);
	dc.SetBrush(leafs);
	//dc.DrawEllipse(200,320,50,200);
	//dc.DrawEllipticArc(200,320,50,200,50,25);


	//Sun
	wxBrush sun = wxColour(250,250,91,255);
	dc.SetBrush(sun);
	//1 top one
	//1 bottom one
	//3 point is where the tip is
	//dc.DrawArc(300 ,15,10,15,150,75);
	//Top layer to the sun
	dc.DrawCircle(700,10,200);


	//Monkey
	wxBrush monkey = wxColour(0,0,0);
	dc.SetBrush(monkey);
	//chest
	dc.DrawLine(100,425,140,350);
	//front
	dc.DrawLine(110,325,140,350);
	//top
	dc.DrawLine(90,375,110,325);
	//back
	dc.DrawLine(100,425,90,375);

	//back legs
	dc.DrawLine(100,425,135, 430);
	dc.DrawLine(100,425,155, 400);

	//front legs
	dc.DrawLine(140,350,160,380);
	dc.DrawLine(140,350,180,350);

	//head
	dc.SetBrush(wxNullBrush);
	dc.DrawRectangle(105,300,35,20);

	//neck
	dc.DrawLine(110,325,115,320);
	dc.DrawLine(122,335,120,320);



/*
	//(x1,y1) is the top x2 is the bottom
	dc.DrawLine(500,5,500,800);

	// this make a thick green line
	wxPen pen(wxColour(0, 128, 0), 3);
	dc.SetPen(pen);
	dc.DrawLine(500, 70, 1000, 200);
	dc.DrawRectangle(50, 50, -50, -50);


	//fills the box in
	wxBrush xbrush(wxColour(0, 0, 255));
	//get rid of the outline
	//dc.SetPen(wxNullPen);
	dc.SetBrush(xbrush);
	//draw rectangle that is emppty
	// PLotst the top of box then exapnts down and to the right
	// betive flips it
	dc.DrawRectangle(50, 50, -50, -5);
//
//	//Fonts
//	// Creates a 20-pixel tall font
//	// Pretty much the kind of font want/needed
//	wxFont font(wxSize(0, 20),
//				wxFONTFAMILY_SWISS,
//				wxFONTSTYLE_NORMAL,
//				wxFONTWEIGHT_NORMAL);
//	dc.SetFont(font);
//	// This displays the color needs
//	dc.SetTextForeground(wxColour(0, 64, 0));
//	dc.DrawText(L"CSE 335 rocks!",  // Text to draw
//				10,     // x coordinate for the left size of the text
//				10);    // y coordinate for the top of the text

*/

}