/**
 * @file AnimChannelPosition.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "AnimChannelPosition.h"

/**
 * Set a keyframe
 *
 * This function allocates a new keyframe and sends it to
 * AnimChannel, which will insert it into the collection of keyframes.
 * @param position Position for the keyframe.
 */
void AnimChannelPosition::SetKeyframe(wxPoint position )
{
	// Create a keyframe of the appropriate type
	// Telling it this channel and the angle
	auto keyframe = std::make_shared<KeyframePosition>(this, position);

	// Insert it into the collection
	InsertKeyframe(keyframe);
}
/**
 * Delete the key frame
 * @param position Position for the key frame
 */
void AnimChannelPosition::DeleteKeyframe(wxPoint position)
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
void AnimChannelPosition::Tween(double t)
{
	wxPoint v1 = mKeyframe1->GetPosition();
	wxPoint v2 = mKeyframe2->GetPosition();

	int x = int(v1.x + t  * (v2.x - v1.x));
	int y = int(v1.y + t * (v2.y - v1.y));


	mPosition = wxPoint(x, y);
}
