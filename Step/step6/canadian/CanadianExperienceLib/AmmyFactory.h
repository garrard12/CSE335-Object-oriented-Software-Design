/**
 * @file AmmyFactory.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_AMMYFACTORY_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_AMMYFACTORY_H
class Actor;
/**  Factory class that builds the Ammy character */
class AmmyFactory
{
private:

public:

	std::shared_ptr<Actor> Create(std::wstring imagesDir);
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_AMMYFACTORY_H
