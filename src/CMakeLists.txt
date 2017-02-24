# Set up Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

# Define the Broken Bazooka executable
set(BB_SOURCES
        map/map.cpp
        map/map_data.cpp
        map/map_tile.cpp
        map/sector.cpp
        map/selector.cpp
        map/selector_tile.cpp
        util/combo_box_item_delegate.cpp
        broken_bazooka.cpp
        main.cpp
        map_editor.cpp
        tile_selector.cpp)
set(BB_HEADERS
        map/layer.h
        map/map.h
        map/map_data.h
        map/map_tile.h
        map/sector.h
        map/selector.h
        map/selector_tile.h
        map/tile.h
        util/combo_box_item_delegate.h
        util/constants.h
        broken_bazooka.h
        map_editor.h
        tile_selector.h)
set(BB_MOC
        broken_bazooka.h)
set(BB_RCC
        res/resources.qrc)
set(BB_UIC
        broken_bazooka.ui tile_selector.cpp map_editor.cpp)
add_executable(BrokenBazooka ${BB_SOURCES} ${BB_HEADERS} ${BB_MOC} ${BB_RCC} ${BB_UIC})
target_link_libraries(BrokenBazooka Qt5::Core Qt5::Widgets)
