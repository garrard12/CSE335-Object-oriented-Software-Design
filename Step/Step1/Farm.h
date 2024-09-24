/**
 * @file Farm.h
 * @author Auden Garrard
 *
 * Class that describes a Farm
 *
 * This class holds a collection of animals that make
 * up the inventory of a farm.
 */

#ifndef STEP1_FARM_H
#define STEP1_FARM_H

#include <vector>
#include "Cow.h"

/**
 * Class that describes a Farm
 *
 * Holds a collection of animals that make up the farm
 */
class Farm
{
private:
	/// Stores the different kinds of animals
	std::vector<Animal *> mInvertory;
public:
	void AddAnimal(Animal *animal);
	void DisplayInventory();
	int NumberOfAnimalThatCanSurvive();
	~Farm();
};

#endif //STEP1_FARM_H
