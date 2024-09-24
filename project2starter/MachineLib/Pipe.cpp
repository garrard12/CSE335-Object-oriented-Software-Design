/**
 * @file Pipe.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "Pipe.h"
#include "Instrument.h"

/// The pipe base image
const std::wstring PipeBaseImage = L"/images/pipe-base.png";

/// The pipe image
const std::wstring PipeImage = L"/images/pipe.png";

/// The pipe top image
const std::wstring PipeTopImage = L"/images/pipe-top.png";

/// The pipe puff image
const std::wstring PuffImage = L"/images/puff.png";

/// Pipe images width in pixels
const int PipeWidth = 20;

/// Pipe base height
const int PipeBaseHeight = 20;

/// Puff image width in pixels
const int PuffWidth = 65;
/**
 * Constructor
 * @param resourcesDir The  resources Directory
 * @param engine The sound engine
 * @param note The note this pipe plays
 * @param pipeLength How long the pipe is
 */
Pipe::Pipe(std::wstring resourcesDir, ma_engine *engine, std::wstring note, int pipeLength) :
mResourcesDir(resourcesDir), mAudioEngine(engine), mPipeNote(note), mPipeLength(pipeLength),
mSink(this),Instrument(resourcesDir,engine,note)
{
	// Instrument base class polygon
	mPipeBase.SetImage(resourcesDir + PipeBaseImage);
	mPipeBase.Rectangle(-PipeWidth / 2, 0, PipeWidth, PipeWidth);

	// Polygons for the other components
	mPipe.SetImage(resourcesDir + PipeImage);
	mPipe.Rectangle(-PipeWidth / 2, -PipeBaseHeight, PipeWidth, pipeLength);

	mPipeTop.SetImage(resourcesDir + PipeTopImage);
	mPipeTop.Rectangle(-PipeWidth / 2, -PipeBaseHeight - pipeLength, PipeWidth);

	mPuff.SetImage(resourcesDir + PuffImage);
	mPuff.Rectangle(-PuffWidth / 2, -PipeBaseHeight - pipeLength, PuffWidth);
}
/**
 * Draws the pipe
 * @param graphics The graphic that should be drawn
 * @param x Where the machine is
 * @param y Where the machine is
 */
void Pipe::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
	// Update the location on the machine
	x += GetX();
	y += GetY();

	// Should the smoke be drawn
	if(mShowSmoke)
	{
		mPuff.DrawPolygon(graphics,x,y);
	}
	//Draws the pipe inform
	mPipe.DrawPolygon(graphics,x,y);
	mPipeTop.DrawPolygon(graphics,x,y);
	mPipeBase.DrawPolygon(graphics,x,y);
}
/**
 * Update the time of the machien
 * @param elapsed How much has gone buy
 */
void Pipe::UpdateTime(double elapsed)
{
	Instrument::UpdateTime(elapsed);
}
/**
 * Receiver th air pressure for
 * @param air The pressure for the air
 * @param speed The amount the tube should bend
 */
void Pipe::ReceiverAir(double air, int speed)
{
	// Should the next note be played
	if (air > 0 && mPlaySound == 0 )
	{
		mShowSmoke = true;
		PlaySound();
	}
	if(air == 0)
	{
		mShowSmoke = false;
	}
	mPlaySound = air;
}

