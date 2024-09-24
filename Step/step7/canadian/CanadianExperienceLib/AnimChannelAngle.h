/**
 * @file AnimChannelAngle.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ANIMCHANNELANGLE_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ANIMCHANNELANGLE_H

#include "AnimChannel.h"


/**
 * Animation channel for angles.
 */
class AnimChannelAngle : public AnimChannel
{
private:
	/// The angle of the channel
	double mAngle = 0;
protected:
	/** The angle that is being changed */
	class KeyFrameAngle : public Keyframe
	{
	private:
		/// The angle for rotation
		double mAngle = 0;
		/// The channel this keyframe is associated with
		AnimChannelAngle *mChannel;
	public:
		/// Default constructor (disabled)
		KeyFrameAngle() = delete;

		/// Copy constructor (disabled)
		KeyFrameAngle(const KeyFrameAngle &) = delete;

		/// Assignment operator
		void operator=(const KeyFrameAngle &) = delete;

		/// Use this keyframe as keyframe 1
		void UseAs1() override { mChannel->mKeyframe1 = this; }

		/// Use this keyframe as keyframe 2
		void UseAs2() override { mChannel->mKeyframe2 = this; }

		/// Use this keyframe as the angle
		void UseOnly() override { mChannel->mAngle = mAngle; }

		/**
         * Constructor
         * @param channel The channel we are for
         * @param angle The angle for the keyframe
         */
		KeyFrameAngle(AnimChannelAngle *channel, double angle) :
			Keyframe(channel), mChannel(channel), mAngle(angle) {}

		/**
		 * Get the Angle
		 * @return the angle
		 */
		double GetAngle(){return mAngle;}
	};
private:
	/// The first angle keyframe
	KeyFrameAngle *mKeyframe1 = nullptr;

	/// The second angle keyframe
	KeyFrameAngle *mKeyframe2 = nullptr;
protected:
	void Tween(double t) override;
public:

	AnimChannelAngle() {};

	/// Copy constructor (disabled)
	AnimChannelAngle(const AnimChannelAngle &) = delete;

	/// Assignment operator
	void operator=(const AnimChannelAngle &) = delete;

	virtual ~AnimChannelAngle() {}
	/**
	 * Get the angle
	 * @return The angle of the channel
	 */
	double GetAngle() const{return mAngle;}

	void SetKeyframe(double angle);

	void DeleteKeyframe();
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ANIMCHANNELANGLE_H
