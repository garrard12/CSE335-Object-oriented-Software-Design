/**
 * @file Drawable.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_DRAWABLE_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_DRAWABLE_H


class Actor;

/**
 * Abstract base class for drawable elements of our picture.
 *
 * A drawable is one part of an actor. Drawable parts can be moved
 * independently.
 */
class Drawable
{
private:

	/// The position of this drawable relative to its parent
	wxPoint mPosition = wxPoint(0,0);

	/// The drawable name
	std::wstring mName;

	/// The rotation of this drawable relative to its parent
	double mRotation = 0;

	/// The actor using this drawable
	Actor *mActor = nullptr;

	/// All the Drawables Children
	std::vector<std::shared_ptr<Drawable>> mChildren;

	/// The Drawable item
	Drawable* mParent = nullptr;

protected:
	/// The actual position in the drawing
	wxPoint mPlacedPosition = wxPoint(0,0);

	/// The actual rotation in the drawing
	double mPlacedR = 0;

	Drawable(std::wstring const &name);

	wxPoint RotatePoint(wxPoint point, double angle);

public:
	/// Default constructor (disabled)
	Drawable() = delete;
	
	/// Copy constructor (disabled)
	Drawable(const Drawable &) = delete;
	
	/// Assignment operator
	void operator=(const Drawable &) = delete;
	/// Destructor
	virtual ~Drawable(){};

	void SetActor(Actor* actor);

	void Place(wxPoint offset, double rotate);

	void AddChild(std::shared_ptr<Drawable> child);

	void Move(wxPoint delta);

	/**
	* Draw this drawable
	* @param gc Graphics object to draw on
	*/
	virtual void Draw(std::shared_ptr<wxGraphicsContext> gc) = 0;
	/**
     * Test to see if we have been clicked on by the mouse
     * @param point Position to test
     * @return true if clicked on
     */
	virtual bool HitTest(wxPoint point) = 0;
	/**
     * Is this a movable drawable?
     * @return true if movable
     */
	virtual bool IsMovable(){return false;};

	/**
     * Set the drawable position
     * @param pos The new drawable position
     */
	void SetPosition(wxPoint pos) { mPosition = pos; }

	/**
	 * Get the drawable position
	 * @return The drawable position
	 */
	wxPoint GetPosition() const { return mPosition; }

	/**
	 * Set the rotation angle in radians
	* @param r The new rotation angle in radians
	 */
	void SetRotation(double r) { mRotation = r; }

	/**
	 * Get the rotation angle in radians
	 * @return The rotation angle in radians
	 */
	double GetRotation() const { return mRotation; }

	/**
	 * Get the drawable name
	 * @return The drawable name
	 */
	std::wstring GetName() const { return mName; }

	/**
	 * Get Drawable item
	 * @return The time being drawan
	 */
	Drawable* GetParent() const {return mParent;}

	/**
	 * The item to draw
	 * @param drawable The image being drawn
	 */
	 void SetChild(Drawable* drawable){mParent = drawable;}
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_DRAWABLE_H
