/**
 * @file Pipe.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_PIPE_H
#define CANADIANEXPERIENCE_MACHINELIB_PIPE_H
#include "Instrument.h"
#include "AirAccepter.h"
#include "AirSink.h"

struct ma_engine;
/**
 * The Pipe instrument
 */
class Pipe :  public AirAccepter, public Instrument
{
private:
	/// The length of the pipe
	int mPipeLength = 0;

	/// The image directory
	std::wstring mResourcesDir;

	/// The sound the pipe makes
	std::wstring mPipeNote;

	/// The miniaudio engine
	ma_engine* mAudioEngine;

	/// The image of the Pipe
	cse335::Polygon mPipe;

	/// The image to the top of the Pip
	cse335::Polygon mPipeTop;

	/// The puff of the smoke
	cse335::Polygon mPuff;

	/// The base for the pipe
	cse335::Polygon mPipeBase;

	/// Should the smoke should be showing
	bool mShowSmoke = false;

	/// Play the sound of instrument
	double mPlaySound = 0;

	/// The Air sink it goes to
	AirSink mSink;

public:
	Pipe(std::wstring resourcesDir,ma_engine* engine,std::wstring note,int pipeLength);

	Pipe() = delete;

	/// Copy constructor (disabled)
	Pipe(const Pipe &) = delete;

	/// Assignment operator
	void operator=(const Pipe &) = delete;

	void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

	void UpdateTime(double elapsed) override;

	void ReceiverAir(double air, int speed) override;

	//void SetPosition(wxPoint location){mLocation = location};
	/**
	 * Get the air sink to Compentd
	 * @return The sink that is assocaited with it
	 */
	AirSink *GetSink() {return &mSink;}
};

#endif //CANADIANEXPERIENCE_MACHINELIB_PIPE_H
