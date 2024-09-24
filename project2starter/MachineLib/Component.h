/**
 * @file Component.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
#define CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H


class  Machine;

/** Hold all the Component of the machine*/
class Component
{
private:
	/// The position of the component
	wxPoint mPosition = wxPoint(0,0);
	/// A pointer to the machine
	Machine* mMachine = nullptr;
public:
	void SetMachine(Machine* machine);

	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) = 0;

	/**
	 * Set the time for the component
	 * @param elapsed The new time
	 */
	virtual void UpdateTime(double elapsed) = 0;

	/**
	 * Get the x Location of the machine
	 * @return The x location of the machine
	 */
	int GetX() const{return mPosition.x;}
	/**
	 * Get the y Location of the machine
	 * @return The y  location of the machine
	 */
	int GetY() const{return mPosition.y;}

	/**
	 * Sets the location to the machine
	 * @param location The location to the machine
	 */
	void SetPosition(wxPoint location){mPosition = location;}

};

#endif //CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
