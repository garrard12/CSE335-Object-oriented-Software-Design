/**
 * @file PictureFactory.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTUREFACTORY_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTUREFACTORY_H

class Picture;
/**
 * A factory class that builds our picture.
 */
class PictureFactory
{
private:

public:
	std::shared_ptr<Picture> Create(std::wstring imagesDir);
};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTUREFACTORY_H
