/**
 * @file AnimChannel.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ANIMCHANNEL_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ANIMCHANNEL_H

class Timeline;

/**
 * Base class for animation channels
 *
 * This class provides basic functionality and a polymorphic
 * representation for animation channels.
 */
class AnimChannel
{
private:
	/// The name for the key frame
	std::wstring mName;
	/// First Key frame
	int mKeyframe1 = -1;
	/// Second Key frame
	int mKeyframe2 = -1;
	/// The timeline object
	Timeline *mTimeline = nullptr;
protected:
	/// Default constructor
	AnimChannel() {}

	/// Class that represents a keyframe
	class Keyframe
	{
	private:
		/// The frame
		int mFrame = 0;
		/// The channel this keyframe is associated with
		AnimChannel *mChannel;
	protected:
		/**
		 * Constructor
		 * @param channel Channel we are associated with
		 */
		Keyframe(AnimChannel *channel) : mChannel(channel) {}
	public:
		/// Default constructor (disabled)
		Keyframe() = delete;

		/// Copy constructor (disabled)
		Keyframe(const Keyframe &) = delete;

		/// Assignment operator
		void operator=(const Keyframe &) = delete;

		/// Use this keyframe as keyframe 1
		virtual void UseAs1() {}

		/// Use this keyframe as keyframe 2
		virtual void UseAs2() {}

		/// Use this keyframe as the angle
		virtual void UseOnly() {}

		/**
		 * Get frame
		 * @return The frame
		 */
		int GetFrame(){return mFrame;}
		/**
		 * Set the frame
		 * @param frame The frame wanted
		 */
		void SetFrame(int frame){mFrame = frame;}
	};

	void InsertKeyframe(std::shared_ptr<Keyframe> keyframe);

	void RemoveKeyframe();
	/**
	 * make the animation run smoothly
	 * @param t The t value
	 */
	virtual void Tween(double t) = 0;
private:
	/// The collection of keyframes for this channel
	std::vector<std::shared_ptr<Keyframe>> mKeyframes;
public:
	/// Copy constructor (disabled)
	AnimChannel(const AnimChannel &) = delete;

	/// Assignment operator
	void operator=(const AnimChannel &) = delete;

	virtual ~AnimChannel(){}

	bool IsValid();
	void SetFrame(int currFrame);

	/**
	 * Get the name
	 * @return Grabs the name
	 */
	std::wstring GetName()const{return mName;}
	/**
	 * Set the name
	 * @param name sets the name
	 */
	void SetName(std::wstring name){mName = name;}
	/**
	 * Get the timeline on
	 * @return Get the point to timeline
	 */
	Timeline* GetTimeline() const{return mTimeline;}
	/**
	 * Set the time line
	 * @param timeline The timeline
	 */
	void SetTimeline(Timeline* timeline){mTimeline = timeline;}
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ANIMCHANNEL_H
