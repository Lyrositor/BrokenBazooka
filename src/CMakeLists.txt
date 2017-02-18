# Set up Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

# Define the Broken Bazooka executable
set(BB_SOURCES
        main.cpp
        main_window.cpp
        map_editor.cpp
        tile_selector.cpp)
set(BB_HEADERS
        main_window.h
        map_editor.h
        tile_selector.h)
set(BB_MOC
        main_window.h)
set(BB_RCC
        res/resources.qrc)
set(BB_UIC
        main_window.ui)
add_executable(BrokenBazooka ${BB_SOURCES} ${BB_HEADERS} ${BB_MOC} ${BB_RCC} ${BB_UIC})
target_link_libraries(BrokenBazooka Qt5::Core Qt5::Widgets)
