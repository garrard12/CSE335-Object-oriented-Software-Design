/**
 * @file Machine2Factory.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINE2FACTORY_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINE2FACTORY_H

class Machine;
struct ma_engine;

/** Class that makes the Machine two **/
class Machine2Factory
{
private:
	/// The resources directory
	std::wstring mResourcesDir;

	/// The miniaudio engine
	ma_engine* mAudioEngine;
public:
	Machine2Factory(std::wstring resourcesDir, ma_engine* audioEngine);

	std::shared_ptr<Machine> Create();
};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINE2FACTORY_H
