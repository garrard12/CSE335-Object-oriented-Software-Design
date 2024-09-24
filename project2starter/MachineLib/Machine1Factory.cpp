/**
 * @file Machine1Factory.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "Machine1Factory.h"
#include "Machine.h"
#include "CardReader.h"
#include "Component.h"
#include "Shape.h"
#include "Pipe.h"
#include "Cylinder.h"
#include "StruckInstrument.h"
#include "AirSource.h"
#include "Tubing.h"

using namespace std;
/**
 * Constructor
 * @param resourcesDir The resources Directory
 * @param audioEngine The audio engine
 */
Machine1Factory::Machine1Factory(std::wstring resourcesDir, ma_engine *audioEngine)
	: mAudioEngine(audioEngine),mResourcesDir(resourcesDir){}

/**
 * Creates the machine
 * @return THe machine that was created
 */
std::shared_ptr<Machine> Machine1Factory::Create()
{

	// Sizes
	const int BackgroundWidth = 550;

	// Locations of stuff
	const int BaseWidth = 700;
	const int BaseHeight = 10;

	// All the centers (X)
	const int BackgroundCenter = 80;
	const int CardReaderCenter = -275;
	const int CymbalAndDrumCenter = 295;
	const int ClampingPostCenter = -182;

	const int NumPipes = 5;
	const int PipesCenter = 100;
	const int PipeSpacing = 40;
	const int PipeY = -100;

	shared_ptr<Machine> machineOne = make_shared<Machine>(mResourcesDir);

	//
	// The base to the machine
	//
	auto base = make_shared<Shape>();
	base->Rectangle(-BaseWidth /2, BaseHeight, BaseWidth, BaseHeight);
	base->SetColor(wxColour(100, 100, 100));
	machineOne->AddComponent(base);

	//
	// The background image
	//
	auto background = std::make_shared<Shape>();
	background->SetImage(mResourcesDir + L"/images/mortier.png");
	background->Rectangle(-BackgroundWidth /2, 0, BackgroundWidth, 0);
	background->SetPosition(wxPoint(BackgroundCenter, 0));
	machineOne->AddComponent(background);

	//
	// The card reader Info
	//
	auto reader = make_shared<CardReader>(mResourcesDir);
	reader->SetCard(mResourcesDir + L"/images/cards/suzanna.png");
	reader->SetPosition(wxPoint(CardReaderCenter,0));
	machineOne->AddComponent(reader);


	//
	// Pipes
	//
	int PipeLength[] = { 200, 150, 105, 80, 55 };
	const wchar_t* sounds[] = {L"/audio/organC4.wav",
		L"/audio/organD4.wav",
		L"/audio/organE4.wav",
		L"/audio/organG4.wav",
		L"/audio/organA4.wav"};

	// Vector to collect the pipes so we can
	// run hoses to them later.
	std::vector<std::shared_ptr<Pipe>> pipes;

	//
	// The pipes
	//
	int pipeX = -PipeSpacing * NumPipes / 2 + PipesCenter;
	for (int i = 0; i < NumPipes; i++) {
		//
		// The pipes
		//
		auto pipe = std::make_shared<Pipe>(mResourcesDir, mAudioEngine, sounds[i], PipeLength[i]);
		pipe->SetPosition(wxPoint(pipeX, PipeY));
		machineOne->AddComponent(pipe);
		pipes.push_back(pipe);

		pipeX += PipeSpacing;
	}

	//
	// The cymbal
	//
	auto cymbal = std::make_shared<StruckInstrument>(mResourcesDir, mAudioEngine, L"/audio/cymbal.wav");
	cymbal->SetImage(mResourcesDir + L"/images/cymbal-all.png");
	cymbal->Rectangle(-cymbal->GetImageWidth()/2, 0);
	cymbal->SetPosition(wxPoint(CymbalAndDrumCenter, 0));
	machineOne->AddComponent(cymbal);

	auto cymbalCylinder = std::make_shared<Cylinder>(mResourcesDir);
	cymbalCylinder->SetPosition(wxPoint(CymbalAndDrumCenter - 25, -350));
	cymbalCylinder->SetRotation(0.5);
	cymbalCylinder->SetMaxExtent(0.55);
	machineOne->AddComponent(cymbalCylinder);

	// I dont think this is impelent
	cymbalCylinder->SetMotionSink(cymbal);

	//
	// The drum
	//
	auto drum = std::make_shared<StruckInstrument>(mResourcesDir, mAudioEngine, L"/audio/kick.wav");
	drum->SetImage(mResourcesDir + L"/images/drum.png");
	drum->Rectangle(-drum->GetImageWidth() / 2, 0);
	drum->SetPosition(wxPoint(CymbalAndDrumCenter, 0));
	machineOne->AddComponent(drum);

	// Block to hold the cylinder
	auto block = std::make_shared<Shape>();
	block->SetImage(mResourcesDir + L"/images/angle-block.png");
	block->Rectangle(-block->GetImageWidth(), 0);   // 0,0 is lower right corner
	block->SetPosition(wxPoint(110, 0));
	machineOne->AddComponent(block);

	auto drumCylinder = std::make_shared<Cylinder>(mResourcesDir);
	drumCylinder->SetPosition(wxPoint(110, -30));
	drumCylinder->SetRotation(0.25);
	machineOne->AddComponent(drumCylinder);

	drumCylinder->SetMotionSink(drum);

	auto post = std::make_shared<Shape>();
	post->SetImage(mResourcesDir + L"/images/clamping-post.png");
	post->Rectangle(-post->GetImageWidth()/2, 0);
	post->SetPosition(wxPoint(ClampingPostCenter, 0));
	machineOne->AddComponent(post);

	    //
    // Temporary connection from card reader to pipes
    // Use this code to get the system working before you
    // add the Tubing class.
    //
//    for (int i = 0; i < 5; i++)
//    {
//        reader->GetSource(i)->SetSink(pipes[4 - i]->GetSink());
//    }
//
//    reader->GetSource(9)->SetSink(cymbalCylinder->GetSink());
//    reader->GetSource(8)->SetSink(drumCylinder->GetSink());

	//
	// We do the tubing last so it is on top
	//
	for (int i = 0; i < 5; i++)
	{
		auto tubing = std::make_shared<Tubing>();
		reader->GetSource(i)->SetSpeed(50);
		reader->GetSource(i)->SetSink(tubing->GetSink());
		tubing->GetSource()->SetSink(pipes[4-i]->GetSink());
		machineOne->AddComponent(tubing);

		//tubing->AddClamp(ClampingPostCenter, -10 - 10*i, 0.75, 40);
	}

	auto tubing = std::make_shared<Tubing>();
	reader->GetSource(9)->SetSink(tubing->GetSink());
	reader->GetSource(9)->SetSpeed(25);
	reader->GetSource(9)->SetSpeed(50);
	tubing->GetSource()->SetSink(cymbalCylinder->GetSink());
	machineOne->AddComponent(tubing);

//	tubing->AddClamp(-180, -150, 0.5, 80);
//	tubing->AddClamp(-180, -300, 0.5, 100);

	tubing = std::make_shared<Tubing>();
	reader->GetSource(8)->SetSpeed(10);
	reader->GetSource(8)->SetSink(tubing->GetSink());
	tubing->GetSource()->SetSink(drumCylinder->GetSink());
	machineOne->AddComponent(tubing);

//	tubing->AddClamp(ClampingPostCenter, -10 - 10 * 5, 0.75, 50);
//
	// Clamping post clamps for the tubing
	auto clamps = std::make_shared<Shape>();
	clamps->SetImage(mResourcesDir + L"/images/clamping-post-clamps.png");
	clamps->Rectangle(-clamps->GetImageWidth()/2, 0);
	clamps->SetPosition(wxPoint(ClampingPostCenter, 0));
	machineOne->AddComponent(clamps);
//
	//
	// The foreground image (ropes that draw in front)
	//
	auto backgroundRope = std::make_shared<Shape>();
	backgroundRope->SetImage(mResourcesDir + L"/images/mortier-rope.png");
	backgroundRope->Rectangle(-BackgroundWidth /2, 0, BackgroundWidth, 0);
	backgroundRope->SetPosition(wxPoint(BackgroundCenter, 0));
	machineOne->AddComponent(backgroundRope);

	return machineOne;
}

