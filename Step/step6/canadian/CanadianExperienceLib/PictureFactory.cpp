/**
 * @file PictureFactory.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "Actor.h"
#include "HaroldFactory.h"
#include "ImageDrawable.h"
#include "AmmyFactory.h"

using namespace std;
/**
 * Creating the images on screen
 * @param imagesDir the images to be made
 * @return The images on the screen
 */
shared_ptr<Picture> PictureFactory::Create(wstring imagesDir)
{
	shared_ptr<Picture> picture = make_shared<Picture>();

	// Create the background and add it
	auto background = make_shared<Actor>(L"Background");
	background->SetClickable(false);
	background->SetPosition(wxPoint(0, 0));
	auto backgroundI =
		make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background.jpg");
	background->AddDrawable(backgroundI);
	background->SetRoot(backgroundI);
	picture->AddActor(background);

	// Create and add Harold
	HaroldFactory haroldFactory;
	auto harold = haroldFactory.Create(imagesDir);

	// This is where Harold will start out.
	harold->SetPosition(wxPoint(300, 500));
	picture->AddActor(harold);

	// Create and add Ammy
	AmmyFactory ammyFactory;
	auto ammy = ammyFactory.Create(imagesDir);

	// This is where Harold will start out.
	ammy->SetPosition(wxPoint(500, 500));
	picture->AddActor(ammy);

	return picture;
}
