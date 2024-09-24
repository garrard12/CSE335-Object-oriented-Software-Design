/**
 * @file Farm.cpp
 * @author Auden Garrard
 */

#include "Farm.h"

/**
 * Add an animal to the farm inventory
 * @param animal A cow to add to the inventory
 */
void Farm::AddAnimal(Animal *animal)
{
	mInvertory.push_back(animal);
}

/**
 * Display the farm inventory
 */
void Farm::DisplayInventory()
{
	for (auto  animal : mInvertory)
	{
		animal->DisplayAnimal();
	}
}

/**
 * Finds out how many animals that can survive the tornado
 * @return how many of the animals can survive the tornado
 */
int Farm::NumberOfAnimalThatCanSurvive()
{
	int counter = 0;
	for (auto animal: mInvertory)
	{
		counter += animal->SurviveTornado();
	}
	return counter;
}

/**
 * Farm destructor
 */
Farm::~Farm()
{
	// Iterate over all of the animals, destroying each one.
	for (auto animal : mInvertory)
	{
		delete animal;
	}
	// And cleat the list
	mInvertory.clear();
}
