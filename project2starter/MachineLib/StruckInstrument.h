/**
 * @file StruckInstrument.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_STRUCKINSTRUMENT_H
#define CANADIANEXPERIENCE_MACHINELIB_STRUCKINSTRUMENT_H

#include "Instrument.h"

class Cylinder;

struct ma_engine;
/**
 * The struck Intrument class
 */
class StruckInstrument : public Instrument
{
private:
	/// The resources directory
	std::wstring mResourcesDir;
	/// The miniaudio engine
	ma_engine* mAudioEngine;
	/// Note
	std::wstring mNote;
	/// Did the instrument get hit
	bool instrumentStruck = false;
	/// The Cylinder the at is playing the instrument
	Cylinder* mCylinder = nullptr;

public:
	/// Copy constructor (disabled)
	StruckInstrument(const StruckInstrument &) = delete;

	/// Assignment operator
	void operator=(const StruckInstrument &) = delete;

	StruckInstrument(std::wstring resourcesDir, ma_engine* audioEngine, std::wstring note);

	void CylinderConnection(Cylinder* cylinder);

	void PlayMusic();

};

#endif //CANADIANEXPERIENCE_MACHINELIB_STRUCKINSTRUMENT_H
