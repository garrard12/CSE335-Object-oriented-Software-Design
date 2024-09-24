/**
 * @file Picture.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTURE_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTURE_H


class PictureObserver;
class Actor;
/**
 * The picture we are drawing.
 *
 * There will be one picture object that contains all of
 * our actors, which then contains the drawables.
 */
class Picture
{
private:

	/// The picture size
	wxSize mSize = wxSize(1500, 800);

	/// The observers of this picture
	std::vector<PictureObserver *> mObservers;

	/// The Actor in oder of drawing
	std::vector<std::shared_ptr<Actor>> mActors;

public:

	/// Copy constructor (disabled)
	Picture(const Picture &) = delete;

	/// Assignment operator
	void operator=(const Picture &) = delete;

	/**
	 * Constructor
	 */
	 Picture(){}

	/**
	* Get the picture size
	* @return Picture size in pixels
	*/
	wxSize GetSize() {return mSize;}

	/**
	 * Set the picture size
	 * @param size Picture size in pixels
	 */
	void SetSize(wxSize size) {mSize = size;}

	void AddObserver(PictureObserver *observer);
	void RemoveObserver(PictureObserver *observer);
	void UpdateObservers();
	void Draw(std::shared_ptr<wxGraphicsContext> graphics);
	void AddActor(std::shared_ptr<Actor> actor);

	/** Iterator that iterates over some collection */
	class Iter
	{
	public:
		/**
		 * Constructor
		 * @param picture the collection we are iterating over
		 * @param pos Where in the collection at
		 */
		Iter(Picture *picture, int pos) : mPicture(picture), mPos(pos) {}

		/**
		 * Compare two iterators
		 * @param other The other iterator we are comparing to
		 * @return  true if this position is not equal to the other position
		*/
		bool operator!=(const Iter &other) const
		{
			return mPos != other.mPos;
		}

		/**
		 * Get value at current position
		 * @return Value at mPos in the collection
		 */
		std::shared_ptr<Actor> operator *() const { return mPicture->mActors[mPos]; }

		/**
		 * Increment the iterator, moving to the next item in the collection
		 * @return Reference to this iterator
		 */
		const Iter& operator++()
		{
			mPos++;
			return *this;
		}


	private:
		Picture* mPicture;    ///< Collection we are iterating over
		int mPos;                  ///< Position in the collection
	};

		/**
	 * Get an iterator for the beginning of the collection
	 * @return Iter object at position 0
	 */
	Iter begin() { return Iter(this, 0); }

	/**
	 * Get an iterator for the end of the collection
	 * @return Iter object at position past the end
	 */
	Iter end() { return Iter(this, mActors.size()); }

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTURE_H
