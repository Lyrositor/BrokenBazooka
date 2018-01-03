# Define the project library
set(BB_PROJECT_SOURCES
        project.cpp)
set(BB_PROJECT_HEADERS
        project.h)
add_library(BbProject STATIC ${BB_PROJECT_SOURCES} ${BB_PROJECT_HEADERS})
