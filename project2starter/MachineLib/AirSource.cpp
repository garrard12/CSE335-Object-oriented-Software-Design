/**
 * @file AirSource.cpp
 * @author Auden Garrard
 */
#include "pch.h"
#include "AirSource.h"
#include "AirSink.h"

/**
 * Set the connection between the air source athe the card reader
 * @param cardReader The card reader to set
 */
void AirSource::SetAirSource(CardReader *cardReader)
{
	mCardReader = cardReader;
}
/**
 * Set the pressure to the component
 * @param pressure The pressure to be set
 */
void AirSource::SendAir(double pressure)
{
	//Make sure it a valid sink being sink
	if(mSink != nullptr){
		mSink->SetPressure(pressure,mSpeed);
	}
}
