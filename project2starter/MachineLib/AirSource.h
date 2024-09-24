/**
 * @file AirSource.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_AIRSOURCE_H
#define CANADIANEXPERIENCE_MACHINELIB_AIRSOURCE_H

#include "AirSink.h"


class CardReader;
/** All the air sources for the machine */
class AirSource
{
private:
	/// Carder reader
	CardReader* mCardReader;
	/// The sink that is attached to the air sink
	AirSink* mSink;
	/// The speed amount of curve for tubing in
	int mSpeed;

public:
	/// Copy constructor (disabled)
	AirSource(const AirSource &) = delete;

	/// Assignment operator
	void operator=(const AirSource &) = delete;

	AirSource(){}

	void SetAirSource(CardReader *cardReader);

	void SendAir(double pressure);
	/**
	 * The air sink th
	 * @param sink The sink to be set
	 */
	void SetSink(AirSink* sink){mSink = sink;}
	/**
	 * Set the speed of the the curve
	 * @param speed The amount to curve the tubing
	 */
	void SetSpeed(int speed){mSpeed = speed;}
};

#endif //CANADIANEXPERIENCE_MACHINELIB_AIRSOURCE_H
