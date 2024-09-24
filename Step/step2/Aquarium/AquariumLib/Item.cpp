/**
 * @file Item.cpp
 * @author Auden Garrard
 */

#include "../pch.h"
#include "Item.h"
#include "../AquariumApp.h"

/**
 * Destructor
 */
 Item::~Item()
 {

 }

/**
 * Constructor
 * @param aquarium The aquarium this item is a member of
 */
Item::Item(Aquarium *aquarium) : mAquarium(aquarium)
{
}
