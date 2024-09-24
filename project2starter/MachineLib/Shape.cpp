/**
 * @file Shape.cpp
 * @author Auden Garrard
 */
#include "pch.h"
#include "Shape.h"
/**
 * Draws the shape
 * @param graphics The graphics that is being drawn
 * @param x The x location on the machine
 * @param y The y locatoon on the machine
 */
void Shape::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
	mShape.DrawPolygon(graphics, x + GetX(), y + GetY());
}
/**
 * Update the time of the machine
 * @param time How much time has passed
 */
void Shape::UpdateTime(double time) {}
