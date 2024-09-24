/**
 * @file Machine1Factory.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINE1FACTORY_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINE1FACTORY_H

class Machine;
struct ma_engine;

/** Class that makes the Machine one **/
class Machine1Factory
{
private:
	/// The resources directory
	std::wstring mResourcesDir;

	/// The miniaudio engine
	ma_engine* mAudioEngine;
public:

	Machine1Factory(std::wstring resourcesDir, ma_engine* audioEngine);

	std::shared_ptr<Machine> Create();

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINE1FACTORY_H
