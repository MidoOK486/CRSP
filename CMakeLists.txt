cmake_minimum_required(VERSION 3.16)
project(CRSP VERSION 1.0 LANGUAGES C CXX)

# Set default to Release build if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Set output directory for DLLs and SOs
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Release)

# Add the main CRSP shared library
add_library(CRSP SHARED
    src/core/rsp_core.cpp
    src/execute/execute.cpp
    src/main.cpp
    # Add more source files here as needed
)

# Include directories (add all folders with public headers)
target_include_directories(CRSP
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

# Define export symbol for Windows DLL
target_compile_definitions(CRSP PRIVATE CRSP_EXPORTS)

# Set C++ standard
target_compile_features(CRSP PRIVATE cxx_std_17)

# Optional: install rules if needed later
# install(TARGETS CRSP DESTINATION lib)
