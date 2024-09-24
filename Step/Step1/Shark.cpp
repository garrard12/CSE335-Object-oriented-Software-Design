/**
 * @file Shark.cpp
 * @author Auden Garrard
 */

#include <iostream>
#include "Shark.h"

using namespace std;

/**
 * Obtain information from the user about this shark.
 *
 * Asks the user for information that describes a shark.
*/
void Shark::ObtainSharkInformation()
{
	cout << endl;
	cout << "Input information about the shark" << endl;

	//Get the name of the shark
	cout << "Name :";
	cin >> mName;

	bool validInput = false;
	while (!validInput)
	{
		//Display the option of shark
		cout << "1: Great White" << endl;
		cout << "2: Hammer Head" << endl;
		cout << "3: Nurse" << endl;
		cout << "4: Thresher" << endl;

		//Take in user input
		int option;
		cin >> option;

		//See if it is valid input
		if (!cin)
		{
			cin.clear();
			cin.ignore();
			continue;
		}
		//Set Type to the right shark
		switch (option)
		{
			case 1:
				mType = Type::GreatWhite;
				validInput = true;
				break;
			case 2:
				mType = Type::HammerHead;
				validInput = true;
				break;
			case 3:
				mType = Type::Nurse;
				validInput = true;
				break;
			case 4:
				mType = Type::Thresher;
				validInput = true;
				break;
		}
	}
}
/**
 * Display information about this shark
 */
void Shark::DisplayAnimal()
{
	cout << "Shark " << mName << " is a ";

	//picks what shark to display
	switch(mType)
	{
		case Type::GreatWhite:
			cout << "Great White" << endl;
			break;
		case Type::HammerHead:
			cout << "Hammer Head" << endl;
			break;
		case Type::Nurse:
			cout << "Nurse" << endl;
			break;
		case Type::Thresher:
			cout << "Thresher" << endl;
			break;
	}
}
/**
 * Decides if that kind of shark can survive the tornado
 *
 * @return a 1 if the shark survives or a 0 if they die
 */
int Shark::SurviveTornado()
{
	switch(mType)
	{
		case Type::GreatWhite:
			return 1;
		case Type::HammerHead:
			return 1;
		case Type::Nurse:
			return 0;
		case Type::Thresher:
			return 0;
	}
}