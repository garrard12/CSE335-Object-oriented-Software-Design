project(CityLib)

set(SOURCE_FILES
        pch.h
        City.h City.cpp
        Tile.h Tile.cpp
        CityReport.h CityReport.cpp
        MemberReport.h MemberReport.cpp
        TileBuilding.h TileBuilding.cpp
        TileGarden.h TileGarden.cpp
        TileLandscape.h TileLandscape.cpp
        MainFrame.cpp MainFrame.h
        CityReport.cpp CityView.cpp CityView.h ids.h
        TileWater.cpp TileWater.h
        Starship.cpp Starship.h
        TileStarshipPad.cpp TileStarshipPad.h
        BuildingCounter.cpp BuildingCounter.h RocketCounter.cpp RocketCounter.h PadVisitor.cpp PadVisitor.h DeletePadVisitor.cpp DeletePadVisitor.h)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)