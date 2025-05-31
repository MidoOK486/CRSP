cmake_minimum_required(VERSION 3.15)
project(CRSP VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
file(GLOB_RECURSE CRSP_SRC
     "src/*.cpp"
)

# Header search path
include_directories(${CMAKE_SOURCE_DIR}/include)

# Build as shared library
add_library(CRSP SHARED ${CRSP_SRC})

# Define macro for exports
target_compile_definitions(CRSP PRIVATE CRSP_EXPORTS)

# Output name/version
set_target_properties(CRSP PROPERTIES
    OUTPUT_NAME "CRSP"
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)
