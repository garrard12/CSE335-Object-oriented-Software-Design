/**
 * @file AirSink.cpp
 * @author Auden Garrard
 */
#include "pch.h"
#include "AirSink.h"
#include "Component.h"
#include "AirAccepter.h"
/**
 * Constructor
 * @param componet  THe Componet that is accepting the air
 */
AirSink::AirSink(AirAccepter *componet) : mComponet(componet) {}

/**
 * Set the air pressure for component
 * @param pressure The pressure to be sent
 * @param speed The amount the tube should bend
 */
void AirSink::SetPressure(double pressure,int speed )
{
	if(mComponet != nullptr)
	{
		mComponet->ReceiverAir(pressure, speed);
	}
}