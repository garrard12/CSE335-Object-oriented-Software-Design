/**
 * @file Actor.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ACTOR_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ACTOR_H

#include <string>

class Drawable;
class Picture;
/**
 * Class for actors in our drawings.
 *
 * An actor is some graphical object that consists of
 * one or more parts. Actors can be animated.
 */
class Actor
{
private:
	/// The actor name
	std::wstring mName;

	/// Is this actor enabled (drawable?)
	bool mEnabled = true;

	/// The actor position
	wxPoint mPosition = wxPoint(0, 0);

	/// Is this actor mouse clickable
	bool mClickable = true;

	/// The root drawable
	std::shared_ptr<Drawable> mRoot;

	/// The drawables in drawing order
	std::vector<std::shared_ptr<Drawable>> mDrawablesInOrder;

	/// The Picture To draw
	Picture* mPicture = nullptr;

public:
	/// Default constructor (disabled)
	Actor() = delete;
	
	/// Copy constructor (disabled)
	Actor(const Actor &) = delete;
	
	/// Assignment operator
	void operator=(const Actor &) = delete;
	/// Destructor
	virtual ~Actor(){};

	Actor(const std::wstring &name);

	void SetRoot(std::shared_ptr<Drawable> root);
	void Draw(std::shared_ptr<wxGraphicsContext> gc);
	std::shared_ptr<Drawable> HitTest(wxPoint pos);
	void AddDrawable(std::shared_ptr<Drawable> drawable);
	void SetPicture(Picture* picture);

	/**
	 * Grabs the pointer to the pic
	 * @return Get the pointer to Picture
	 */
	Picture* GetPicture() const{return mPicture; }

	/**
   * Get the actor name
   * @return Actor name
   */
	std::wstring GetName() const {return mName;}
	/**
     * The actor position
     * @return The actor position as a point
     */
	wxPoint GetPosition(){return mPosition;}
	/**
     * The actor position
     * @param position The new actor position
     */
	void SetPosition(wxPoint position){mPosition = position;}
	/**
     * Actor is enabled
     * @return enabled status
     */
	bool IsEnable() const {return mEnabled;}

	/**
     * Set Actor Enabled
     * @param enable New enabled status
     */
	void SetEnable(bool enable){mEnabled = enable;}

	/**
     * Actor is clickable
     * @return true if actor is clickable
     */
	bool IsClickable() const { return mClickable; }

	/**
	 * Actor clickable
	 * @param clickable New clickable status
	 */
	void SetClickable(bool clickable) { mClickable = clickable; }
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ACTOR_H
