/**
 * @file Chicken.h
 * @author Auden Garrard
 *
 * Declaration of the Chicken class.
 */

#ifndef STEP1__CHICKEN_H
#define STEP1__CHICKEN_H

#include <string>
#include "Animal.h"

/**
 * Class that describes a chicken
 */
class Chicken : public Animal
{
private:
	/// The chicken's ID
	std::string mId;

public:
	void ObtainChickenInformation();
	void DisplayAnimal();
	int SurviveTornado();
};

#endif //STEP1__CHICKEN_H
