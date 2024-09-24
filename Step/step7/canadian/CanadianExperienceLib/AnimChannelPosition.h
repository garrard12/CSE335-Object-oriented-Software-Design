/**
 * @file AnimChannelPosition.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ANIMCHANNELPOSITION_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ANIMCHANNELPOSITION_H

#include "AnimChannel.h"

/** Class for moving the Actor*/
class AnimChannelPosition : public AnimChannel
{
private:
	/// The location they are at
	wxPoint mPosition = wxPoint(0,0);

protected:
	/** Set the Key frame for the position */
	class KeyframePosition: public Keyframe
	{
	private:
		/// The positions
		wxPoint mPosition = wxPoint(0,0);
		/// The channel this keyframe is associated with
		AnimChannelPosition* mChannel;
	public:
		/// Default constructor (disabled)
		KeyframePosition() = delete;

		/// Copy constructor (disabled)
		KeyframePosition(const KeyframePosition &) = delete;

		/// Assignment operator
		void operator=(const KeyframePosition &) = delete;

		/**
		 * Constructor
		 * @param channel The we working with
		 * @param position The position of the Actor
		 */
		 KeyframePosition(AnimChannelPosition* channel,wxPoint position) :
		 	Keyframe(channel),mChannel(channel),mPosition(position){};

		/// Use this keyframe as keyframe 1
		void UseAs1() override { mChannel->mKeyframe1 = this; }

		/// Use this keyframe as keyframe 2
		void UseAs2() override { mChannel->mKeyframe2 = this; }

		/// Use this keyframe as the angle
		void UseOnly() override { mChannel->mPosition = mPosition; }

		 /**
		  * Get the position
		  * @return the position
		  */
		 wxPoint GetPosition() const {return mPosition;}
	};

private:
	/// The first angle keyframe
	KeyframePosition *mKeyframe1 = nullptr;

	/// The second angle keyframe
	KeyframePosition *mKeyframe2 = nullptr;

protected:
	void Tween(double t);
public:

	AnimChannelPosition(){}

	/// Copy constructor (disabled)
	AnimChannelPosition(const AnimChannelPosition &) = delete;

	/// Assignment operator
	void operator=(const AnimChannelPosition &) = delete;

	virtual ~AnimChannelPosition(){}
	/**
	 * Gets the position of the
	 * @return The position of the key frame
	 */
	wxPoint GetPosition() const{return mPosition;}

 	void SetKeyframe(wxPoint position);

	void DeleteKeyframe(wxPoint position);
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ANIMCHANNELPOSITION_H
