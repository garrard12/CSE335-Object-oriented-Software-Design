/**
 * @file Cow.h
 * @author Auden Garrard
 *
 * Class that describes a Cow
 */

#ifndef STEP1__COW_H
#define STEP1__COW_H

#include <string>
#include "Animal.h"

/**
 * Class that describes a Cow
 */
class Cow : public Animal
{
private:
	/// The types of Cows we can have on out farm
	enum class Type {Bull, BeefCow, MilkCow};

	///Cows name
	std::string mName;

	///The type of cow: Bull, BeefCow, MilkCow
	Type mType = Type::MilkCow;

	///The milk production for a cow in gallons per day
	double mMilkProduction = 0;

public:
	void ObtainCowInformation();
	void DisplayAnimal();
	int SurviveTornado();
};

#endif //STEP1__COW_H
