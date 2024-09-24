/**
 * @file Tubing.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "Tubing.h"

/**
 * Constructor
 */
Tubing::Tubing() : mAirSink(this)
{

}
/**
 * Updates the time image for tubing
 * @param elapsed The time that passed
 */
void Tubing::UpdateTime(double elapsed)
{

}
/**
 * Draws the tubing
 * @param graphics The graphic that need to be drawn
 * @param x the x location
 * @param y The y locaion
 */
void Tubing::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
	auto path = graphics->CreatePath();
	path.MoveToPoint(0,15);
	//path.AddCurveToPoint((14.4,14.4),(14.4,14.4),14.4,14.4);
	graphics->StrokePath(path);
}
/**
 * Did the tubing receive the air
 * @param air The air pressure
 * @param speed The amount the tube should bend
 * */
void Tubing::ReceiverAir(double air, int speed)
{
	mAirSource.SendAir(air);
	mSpeed = speed;
}
