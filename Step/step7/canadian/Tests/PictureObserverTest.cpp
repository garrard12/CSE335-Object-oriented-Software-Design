/**
 * @file PictureObserverTest.cpp
 * @author Auden Garrard
 *
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <PictureObserver.h>
#include <Picture.h>

using namespace std;

// Since the class is abstract the class needs to be mock
class PictureObserverMock : public PictureObserver
{
public:
	//
	// member variables
	//

	bool mUpdated = false;

	//
	// Functions
	//

	PictureObserverMock() : PictureObserver() {}
	virtual void UpdateObserver() override {mUpdated = true;}
	void UpdateObserverFalse() {mUpdated = false;}
};

TEST(PictureObserverTest, Construct) {
	PictureObserverMock observer;
}


TEST(PictureObserverTest, OneObserver) {
	// Allocate a Picture object
	auto picture = std::make_shared<Picture>();

	// Create a mock observer object
	PictureObserverMock observer;

	// And set it for the observer:
	observer.SetPicture(picture);

	picture->UpdateObservers();

	ASSERT_TRUE(observer.mUpdated);
}


TEST(PictureObserverTest, TwoObserver) {
	// Allocate a Picture object
	auto picture = std::make_shared<Picture>();

	// Create a mock observer object
	PictureObserverMock observerOne;
	PictureObserverMock observerTwo;

	// And set it for the observer:
	observerOne.SetPicture(picture);
	observerTwo.SetPicture(picture);

	//Make sure they aren't updated
	ASSERT_FALSE(observerOne.mUpdated);
	ASSERT_FALSE(observerTwo.mUpdated);

	picture->UpdateObservers();

	// Check to make sure that Update it being called
	// on all the observers
	ASSERT_TRUE(observerOne.mUpdated);
	ASSERT_TRUE(observerTwo.mUpdated);
}

TEST(PictureObserver,Getter)
{
	// Allocate a Picture object
	auto picture = std::make_shared<Picture>();

	// Create a mock observer object
	PictureObserverMock observer;

	// And set it for the observer:
	observer.SetPicture(picture);

	std::shared_ptr<Picture> answer;

	answer = observer.GetPicture();

	// Check to make sure it grab the picture
	ASSERT_EQ(answer,picture);

}

TEST(PictureObserver,CreatAndDestroy)
{
	vector<PictureObserverMock> allObserver;

	// Allocate a Picture object
	auto picture = std::make_shared<Picture>();

	// Create a mock observer object
	PictureObserverMock observerOne;

	// And set it for the observer:
	observerOne.SetPicture(picture);

	picture->UpdateObservers();

	ASSERT_TRUE(observerOne.mUpdated);
	observerOne.UpdateObserverFalse();

	//
	// Creating and destroy an Observer
	// Will get error if does not automatically destroy itself
	//
	{
		PictureObserverMock observerTwo;

		// And set it for the observer:
		observerTwo.SetPicture(picture);

		picture->UpdateObservers();

		ASSERT_TRUE(observerTwo.mUpdated);
		// Turn them back to false
		observerTwo.UpdateObserverFalse();
		observerOne.UpdateObserverFalse();
	}

	picture->UpdateObservers();

	ASSERT_TRUE(observerOne.mUpdated);
}
