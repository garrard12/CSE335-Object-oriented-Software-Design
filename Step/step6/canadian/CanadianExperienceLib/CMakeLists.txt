project(CanadianExperienceLib)

set(SOURCE_FILES
        pch.h
        MainFrame.cpp MainFrame.h
        ViewEdit.cpp ViewEdit.h
        ViewTimeline.cpp ViewTimeline.h
        PictureObserver.h PictureObserver.cpp
        Picture.h Picture.cpp
        Drawable.h Drawable.cpp
        Actor.h Actor.cpp
        PolyDrawable.h PolyDrawable.cpp
        PictureFactory.h PictureFactory.cpp
        HaroldFactory.h HaroldFactory.cpp
        ImageDrawable.h ImageDrawable.cpp
        HeadTop.h HeadTop.cpp
        AmmyFactory.h AmmyFactory.cpp
        )

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)