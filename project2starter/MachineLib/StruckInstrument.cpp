/**
 * @file StruckInstrument.cpp
 * @author Auden Garrard
 */
#include "pch.h"
#include "StruckInstrument.h"
#include "Cylinder.h"
#include "Instrument.h"

using namespace std;
/**
 * Constructor
 * @param resourcesDir  The resources directory
 * @param audioEngine The audio engine to play music
 * @param note The note to play
 */
StruckInstrument::StruckInstrument(std::wstring resourcesDir, ma_engine *audioEngine, std::wstring note)
:mResourcesDir(resourcesDir),mAudioEngine(audioEngine),mNote(note),Instrument(resourcesDir,audioEngine,note)
{

}
/**
 * The struck instrument class
 * @param cylinder The Cylinder of the class
 */
void StruckInstrument::CylinderConnection(Cylinder *cylinder)
{
	mCylinder = cylinder;
}
/**
 * Play the sound
 */
void StruckInstrument::PlayMusic()
{
	PlaySound();
}
