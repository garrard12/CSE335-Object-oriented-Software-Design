/**
 * @file FishGusTest.cpp
 * @author Auden Garrard
 */


#include <pch.h>
#include "gtest/gtest.h"
#include <Gus.h>
#include <FishBeta.h>
#include <Angler.h>
#include <Bubbles.h>
#include <Aquarium.h>

TEST(FishGusTest, DoubleClickTest){
	//Creat an aquarium to test in
	Aquarium aquarium;

	//Create some fish
	auto beta = std::make_shared<FishBeta>(&aquarium);
	auto gus = std::make_shared<Gus>(&aquarium);
	auto bubbles = std::make_shared<Bubbles>(&aquarium);
	auto angler = std::make_shared<Angler>(&aquarium);


	//Add the fish to the aquarium
	aquarium.Add(beta);
	aquarium.Add(gus);
	aquarium.Add(bubbles);
	aquarium.Add(angler);

	//Set some locations
	gus->SetLocation(200,250);
  	beta->SetLocation(300,250);
	angler->SetLocation(400,300);
	bubbles->SetLocation(162.87,101.49);

	gus->DoubleClickTest(gus);

	ASSERT_NEAR(250,beta->GetY(),.01) << L"Guss Doesn't Move Y";
	ASSERT_NEAR(200,gus->GetX(),.01) << L"Guss Doesn't Move X";

	ASSERT_NEAR(350,beta->GetX(),.01) << L"Failed Beta fish X";
	ASSERT_NEAR(250,beta->GetY(),.01) << L"Failed Beta fish Y";

	ASSERT_NEAR(448.50,angler->GetX(),.01) << L"Failed Angler fish X";
	ASSERT_NEAR(312.12,angler->GetY(),.01) << L"Failed Angler fish Y";

	ASSERT_NEAR(150.74,bubbles->GetX(),.01) << L"Failed Bubbles fish X";
	ASSERT_NEAR(52.98,bubbles->GetY(),.01) << L"Failed Bubbles fish Y";

	//This is the test if fish is on top of Gus
	beta->SetLocation(200,250);
	angler->SetLocation(200,250);
	bubbles->SetLocation(200,250);

	gus->DoubleClickTest(gus);

	ASSERT_NEAR(250,beta->GetX(),.01) << L"Failed Beta fish X";
	ASSERT_NEAR(300,beta->GetY(),.01) << L"Failed Beta fish Y";

	ASSERT_NEAR(250,angler->GetX(),.01) << L"Failed Angler fish X";
	ASSERT_NEAR(300,angler->GetY(),.01) << L"Failed Angler fish Y";

	ASSERT_NEAR(250,bubbles->GetX(),.01) << L"Failed Bubbles fish X";
	ASSERT_NEAR(300,bubbles->GetY(),.01) << L"Failed Bubbles fish Y";
}
