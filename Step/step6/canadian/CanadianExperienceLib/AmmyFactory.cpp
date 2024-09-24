/**
 * @file AmmyFactory.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "AmmyFactory.h"
#include "Actor.h"
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"

using namespace std;
/**
 * This is a factory method that creates our Harold actor.
 * @param imagesDir Directory that contains the images for this application
 * @return Pointer to an actor object.
 */
std::shared_ptr<Actor> AmmyFactory::Create(std::wstring imagesDir)
{

	shared_ptr<Actor> actor = make_shared<Actor>(L"Ammy");

	auto shirt = make_shared<ImageDrawable>(L"Shirt", imagesDir + L"/black_coat.png");
	shirt->SetCenter(wxPoint(44, 138));
	shirt->SetPosition(wxPoint(0, -114));
	actor->SetRoot(shirt);


	//
	// Arms
	//

	auto larm = make_shared<PolyDrawable>(L"Left Arm");
	larm->SetColor(wxColour(60, 174, 184));
	larm->SetPosition(wxPoint(50, -130));
	larm->AddPoint(wxPoint(-7, -7));
	larm->AddPoint(wxPoint(-7, 96));
	larm->AddPoint(wxPoint(8, 96));
	larm->AddPoint(wxPoint(8, -7));
	shirt->AddChild(larm);

	auto rarm = make_shared<PolyDrawable>(L"Right Arm");
	rarm->SetColor(wxColour(60, 174, 184));
	rarm->SetPosition(wxPoint(-45, -130));
	rarm->AddPoint(wxPoint(-7, -7));
	rarm->AddPoint(wxPoint(-7, 96));
	rarm->AddPoint(wxPoint(8, 96));
	rarm->AddPoint(wxPoint(8, -7));
	shirt->AddChild(rarm);

	//
	// hand
	//

	auto lhand = make_shared<PolyDrawable>(L"Left Hand");
	lhand->SetColor(wxColour(207,157,114));
	lhand->SetPosition(wxPoint(0, 96));
	lhand->AddPoint(wxPoint(-12, -2));
	lhand->AddPoint(wxPoint(-12, 17));
	lhand->AddPoint(wxPoint(11, 17));
	lhand->AddPoint(wxPoint(11, -2));
	larm->AddChild(lhand);

	auto rhand = make_shared<PolyDrawable>(L"Right Hand");
	rhand->SetColor(wxColour(207,157,114));
	rhand->SetPosition(wxPoint(0, 96));
	rhand->AddPoint(wxPoint(-12, -2));
	rhand->AddPoint(wxPoint(-12, 17));
	rhand->AddPoint(wxPoint(11, 17));
	rhand->AddPoint(wxPoint(11, -2));
	rarm->AddChild(rhand);

	//
	// Legs
	//

	auto lleg = make_shared<ImageDrawable>(L"Left Leg", imagesDir + L"/lleg2.png");
	lleg->SetCenter(wxPoint(11, 9));
	lleg->SetPosition(wxPoint(27, 0));
	shirt->AddChild(lleg);

	auto rleg = make_shared<ImageDrawable>(L"Right Leg", imagesDir + L"/rleg2.png");
	rleg->SetCenter(wxPoint(39, 9));
	rleg->SetPosition(wxPoint(-27, 0));
	shirt->AddChild(rleg);

	//
	// Head
	//

	auto headb = make_shared<ImageDrawable>(L"Head Bottom", imagesDir + L"/harold_headb.png");
	headb->SetCenter(wxPoint(44, 31));
	headb->SetPosition(wxPoint(0, -130));
	shirt->AddChild(headb);

	auto headt = make_shared<HeadTop>(L"Head Top", imagesDir + L"/headt3.png");
	headt->SetCenter(wxPoint(55, 100));
	headt->SetEye(wxPoint(50, 65));
	headt->SetPosition(wxPoint(0, -25));
	headb->AddChild(headt);

	//
	// Add them to drawable
	//
	actor->AddDrawable(larm);
	actor->AddDrawable(rarm);
	actor->AddDrawable(rhand);
	actor->AddDrawable(lhand);
	actor->AddDrawable(lleg);
	actor->AddDrawable(rleg);
	actor->AddDrawable(shirt);
	actor->AddDrawable(headb);
	actor->AddDrawable(headt);

	return actor;
}
