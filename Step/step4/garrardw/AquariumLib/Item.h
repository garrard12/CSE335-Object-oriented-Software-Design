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

	/// The underlying Item Image
	std::unique_ptr<wxImage> mItemImage;

	/// True mirrors the item image
	bool mMirror = false;

	/// The bitmap we can display for this Item
	std::unique_ptr<wxBitmap> mItemBitmap;

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
	* Get the pointer to the Aquarium object
	* @return Pointer to Aquarium object
	*/
	Aquarium *GetAquarium() { return mAquarium;}

	/**
	 * Get The width of the item
	 * @return return the width of the item
	 */
	 int GetWidth() const { return mItemBitmap->GetWidth(); }

	/**
	* Get the height of the item
	* @return return the height of the item
	*/
	 int GetHeight() const{return mItemBitmap->GetHeight();}

	 /**
	  * Set the item location
	  * @param x location in pixels
	  * @param y location in pixels
	  */
	 void SetLocation(double x, double y){mX = x; mY = y;}


	  void Draw(wxDC *dc);

	  bool HitTest(int x, int y);

	  /**
	   * Test this item to see if it has been double clicked on
	   * @param item an Item from the aquarium
	   */
	  virtual void DoubleClickTest(std::shared_ptr<Item> item) {}

	  virtual wxXmlNode* XmlSave(wxXmlNode *node);

	  virtual void XmlLoad(wxXmlNode *node);

	  /**
	   * Handle updates for animation
	   * @param elapsed The time since the last update
	   */
	  virtual void Update(double elapsed) {}

	  double DistanceTo(std::shared_ptr<Item> item);

	  void SetMirror(bool m);


protected:
	Item(Aquarium *aquarium,const std::wstring &filename);
};

#endif //AQUARIUM__ITEM_H
