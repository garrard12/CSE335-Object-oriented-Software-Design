/**
 * @file AirAccepter.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_AIRACCEPTER_H
#define CANADIANEXPERIENCE_MACHINELIB_AIRACCEPTER_H
/**
 * The Air Sink class
 */
class AirSink;
/**
 * Interface class for receiving the air
 */
class AirAccepter
{
private:

public:
	/**
	 * Virtual Function that let
	 * @param air the pressure being sent
	 * @param speed The amount the tube should bend
	 */
	virtual void ReceiverAir(double air, int speed) = 0;

};

#endif //CANADIANEXPERIENCE_MACHINELIB_AIRACCEPTER_H
