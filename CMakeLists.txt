cmake_minimum_required(VERSION 3.16)
project(CRSP VERSION 1.0 LANGUAGES C CXX)

# Default to Release if not set
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Define output directory for all built shared libs
set(CRSP_OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CRSP_OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CRSP_OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CRSP_OUTPUT_DIR})

# Add shared library target
add_library(CRSP SHARED
    src/core/rsp_core.cpp
    src/execute/execute.cpp
    src/main.cpp
    # Add more source files here
)

# Include headers directory
target_include_directories(CRSP PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Windows-specific export definitions for DLL
if(WIN32)
  target_compile_definitions(CRSP PRIVATE CRSP_EXPORTS)
endif()

# Use C++17
target_compile_features(CRSP PRIVATE cxx_std_17)

# Optional: Set version info for the shared library
set_target_properties(CRSP PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
)

# Optional: Print info about build config and target architecture
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Target platform: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Target architecture: ${CMAKE_SIZEOF_VOID_P} bytes pointer")

