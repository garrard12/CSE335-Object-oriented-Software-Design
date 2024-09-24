/**
 * @file Instrument.cpp
 * @author Auden Garrard
 */
#include "pch.h"
#include "Instrument.h"


/**
 * Constructor
 * @param resourcesDir The  resources Directory
 * @param audioEngine The sound engine
 * @param note The note this pipe plays
 */
Instrument::Instrument(std::wstring resourcesDir, ma_engine *audioEngine, std::wstring note) :
mResourcesDir(resourcesDir), mAudioEngine(audioEngine), mNote(note)
{
	auto result = ma_sound_init_from_file(audioEngine, wxString(resourcesDir + note), 0, NULL, NULL, &mSound);
	if (result != MA_SUCCESS)
	{
		wxString msg;
		msg.Printf(L"Unable to load audio file %s - %d", wxString(note), result);
		wxMessageBox( msg, wxT("miniaudio failure"), wxICON_ERROR);
	}
}
/**
 * Draws the instrument
 * @param graphics The graphic to be drawn
 * @param x Where on the machine to be drawn
 * @param y When on the machine to be drawn
 */
void Instrument::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
	Shape::Draw(graphics, x, y);
}
/**
 * Update the time of the machine
 * @param elapsed How much time has passed
 */
void Instrument::UpdateTime(double elapsed)
{

}
/**
 * Destructor
 */
Instrument::~Instrument()
{
	if(ma_sound_is_playing(&mSound))
	{
		ma_sound_stop(&mSound);
	}
	ma_sound_uninit(&mSound);
}
/**
 * Plays the sound for the instruments
 */
void Instrument::PlaySound()
{
	// If the sound is already playing, stop it first
	if(ma_sound_is_playing(&mSound))
	{
		ma_sound_stop(&mSound);
	}

	// Always rewind to the beginning before playing
	ma_sound_seek_to_pcm_frame(&mSound, 0);

	// And play the sound!
	ma_sound_start(&mSound);
}
