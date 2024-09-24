/**
 * @file PictureObserver.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTUREOBSERVER_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTUREOBSERVER_H
class Picture;


/**
* Observer base class for a picture.
*
* This class implements the base class functionality for
* an observer in the observer pattern.
*/
class PictureObserver
{
private:
	/// Picture we are observing
	std::shared_ptr<Picture> mPicture;

protected:
	/// Constructor
	PictureObserver() {}
public:

	/// Copy Constructor (Disabled)
	PictureObserver(const PictureObserver &) = delete;
	/// Assignment Operator (Disabled)
	void operator=(const PictureObserver &) = delete;

	virtual ~PictureObserver();

	/// This function is called to update any observers
	virtual void UpdateObserver() = 0;

	/**
	 * Get the picture
	 * @return Get picture being observing
	 */
	std::shared_ptr<Picture> GetPicture(){return mPicture;}

	void SetPicture(std::shared_ptr<Picture> picture);

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTUREOBSERVER_H
