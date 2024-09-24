/**
 * @file Item.h
 * @author Auden Garrard
 *
 * Base class for any item in our aquarium.
 */

#ifndef AQUARIUM__ITEM_H
#define AQUARIUM__ITEM_H

/**
 * Set the location of the items on to the screen
 */
class Aquarium;
class Item
{
private:
	/// The aquarium this item is contanined in
	Aquarium *mAquarium;

	/// X location for the center of the item
	double mX = 0;
	/// Y location for the center of the item
	double mY = 0;

public:
	virtual ~Item();

	 /// Default constructor (disabled)
	 Item() = delete;

	 /// Copy constructor (disabled)
	 Item(const Item &) = delete;

	 /// Assignment operator
	 void operator=(const Item &) = delete;

	/**
	 * The X location of the item
	 * @return X location in pixels
	 */
	 double GetX() const {return mX;}

	 /**
	  * The Y location of the item
	  * @return Y location in pixels
	  */
	 double  GetY() const {return mY;}

	 /**
	  * Set the item location
	  * @param X location in pixels
	  * @param Y location in pixels
	  */
	 void SetLocation(double x, double y){mX = x; mY = y;}
protected:
	Item(Aquarium *aquarium);
};

#endif //AQUARIUM__ITEM_H
