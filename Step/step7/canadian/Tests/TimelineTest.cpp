/**
 * @file TimelineTest.cpp
 * @author Auden Garrard
 */
#include <pch.h>
#include "gtest/gtest.h"
#include <Timeline.h>
#include <AnimChannelAngle.h>

TEST(TimeLineTest,FramRateGetterAndSetter)
{
	Timeline timeline;

	//Default value
	ASSERT_NEAR(30,timeline.GetFrameRate(),.001);

	//Check the setter
	timeline.SetFrameRate(40);

	// Check to make sure it update corrert
	ASSERT_NEAR(40,timeline.GetFrameRate(),.001);
}

TEST(TimelineTest,NumFramGetterAndSetter)
{
	Timeline timeline;

	// Default value
	ASSERT_NEAR(300, timeline.GetNumFrames(),.001);

	// Change the value
	timeline.SetNumFrames(400);

	// Check to make sure the Frames get updated
	ASSERT_NEAR(400, timeline.GetNumFrames(),.001);
}

TEST(Timeline,CurrentTimeGetterAndSetter)
{
	Timeline timeline;

	// Default value
	ASSERT_NEAR(0, timeline.GetCurrentTime(),.001);

	// Change the value
	timeline.SetCurrentTime(43.3);

	// Check to make sure the Frames get updated
	ASSERT_NEAR(43.3, timeline.GetCurrentTime(),.001);
}

TEST(TimelineTest, GetDuration)
{
	Timeline timeline;

	// Default value
	ASSERT_NEAR(10, timeline.GetDuration(), 0.0001);

	// Changed duration
	timeline.SetFrameRate(375);
	ASSERT_NEAR(300.0 / 375.0, timeline.GetDuration(), 0.0001);

	timeline.SetNumFrames(789);
	ASSERT_NEAR(789.0 / 375.0, timeline.GetDuration(), 0.0001);
}

TEST(TimelineTest, GetCurrentFrame)
{
	Timeline timeline;

	// Default value
	ASSERT_EQ(0, timeline.GetCurrentFrame());

	// Changed time
	timeline.SetCurrentTime(9.27);
	ASSERT_EQ(278, timeline.GetCurrentFrame());
}

TEST(TimelineTest, Add)
{
	Timeline timeline;
	AnimChannelAngle channel;

	timeline.AddChannel(&channel);
	ASSERT_EQ(&timeline, channel.GetTimeline());
}