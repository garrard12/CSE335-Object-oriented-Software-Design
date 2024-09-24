/**
 * @file AquariumTest.cpp
 * @author Auden Garrard
 */


#include <pch.h>
#include "gtest/gtest.h"
#include <Aquarium.h>
#include <FishBeta.h>

using namespace std;

TEST(AquariumTest, Construct){
	Aquarium aquarium;
}

TEST(AquariumTest, NonoverlappingAdd1) {
	Aquarium aquarium;

	shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
	aquarium.Add(fish1);

	ASSERT_NEAR(200, fish1->GetX(), 0.1);
	ASSERT_NEAR(200, fish1->GetY(), 0.1);

	// First fish moved to 210, 210
	fish1->SetLocation(210, 210);

	shared_ptr<FishBeta> fish2 = make_shared<FishBeta>(&aquarium);
	aquarium.Add(fish2);

	// Second fish should be created at 200, 200, since there
	// is not a fish there.
	ASSERT_NEAR(200, fish2->GetX(), 0.1);
	ASSERT_NEAR(200, fish2->GetY(), 0.1);

	shared_ptr<FishBeta> fish3 = make_shared<FishBeta>(&aquarium);
	aquarium.Add(fish3);

	// Since there are fish at (200, 200) and (210, 210),
	// this fish should have been created at (220, 220)
	ASSERT_NEAR(220, fish3->GetX(), 0.1);
	ASSERT_NEAR(220, fish3->GetY(), 0.1);
}

TEST(AquariumTest, NonoverlappingAdd2) {
	Aquarium aquarium;

	shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
	aquarium.Add(fish1);

	ASSERT_NEAR(200, fish1->GetX(), 0.1);
	ASSERT_NEAR(200, fish1->GetY(), 0.1);

	shared_ptr<FishBeta> fish2 = make_shared<FishBeta>(&aquarium);
	aquarium.Add(fish2);

	ASSERT_NEAR(210, fish2->GetX(), 0.1);
	ASSERT_NEAR(210, fish2->GetY(), 0.1);

	fish1->SetLocation(220, 220);
	// Fish are now at (220, 220), (210, 210)

	shared_ptr<FishBeta> fish3 = make_shared<FishBeta>(&aquarium);
	aquarium.Add(fish3);

	// Since nothing is at (200, 200), the fish should be created there
	ASSERT_NEAR(200, fish3->GetX(), 0.1);
	ASSERT_NEAR(200, fish3->GetY(), 0.1);

	fish2->SetLocation(230, 230);
	// Fish are now at (220, 220), (230, 230), (200, 200)

	shared_ptr<FishBeta> fish4 = make_shared<FishBeta>(&aquarium);
	aquarium.Add(fish4);

	// No fish at 210, 210, so should be created there.
	ASSERT_NEAR(210, fish4->GetX(), 0.1);
	ASSERT_NEAR(210, fish4->GetY(), 0.1);
}
