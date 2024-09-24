/**
 * @file Machine.cpp
 * @author Auden Garrard
 */
#include "pch.h"
#include "Machine.h"
#include "Component.h"

using namespace std;
struct ma_engine;

/**
 * Constructor
 * @param resourcesDir The image directory
 */
Machine::Machine(std::wstring resourcesDir)
	:mResourcesDir(resourcesDir)
{}
/**
 * Add the component to the machine
 * @param component The wanted component that is want to be added
 */
void Machine::AddComponent(std::shared_ptr<Component> component)
{
	mComponent.push_back(component);
	component->SetMachine(this);
}
/**
 * Draws all the components of the machine
 * @param graphics
 */
void Machine::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
	//
	// Loops through all the Components and draws them
	//
	for(auto component : mComponent)
	{
		component->Draw(graphics, mLocation.x, mLocation.y);
	}
}
/**
 * Calls update on all the machine compents
 * @param elapsed How much time has passed
 */
void Machine::UpdateTime(double elapsed)
{
	// updates the Components and Time
	for(auto component : mComponent)
	{
		component->UpdateTime(elapsed);
	}
}