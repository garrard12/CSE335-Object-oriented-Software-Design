/**
 * @file Shark.h
 * @author Auden Garrard
 *
 * Declaration of the Shark
 */

#include <string>
#include "Animal.h"

#ifndef STEP1__SHARK_H
#define STEP1__SHARK_H

/**
 * Class that describes a Shark
 */
class Shark : public Animal
{
private:
	///The types of Sharks we can have on the farm
	enum class Type{GreatWhite,HammerHead,Nurse,Thresher};

	///The type of cows: GreatWhite,HammerHead,Nurse,Thresher
	Type mType = Type::GreatWhite;

	///Name of the Shark
	std::string mName;
public:
	void ObtainSharkInformation();
	void DisplayAnimal();
	int SurviveTornado();
};

#endif //STEP1__SHARK_H
