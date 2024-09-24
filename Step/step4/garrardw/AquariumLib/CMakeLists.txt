project(AquariumLib)

set(SOURCE_FILES MainFrame.cpp MainFrame.h AquariumView.cpp AquariumView.h pch.h
        AquariumView.h AquariumView.cpp Aquarium.cpp AquariumView.h Item.cpp Item.h FishBeta.cpp FishBeta.h ids.h Angler.cpp Angler.h Bubbles.cpp Bubbles.h Castle.cpp Castle.h Fish.cpp Fish.h)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)