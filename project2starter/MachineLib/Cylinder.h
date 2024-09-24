/**
 * @file Cylinder.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_CYLINDER_H
#define CANADIANEXPERIENCE_MACHINELIB_CYLINDER_H
#include "AirAccepter.h"
#include "Component.h"
#include "Polygon.h"
#include "AirSink.h"
//#include "StruckInstrument.h"
class StruckInstrument;

/**
 * The Cylinder class
 */
class Cylinder : public AirAccepter, public Component
{
private:
	/// The Mount to the Cylinder
	cse335::Polygon mMount;
	/// The Cylinder
	cse335::Polygon mCylinder;
	/// The Ram that exteneds
	cse335::Polygon mRam;
	/// The max distance that is can extend
	double mMaxExtent = 1;
	/// Is it extend
	bool mExtended = false;
	/// The image resources directory  for
	std::wstring mResourcesDir;
	/// The sink that is attached to the cylinder
	AirSink mSink;
	/// The angle the images should be rotated
	double mRotation = 0;
	/// Should the sound be called
	double mPlaySound = 0;
	/// The instrument class
	std::shared_ptr<StruckInstrument> mStruckInstrument;

public:

	/// Copy constructor (disabled)
	Cylinder(const Cylinder &) = delete;

	/// Assignment operator
	void operator=(const Cylinder &) = delete;

	Cylinder(std::wstring resourcesDir);

	void ReceiverAir(double air, int speed) override;

	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

	virtual void UpdateTime(double elapsed) override;

	void SetRotation(double rotation);

	/**
	 * Updates the max exteneds the Ram can be
	 * @param distance How far out it can be
	 */
	void SetMaxExtent(double distance){mMaxExtent = distance;}
	/**
	 * The air sink that is attach to the cylinder
	 * @return The air sink
	 */
	AirSink* GetSink(){return &mSink;}

	void SetMotionSink(std::shared_ptr<StruckInstrument> struckInstrument);
};

#endif //CANADIANEXPERIENCE_MACHINELIB_CYLINDER_H
