/**
 * @file Animal.h
 * @author Auden Garrard
 *
 * Declaration of the Animal class
 */

#ifndef STEP1__ANIMAL_H
#define STEP1__ANIMAL_H

/**
 * The object of this class is to show what animals are on the farm
 */
class Animal
{
private:

public:
	virtual ~Animal();
	/** Display an animal */
	// This will be overridden by any class derived from animal
	virtual void DisplayAnimal(){}
	virtual int SurviveTornado(){}
};

#endif //STEP1__ANIMAL_H
