/**
 * @file PictureFactory.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "MachineDrawable.h"

using namespace std;

/// Directory within resources that contains the images.
const std::wstring ImagesDirectory = L"/images";


/**
 * Factory method to create a new picture.
 * @param resourcesDir Directory that contains the resources for this application
 * @param audioEngine The audio engine to use in this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring resourcesDir, ma_engine* audioEngine)
{
    auto imagesDir = resourcesDir + ImagesDirectory;

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

	auto machineActor = make_shared<Actor>(L"MachineOne");
	machineActor->SetPosition(wxPoint(150,250));
	auto machine = make_shared<MachineDrawable>(L"MachineOne",resourcesDir,audioEngine);
	picture->SetMachineone(machine);
	machineActor->SetRoot(machine);
	machineActor->AddDrawable(machine);
	picture->AddActor(machineActor);

	auto machineActor2 = make_shared<Actor>(L"MachineTwo");
	machineActor2->SetPosition(wxPoint(450,375));
	auto machine2 = make_shared<MachineDrawable>(L"MachineTwo",resourcesDir,audioEngine);
	picture->SetMachinetwo(machine2);
	machineActor2->SetRoot(machine2);
	machineActor2->AddDrawable(machine2);
	picture->AddActor(machineActor2);

    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(600, 610));
    picture->AddActor(harold);

    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(900, 620));
    picture->AddActor(sparty);

    return picture;
}

