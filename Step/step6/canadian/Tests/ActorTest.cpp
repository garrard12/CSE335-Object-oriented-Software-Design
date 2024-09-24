/**
 * @file ActorTest.cpp
 * @author Auden Garrard
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <Actor.h>

TEST(ActorTest, Constructor)
{
	Actor actor(L"Harold");
	ASSERT_EQ(std::wstring(L"Harold"), actor.GetName());
}

TEST(ActorTest,EnableGetterAndSetter)
{
	Actor actor(L"Harold");
	// Check the default
	ASSERT_TRUE(actor.IsEnable());
	// Update the value
	actor.SetEnable(false);
	// Check to make sure the value changed
	ASSERT_FALSE(actor.IsEnable());
}
TEST(ActorTest,ClickableGetterAndSetter)
{
	Actor actor(L"Harold");
	// Check the default
	ASSERT_TRUE(actor.IsClickable());
	// Update the value
	actor.SetClickable(false);
	// Check to make sure the value changed
	ASSERT_FALSE(actor.IsClickable());
}

TEST(ActorTest,PositionGetterAndSetter)
{
	Actor actor(L"Harold");
	// Check default
	ASSERT_EQ(actor.GetPosition(),wxPoint(0,0));
	// Update the value
	actor.SetPosition(wxPoint(50,50));
	// Check the new value
	ASSERT_EQ(actor.GetPosition(),wxPoint(50,50));
}

TEST(ActorTest,PictureGetter)
{

}

