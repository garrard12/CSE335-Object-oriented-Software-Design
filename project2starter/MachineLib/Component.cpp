/**
 * @file Component.cpp
 * @author Auden Garrard
 */
#include "pch.h"
#include "Component.h"
#include "Machine.h"

/**
 * Set the machine to the
 * @param machine The pointer to the machine
 */
void Component::SetMachine(Machine *machine)
{
	mMachine = machine;
}
/**
 * Draws the Component
 * @param graphics The graphic of the machine
 * @param x The x location on the machine
 * @param y The y location on the machine
 */
void Component::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{}
