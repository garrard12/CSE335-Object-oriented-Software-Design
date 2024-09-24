/**
 * @file Cow.cpp
 * @author Auden Garrard
 */

#include <iostream>
#include "Cow.h"

using namespace std;

/**
 * Obtain information from the user about this cow.
 *
 * Asks the user for the information that describes a cow.
*/
void  Cow::ObtainCowInformation()
{
	cout << endl;
	cout << "Input information about the cow" << endl;

	// Obtain the name. This is east since it just a
	// string
	cout << "Name: ";
	cin >> mName;

	// Obtain the type using a menu. We have a loop so
	// we can handle errors.
	bool valid = false;
	while (!valid)
	{
		cout << "1: Bull" << endl;
		cout << "2: Beef Cow" << endl;
		cout << "3: Milk Cow" << endl;
		cout << "Enter selection and return: ";
		//grabs user input
		int option;
		cin >> option;
		// Check to make sure the input is valid
		if (!cin)
		{
			cin.clear();
			cin.ignore();
			continue;
		}
		//Picks what kind of car it is
		switch (option)
		{
			case 1:
				mType = Type::Bull;
				valid = true;
				break;
			case 2:
				mType = Type::BeefCow;
				valid = true;
				break;
			case 3:
				mType = Type::MilkCow;
				valid = true;
				break;
		}

		if (mType == Type::MilkCow)
		{
			valid = false;
			while (!valid)
			{
				cout << "Enter milk production in gallons per day: ";

				cin.clear();
				cin.ignore();
				cin >> mMilkProduction;
				if (cin)
				{
					valid = true;
				}
			}
		}
		else
		{
			// If not a milk cow, we have no milk production
			mMilkProduction = 0;
		}
	}
}
/**
 * Display information about this cow;
 */
void Cow::DisplayAnimal()
{
	cout << mName <<": ";
	switch (mType)
	{
		case Type::Bull:
			cout << "Bull" << endl;
			break;
		case Type::BeefCow:
			cout << "Beef Cow" << endl;
			break;
		case Type::MilkCow:
			cout << "Milk Cow/" << mMilkProduction << " GPD" << endl;
			break;
	}
}

/**
 * Decides if that kind of cow can survive the tornado
 *
 * @return a 1 if the cow survives or a 0 if they die
 */
int Cow::SurviveTornado()
{
	switch(mType)
	{
	case Type::Bull:
		return 1;
	case Type::BeefCow:
		return 0;
	case Type::MilkCow:
		return 0;
	}
}