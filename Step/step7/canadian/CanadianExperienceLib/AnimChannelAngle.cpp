/**
 * @file AnimChannelAngle.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "AnimChannelAngle.h"

/**
 * Set a keyframe
 *
 * This function allocates a new keyframe and sends it to
 * AnimChannel, which will insert it into the collection of keyframes.
 * @param angle Angle for the keyframe.
 */
void AnimChannelAngle::SetKeyframe(double angle)
{
	// Create a keyframe of the appropriate type
	// Telling it this channel and the angle
	auto keyframe = std::make_shared<KeyFrameAngle>(this, angle);

	// Insert it into the collection
	InsertKeyframe(keyframe);
}
/**
 * Delete the keyframe
 */
void AnimChannelAngle::DeleteKeyframe()
{
	RemoveKeyframe();
}
/**
 * Compute an angle that is an interpolation
 * between two keyframes
 *
 * This function is called after Use1 and Use2,
 * so we have pointers to valid keyframes of the
 * type KeyframeAngle. This function computes the
 * tweening.
 *
 * @param t A t value. t=0 means keyframe1, t=1 means keyframe2.
 * Other values interpolate between.
 */
void AnimChannelAngle::Tween(double t)
{
	mAngle = mKeyframe1->GetAngle() * (1 - t) +
		mKeyframe2->GetAngle() * t;
}


