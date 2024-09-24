/**
 * @file main.cpp
 * @author Auden Garrard
 *
 * Program main entry point
 */

#include <iostream>
//Bring in the farm object
#include "Farm.h"
#include "Cow.h"
#include "Chicken.h"
#include "Shark.h"

using namespace std;

/**
 * Main entry point
 *
 * This is where the program starts.
 */
int main()
{
	cout << "Instantiating Farm" << endl;
	Farm farm;

	// This loop contunously until we are done
	bool done = false;
	while (!done)
	{
		//Output user instructions
		cout << endl;
		cout << "Farm managemnt" << endl;
		cout << "1 - Add cow" << endl;
		cout << "2 - Add Chicken" << endl;
		cout << "3 - Add Shark" << endl;
		cout << "8 - Number of animals that can survive a tornado" << endl;
		cout << "9 - list inventory" << endl;
		cout << "99 - Exit" << endl;
		cout << "Select Option: ";

		//Get option from the user
		int option;
		cin >> option;

		//Handle invalid input
		//This makes sure that it will be the defualt option1
		if(!cin)
		{
			option = 1000;
			cin.clear();
			cin.ignore();
		}

		//Handle the possible user inputs
		switch(option)
		{
			case 1:
			{
				cout << "Adding cow" << endl;
				Cow *cow = new Cow();
				cow->ObtainCowInformation();
				farm.AddAnimal(cow);
			}
				break;
			case 2:
			{
				cout << "Adding chicken " << endl;
				Chicken *chicken = new Chicken();
				chicken->ObtainChickenInformation();
				farm.AddAnimal(chicken);
			}
				break;
			case 3:
			{
				cout << "Adding Shark " << endl;
				Shark *shark = new Shark();
				shark->ObtainSharkInformation();
				farm.AddAnimal(shark);
			}
				break;
			case 8:
			{
				int totalAnimals = farm.NumberOfAnimalThatCanSurvive();
				cout << "There are " << totalAnimals << " animals who could survive a tornado" << endl;
				break;
			}
			case 9:
				cout << "List inventory" << endl;
				farm.DisplayInventory();
				break;
			case 99:
				done = true;
				break;
			default:
				cout << "Invalid option" << endl;
				break;
		}
	}
	return 0;
}
