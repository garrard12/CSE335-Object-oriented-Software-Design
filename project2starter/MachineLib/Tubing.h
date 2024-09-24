/**
 * @file Tubing.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_TUBING_H
#define CANADIANEXPERIENCE_MACHINELIB_TUBING_H
#include "Component.h"
#include "AirAccepter.h"
#include "AirSink.h"
#include "AirSource.h"
/**
 * The tubing class
 */
class Tubing : public Component, public AirAccepter
{
private:
	/// The air sink
	AirSink mAirSink;
	/// The air source for the tubing
	AirSource mAirSource;
	/// The curve to the tub
	int mSpeed = 0;
public:
	Tubing();

	virtual void UpdateTime(double elapsed) override;

	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

	virtual void ReceiverAir(double air, int speed) override;

	/**
	 * Get the air sink
	 * @return The air sink
	 */
	AirSink* GetSink(){return &mAirSink;}

	/**
	 * Gets the tubing
	 * @return The tubing
	 */
	AirSource* GetSource(){return &mAirSource;}
	/**
	 * Set the soucres of the tubing
	 * @param speed The amount you want the cu
	 */
	void SetSpeed(int speed){mSpeed = speed;}
};

#endif //CANADIANEXPERIENCE_MACHINELIB_TUBING_H
