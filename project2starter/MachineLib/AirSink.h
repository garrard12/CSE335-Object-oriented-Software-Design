/**
 * @file AirSink.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_AIRSINK_H
#define CANADIANEXPERIENCE_MACHINELIB_AIRSINK_H


class AirAccepter;
class AirSource;
class Component;
/** Air sink class */
class AirSink
{
private:
	/// The Component that is accepting the air
	AirAccepter* mComponet;

public:

	AirSink() = default;
	/// Copy constructor (disabled)
	AirSink(const AirSink &) = delete;

	/// Assignment operator
	void operator=(const AirSink &) = delete;

	AirSink(AirAccepter* componet);

	void SetPressure(double pressure, int speed);

	//void SetSink(){}

};

#endif //CANADIANEXPERIENCE_MACHINELIB_AIRSINK_H
