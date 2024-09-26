/**
 * @file PictureTest.cpp
 * @author Auden Garrard
 */
#include <pch.h>
#include "gtest/gtest.h"
#include <Picture.h>
#include <Actor.h>

using namespace std;

TEST(Picture,GetterAndSetter)
{
	Picture pic;
	auto answer = pic.GetSize();
	ASSERT_EQ(answer.GetHeight(),800);
	ASSERT_EQ(answer.GetWidth(),1500);

	pic.SetSize(wxSize(300,500));
	auto answer2 = pic.GetSize();
	ASSERT_EQ(answer2.GetHeight(),500);
	ASSERT_EQ(answer2.GetWidth(),300);
}

TEST(PictureTest, Iterator)
{
	Picture picture;

	auto iter1 = picture.begin();
	auto iter2 = picture.end();

	// Test to ensure an iterator on an empty picture works
	ASSERT_FALSE(iter1 != iter2);

	// Add some actors
	shared_ptr<Actor> actor1 = make_shared<Actor>(L"Bob");
	shared_ptr<Actor> actor2 = make_shared<Actor>(L"Ted");
	shared_ptr<Actor> actor3 = make_shared<Actor>(L"Carol");
	shared_ptr<Actor> actor4 = make_shared<Actor>(L"Alice");

	ASSERT_EQ(nullptr, actor1->GetPicture());

	picture.AddActor(actor1);
	picture.AddActor(actor2);
	picture.AddActor(actor3);
	picture.AddActor(actor4);

	// Test the associations
	ASSERT_TRUE(actor1->GetPicture() == &picture);
	ASSERT_TRUE(actor2->GetPicture() == &picture);
	ASSERT_TRUE(actor3->GetPicture() == &picture);
	ASSERT_TRUE(actor4->GetPicture() == &picture);

	iter1 = picture.begin();
	iter2 = picture.end();
	ASSERT_TRUE(iter1 != iter2); 
	ASSERT_TRUE(*iter1 == actor1);
	++iter1;
	ASSERT_TRUE(iter1 != iter2);
	ASSERT_TRUE(*iter1 == actor2);
	++iter1;
	ASSERT_TRUE(iter1 != iter2);
	ASSERT_TRUE(*iter1 == actor3);
	++iter1;
	ASSERT_TRUE(iter1 != iter2);
	ASSERT_TRUE(*iter1 == actor4);
	++iter1;

	// Ensure we are at the end
	ASSERT_FALSE(iter1 != iter2);
}
TEST(PictureTest, GetTimeline)
{
	Picture picture;

	Timeline *timeline = picture.GetTimeline();
	ASSERT_NE(nullptr, timeline);
}

