/**
 * @file Item.h
 * @author Auden Garrard
 *
 * Base class for any item in our aquarium.
 */

#ifndef AQUARIUM__ITEM_H
#define AQUARIUM__ITEM_H


class Aquarium;

/**
 * Base class for any item in our aquarium.
 */
class Item
{
private:
	/// The aquarium this item is contained in
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
	  * The aquarium items
	  * @return aquarium items
	 */
	 Aquarium *GetAquarium() const {return mAquarium;}

	 /**
	  * Set the item location
	  * @param x location in pixels
	  * @param y location in pixels
	  */
	 void SetLocation(double x, double y){mX = x; mY = y;}

	  /**
	  * Draw this item
	  * @param dc Device context to draw on
	  */
	  virtual void Draw(wxDC *dc) = 0;

	  /**
	   * Test this item to see if it has been clicked on
	   * @param x X location on the aquarium to test in pixels
	   * @param y Y location on the aquarium to test in pixels
	   * @return true if clicked on
	   */
	  virtual bool HitTest(int x, int y) = 0;

	  /**
	   * Test this item to see if it has been double clicked on
	   * @param item an Item from the aquarium
	   */
	  virtual void DoubleClickTest(std::shared_ptr<Item> item) {}

	  double DistanceTo(std::shared_ptr<Item> item);

protected:
	Item(Aquarium *aquarium);
};

#endif //AQUARIUM__ITEM_H
