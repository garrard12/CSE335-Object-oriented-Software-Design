/**
 * @file AnimChannelAngleTest.cpp
 * @author Auden Garrard
 */
#include <pch.h>
#include "gtest/gtest.h"

#include <AnimChannelAngle.h>

using namespace std;


TEST(AnimChannelAngleTest,NameGetterAndSetter)
{
	AnimChannelAngle a;

	// Check the Getter
	ASSERT_EQ(a.GetName(), L"");

	// Check the Setter
	a.SetName(L"bib");
	ASSERT_EQ(a.GetName(), L"bib");

}