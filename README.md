Broken Bazooka
==============

*A graphical editor for EarthBound, built on top of [CoilSnake](https://mrtenda.github.io/CoilSnake/).*

**License:** [Unlicense](http://unlicense.org/)

## Building

Broken Bazooka is written in C++ and should be portable to any desktop platform that supports Qt and Python.

### Prerequisites

You will need the following libraries and tools in order to build Broken Bazooka:
* A C++11 compiler (GCC, MinGW, Visual Studio...)
* [CMake](https://cmake.org/) for generating the build files
* [Qt 5](https://www.qt.io/) (specifically, the QtWidgets library)
* ~~Python 2.7 development libraries~~ (not yet required)

### Compiling

The first step in compiling Broken Bazooka is to run CMake, in order for it to generate your compiler-specific build files. This can easily done through its GUI by pointing its source directory to this directory, then creating a `build/` subdirectory to house the build files.

Alternatively, you can also run CMake from a terminal with the following commands:

    mkdir build
    cd build
    cmake ../

If CMake fails to locate any library paths, you will have to provide them yourself.

You can now build the project with your system's compiler suite. On UNIX-like systems, this is usually done by running the `make` command from the `build/` directory. On Windows, if you have Visual Studio, you can instruct CMake to build a Visual Studio Solution which you can then open.
## Credits

The creator of Broken Bazooka is Lyrositor, who would like to thank Mr. Tenda for CoilSnake, as well as HyperBound and H.S. for suggestions and feedback.
