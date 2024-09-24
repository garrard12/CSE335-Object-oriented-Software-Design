/**
 * @file Fish.h
 * @author Auden Garrard
 *
 * Sets up the base class for Fish
 */



#ifndef AQUARIUM_AQUARIUMLIB_FISH_H
#define AQUARIUM_AQUARIUMLIB_FISH_H

#include "Item.h"

/**
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */
class Fish : public Item
{
private:
	/// Fish speed in the X direction
	/// in pixels per second
	double mSpeedX;

	/// Fish speed in the Y direction
	/// in pixels per second
	double mSpeedY;

protected:
	Fish(Aquarium *aquarium, const std::wstring &filename);

public:
	/// Default constructor (disabled)
	Fish() = delete;
	
	/// Copy constructor (disabled)
	Fish(const Fish &) = delete;
	
	/// Assignment operator
	void operator=(const Fish &) = delete;
	
	void Update(double elapsed) override;
	/**
	 * Getter for the X speed of the fish
	 * @return the X speed of the fish
	 */
	double GetXSpeed() const{return mSpeedX;}

	/**
	 * Getter for the Y speed of the fish
	 * @return the Y speed of the fish
	 */
	double GetYSpeed() const{return mSpeedY;}
	/**
	 * Sets the Y speed
	 * @param newSpeed the new  Y speed
	 */
	void SetYSpeed(double newSpeed) {mSpeedY = newSpeed;}

	/**
	 * Sets the X speed
	 * @param newSpeed the X speed
	 */
	 void SetXSpeed(double  newSpeed){mSpeedX = newSpeed;}

	/**
	 * Make each fish behavior different
	 */
	virtual void makeFishDifferent(){}

};

#endif //AQUARIUM_AQUARIUMLIB_FISH_H
