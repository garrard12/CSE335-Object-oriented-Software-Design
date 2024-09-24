/**
 * @file pch.h
 * @author Auden Garrard
 *
 * Declaration of the precompiler header
 *
 * Much be include in all cpp files
 * This make the compile time much faster because it
 * remembers the state of it last time and just loads it in
 */

#ifndef AQUARIUM_AQUARIUMLIB_PCH_H
#define AQUARIUM_AQUARIUMLIB_PCH_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/xml/xml.h>
#endif

#endif //AQUARIUM_AQUARIUMLIB_PCH_H
