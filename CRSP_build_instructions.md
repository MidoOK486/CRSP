===============================
CRSP Project Build Instructions
===============================

Prerequisites:
-------------
Windows:
- Visual Studio 2022 Community with C++ workload installed
- CMake 3.16 or newer installed (CMake 4.0.0 is fine)
- Use Developer Command Prompt for Visual Studio 2022

Linux (Ubuntu/Debian):
- gcc, g++, make installed
- CMake 3.16 or newer installed

-------------------------------------------------

Building on Windows (Win64):
----------------------------
1. Open "Developer Command Prompt for VS 2022"
2. Navigate to the CRSP project folder:
   cd path\to\CRSP
3. Create and enter build directory:
   mkdir build_win64
   cd build_win64
4. Generate Visual Studio project files:
   cmake .. -G "Visual Studio 17 2022" -A x64
5. Build the project in Release mode:
   cmake --build . --config Release
6. Find the DLL here:
   CRSP\build_win64\Release\CRSP.dll

-------------------------------------------------

Building on Linux:
-----------------
1. Open terminal
2. Navigate to CRSP project folder:
   cd /path/to/CRSP
3. Create and enter build directory:
   mkdir build_linux
   cd build_linux
4. Generate Makefiles:
   cmake ..
5. Build project:
   make
6. Find the shared library here:
   CRSP/build_linux/libCRSP.so

-------------------------------------------------

Testing:
--------
- Use the generated DLL/.so in your emulator or test environment.
- On Linux, run 'ldd libCRSP.so' to check dependencies.
- On Windows, load CRSP.dll in your test app or emulator supporting plugins.

-------------------------------------------------

Tips:
-----
- Always clean build folder if switching between build types or architectures.
- Use 'Release' config for optimized builds.
- Check CMakeLists.txt to ensure 'add_library(CRSP SHARED ...)' is present.

-------------------------------------------------

Optional Scripts:
-----------------
Windows PowerShell build script (run from CRSP folder):

mkdir build_win64
cd build_win64
cmake .. -G "Visual Studio 17 2022" -A x64
cmake --build . --config Release
cd ..

Linux build script (save as build-linux.sh and run):

#!/bin/bash
mkdir -p build_linux
cd build_linux
cmake ..
make
cd ..

-------------------------------------------------

For further help or bug reports, contact the developer.

Thank you for using CRSP!
