/**
 * @file Chicken.cpp
 * @author Auden Garrard
 */

#include <iostream>
#include "Chicken.h"

using namespace std;
/**
 * Obtain a chicken description from the user
 */
void Chicken::ObtainChickenInformation()
{
	cout << endl;
	cout << "Input information about the chicken" << endl;

	//Obtain the ID, This is easy since it's just a sting
	cout << "Id: ";
	cin >> mId;
}
/**
 * Display the chicken
 */
void Chicken::DisplayAnimal()
{
	cout << "Chicken: " << mId << endl;
}
/**
 * Decides if the chicken can survive the tornado
 *
 * @return zero
 */
int Chicken::SurviveTornado()
{
	return 0;
}