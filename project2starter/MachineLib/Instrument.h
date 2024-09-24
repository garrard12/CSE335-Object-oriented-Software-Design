/**
 * @file Instrument.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_INSTRUMENT_H
#define CANADIANEXPERIENCE_MACHINELIB_INSTRUMENT_H

#include "Shape.h"
#include <miniaudio.h>


struct ma_engine;
/** The instrument to the machine */
class Instrument : public Shape
{
private:

	/// The image resources directory  for
	std::wstring mResourcesDir;

	/// The sound the pipe makes
	std::wstring mNote;

	/// The miniaudio engine
	ma_engine* mAudioEngine;

	/// The sound that is playing
	ma_sound mSound;

public:

	/// Copy constructor (disabled)
	Instrument(const Instrument &) = delete;
	
	/// Assignment operator
	void operator=(const Instrument &) = delete;

	~Instrument();
	
	Instrument(std::wstring resourcesDir, ma_engine *audioEngine, std::wstring note);

	void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

 	void UpdateTime(double elapsed) override;

	 void PlaySound();
};

#endif //CANADIANEXPERIENCE_MACHINELIB_INSTRUMENT_H
