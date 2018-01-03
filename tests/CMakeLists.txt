include_directories(../src/)

set(TEST_SOURCES
        main.cpp)
add_executable(BbTests ${TEST_SOURCES})
target_link_libraries(BbTests BbProject)

add_test(NAME BrokenBazookaTests
        COMMAND BbTests
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
