/**
 * @file Starship.h
 *
 * @author Charles B. Owen
 *
 * Class the implements Sparty Starship, a simple rocket
 */

#pragma once

#include <memory>

class City;
class TileStarshipPad;

/**
 * Class the implements Sparty Starship, a simple rocket
*/
class Starship
{
private:
    wxRealPoint ComputePosition();
    bool IsLowerOwner(TileStarshipPad* pad);

    /// The image of the starship
    std::unique_ptr<wxBitmap> mImage;

    /// The launching pad for the starship
    TileStarshipPad* mLaunchingPad = nullptr;

    /// The landing pad for the starship
    TileStarshipPad* mLandingPad = nullptr;

    /// Current position of the starship in flight
    /// as a T value from 0 to 1.
    double mT = 0;

    /// Speed of the starship in t units per second
    double mSpeed = 0;

public:
    Starship(City* city);

    void SetLaunchingPad(TileStarshipPad* pad);
    void SetLandingPad(TileStarshipPad* pad);

    void Update(TileStarshipPad* pad, double elapsed);

    void Draw(TileStarshipPad* pad, wxDC* dc);
 
    bool InFlight();
};

