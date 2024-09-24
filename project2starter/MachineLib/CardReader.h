/**
 * @file CardReader.h
 * @author Auden Garrard
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_CARDREADER_H
#define CANADIANEXPERIENCE_MACHINELIB_CARDREADER_H
#include "Component.h"
#include "Polygon.h"

class AirSource;
/**
 * The card reader class
 */
class CardReader : public Component
{
private:
	/// The front of the card reader
	cse335::Polygon mFront;
	/// The back of the card reader
	cse335::Polygon mBack;
	/// The Card
	cse335::Polygon mCard;
	/// The resources directory of the images
	std::wstring mResourcesDir;
	/// The Column the card reader is on
	int mCurrentColumn = 0;
	/// The beats per Minute
	int mBeatsPerMinute = 180;
	/// All the air sources
	std::vector<std::shared_ptr<AirSource>> mSources;
public:
	/// Copy constructor (disabled)
	CardReader(const CardReader &) = delete;

	/// Assignment operator
	void operator=(const CardReader &) = delete;

	CardReader(std::wstring resourcesDir);

	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

	virtual void UpdateTime(double elapsed) override;

	bool IsPunched(int column, int row);

	/**
	 * Set the card image
	 * @param card The image to the card
	 */
	void SetCard(std::wstring card){mCard.SetImage(card);}

	/**
	* Get an air source.
	* @param i Source index 0-9
	* @return Pointer to AirSource object.
   */
	std::shared_ptr<AirSource> GetSource(int i) { return mSources[i]; }
};

#endif //CANADIANEXPERIENCE_MACHINELIB_CARDREADER_H
