/**
 * @file Starship.cpp
 * @author Charles B. Owen
 */
#include "pch.h"
#include <string>
#include "Starship.h"
#include "TileStarshipPad.h"

/// The Sparty Starship image
const std::wstring StarshipImage = L"images/sparty-starship.png";

/// Starship offset to draw in the x dimension in pixels
const float StarshipOffsetX = -64;

/// Starship offset to draw in the y dimension in pixels
const float StarshipOffsetY = -105;

/// Bezier speed in the Y direction for curve slopw
const double StarshipBezierY = 200;

/// Default Starship speed in t values per second
const double StarshipSpeed = 0.5;

/**
 * Constructor
 * @param city City this Starship is associated with.
*/
Starship::Starship(City* city)
{
    mImage = std::make_unique<wxBitmap>(StarshipImage, wxBITMAP_TYPE_ANY);
}

/**
 * Set the Starship launching pad.
 * 
 * Whenever the launching pad is set, the Starship is reset
 * to a ready-to-launch condition on the pad.
 * @param pad New Starship launching pad
*/
void Starship::SetLaunchingPad(TileStarshipPad* pad)
{
    mLandingPad = nullptr;
    mLaunchingPad = pad;
    mSpeed = 0;
    mT = 0;
}

/**
 * Set the Starship landing pad.
 * This initiates the Starship flight from launch pad to landing pad.
 * @param pad New Starship landing pad.
*/
void Starship::SetLandingPad(TileStarshipPad* pad)
{
    mLandingPad = pad;
    mSpeed = StarshipSpeed;
    mT = 0;
}

/**
 * Update the Starship in time. This allows the Starship to fly.
 * 
 * If the Starship is pointed to by both a launching and landing
 * pad, the update will only be done when called from the 
 * pad that is the lower on the screen (maximum Y value)
 * 
 * @param pad Pad this function is called from.
 * @param elapsed Elasped time in seconds.
*/
void Starship::Update(TileStarshipPad* pad, double elapsed)
{
    if (!IsLowerOwner(pad))
    {
        return;
    }

    mT += elapsed * mSpeed;

    if (mT > 1)
    {
        mT = 1;
        mSpeed = 0;

        // We have landed
        if (mLandingPad != mLaunchingPad)
        {
            mLaunchingPad->StarshipIsGone();
        }

        mLandingPad->StarshipHasLanded();
    }

}

/**
 * Draw the Starship
 * 
 * If the Starship is pointed to by both a launching and landing
 * pad, the drawing will only be done when called from the 
 * pad that is the lower on the screen (maximum Y value)
 * 
 * @param pad The pad object that called the draw.
 * @param dc Device context to draw the Starship on.
*/
void Starship::Draw(TileStarshipPad *pad, wxDC* dc)
{
    if (!IsLowerOwner(pad))
    {
        return;
    }

    if (mImage != nullptr)
    {
        auto position = ComputePosition();

        int wid = mImage->GetWidth();
        int hit = mImage->GetHeight();

        dc->DrawBitmap(*mImage,
                       position.x + StarshipOffsetX, position.y + StarshipOffsetY);
    }
}

/**
 * Determine if this pad is the lower (int Y) of two pads owning
 * the Starship. If only owned by one, return true.
 * @param pad Pad to test
 * @return True if pad is the lower pad or Starship has only one owner.
*/
bool Starship::IsLowerOwner(TileStarshipPad *pad)
{
    // Smart drawing and updating. We only draw 
    // or update when called by the lowest tile
    // when we are pointed to by more than one pad.
    if (mLaunchingPad != nullptr && mLandingPad != nullptr)
    {
        if (mLaunchingPad->GetY() > mLandingPad->GetY())
        {
            // Only draw if called by the launching pad
            if (pad != mLaunchingPad)
            {
                return false;
            }
        }
        else
        {
            // Only draw if called by the landing pad
            if (pad != mLandingPad)
            {
                return false;
            }
        }
    }

    return true;
}

/**
 * Is this Starship in flight right now?
 * @return true if Starship is inflight
*/
bool Starship::InFlight()
{
    return mSpeed > 0;
}


/**
 * Compute a position for the Starship.
 * @return Position as a PointF object.
*/
wxRealPoint Starship::ComputePosition()
{
    if (mLaunchingPad != nullptr)
    {
        if (mLandingPad == nullptr)
        {
            // We have a launching pad, but no landing 
            // pad. Just return the launching pad location
            return wxRealPoint(mLaunchingPad->GetX(), mLaunchingPad->GetY());
        }

        // We are in flight
        double x1 = mLaunchingPad->GetX();
        double y1 = mLaunchingPad->GetY();
        double x4 = mLandingPad->GetX();
        double y4 = mLandingPad->GetY();

        double x2 = x1;
        double y2 = y1 - StarshipBezierY;
        double x3 = x4;
        double y3 = y4 - StarshipBezierY;

        double t = mT;

        // Compute Bezier curve basis functions
        double b1 = (1 - t) * (1 - t) * (1 - t);
        double b2 = 3 * (1 - t) * (1 - t) * t;
        double b3 = 3 * (1 - t) * t * t;
        double b4 = t * t * t;

        return wxRealPoint(
            (x1 * b1 + x2 * b2 + x3 * b3 + x4 * b4),
            (y1 * b1 + y2 * b2 + y3 * b3 + y4 * b4)
        );

    }
    else
    {
        return wxRealPoint(0, 0);
    }
}
