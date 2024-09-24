/**
 * @file Cylinder.cpp
 * @author Auden Garrard
 */
#include "pch.h"
#include "Cylinder.h"
#include "StruckInstrument.h"

/// Cylinder base image
const std::wstring CylinderBaseImage = L"/images/cylinder-base.png";

/// Cylinder body image
const std::wstring CylinderBodyImage = L"/images/cylinder.png";

/// Cylinder ram image
const std::wstring CylinderRamImage = L"/images/cylinder-ram.png";

/// The maximum pixels to move the cylinder ram when enabled
const int CylinderMaxExtent = 44;

/// Angle from bottom center of the cylinder to the tubing connector
const double ConnectorAngle = -0.17;

/// Distance from bottom center of the cylinder to the tubing connector
const double ConnectorDistance = 24.5;

/**
 * Constructor
 * @param resourcesDir The resources directory
 */
Cylinder::Cylinder(std::wstring resourcesDir) : mResourcesDir(resourcesDir), mSink(this)
{

	mMount.SetImage(mResourcesDir + CylinderBaseImage);
	mMount.Rectangle(-mMount.GetImageWidth() / 2, 0);

	mCylinder.SetImage(mResourcesDir + CylinderBodyImage);
	mCylinder.Rectangle(-mCylinder.GetImageWidth() / 2, 0);

	mRam.SetImage(mResourcesDir + CylinderRamImage);
	mRam.Rectangle(-mCylinder.GetImageWidth() / 2, 0);
}
/**
 * Draws the cylinder
 * @param graphics The graphic to draw
 * @param x The x location in the machine
 * @param y The y location in the machine
 */
void Cylinder::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
	x += GetX();
	y += GetY();
	//
	// I think this does something with tubing
	//
	double airX = GetX() + cos(ConnectorAngle * M_PI * 2) * ConnectorDistance;
	double airY = GetY() + sin(ConnectorAngle * M_PI * 2) * ConnectorDistance;

	//
	// Cacl the rotation
	//
	double xRotation  = (CylinderMaxExtent * mMaxExtent) * sin(mRotation * M_PI * 2);
	double yRotation = (CylinderMaxExtent * -mMaxExtent) * cos(mRotation * M_PI * 2);

	//
	// Should the ram be extended
	//
	if(mExtended == false)
	{
		mRam.DrawPolygon(graphics,x,y);
		mCylinder.DrawPolygon(graphics,x,y);
		mMount.DrawPolygon(graphics,x,y);
	}
	else
	{
		// To extend the ram
		mRam.DrawPolygon(graphics,x + xRotation,y + yRotation);
		mCylinder.DrawPolygon(graphics,x,y);
		mMount.DrawPolygon(graphics,x,y);
		//mExtended = false;
	}
}
/**
 * Did it receiver aid
 * @param air The pressure of air
 * @param speed The amount the tube should bend
 */
void Cylinder::ReceiverAir(double air, int speed)
{
	//
	// Checks to makes sure the sound playing correct
	if(air > 0 && mPlaySound == 0)
	{
		mStruckInstrument->PlayMusic();
	}
	// Should the ram be extended
	if(air > .5)
	{
		mExtended = true;
	}else
	{
		mExtended = false;
	}
	mPlaySound = air;
}
/**
 * The time that need to be updated
 * @param elapsed The time in the programe
 */
void Cylinder::UpdateTime(double elapsed)
{

}
/**
 * Rotates the cylinder
 * @param rotation The amount that need to be rotated
 */
void Cylinder::SetRotation(double rotation)
{
	mRotation = rotation;
	mMount.SetRotation(rotation);
	mCylinder.SetRotation(rotation);
	mRam.SetRotation(rotation);
}
/**
 * Makes the connection between struckIntruemnt and Cylinder
 * @param struckInstrument The instrument to
 */
void Cylinder::SetMotionSink(std::shared_ptr<StruckInstrument> struckInstrument)
{
	mStruckInstrument = struckInstrument;
	mStruckInstrument->CylinderConnection(this);
}
