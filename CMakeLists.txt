cmake_minimum_required(VERSION 3.15)
project(CRSP VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optionally build static or shared (default: shared)
option(CRSP_BUILD_STATIC "Build CRSP as a static library" OFF)

# Output path customization (optional)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Collect all .cpp source files recursively
file(GLOB_RECURSE CRSP_SRC
    "src/*.cpp"
)

# Header include path
include_directories(${CMAKE_SOURCE_DIR}/include)

# Choose library type
if(CRSP_BUILD_STATIC)
    add_library(CRSP STATIC ${CRSP_SRC})
else()
    add_library(CRSP SHARED ${CRSP_SRC})
    target_compile_definitions(CRSP PRIVATE CRSP_EXPORTS)
endif()

# Set output library name and version
set_target_properties(CRSP PROPERTIES
    OUTPUT_NAME "CRSP"
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER ""
)

# Optional install step
install(TARGETS CRSP
    EXPORT CRSPTargets
    RUNTIME DESTINATION bin           # Windows DLL
    LIBRARY DESTINATION lib           # Linux SO
    ARCHIVE DESTINATION lib           # Static .a or .lib
)

install(DIRECTORY include/ DESTINATION include
        FILES_MATCHING PATTERN "*.h")

# Optional export targets (for find_package)
install(EXPORT CRSPTargets
    FILE CRSPConfig.cmake
    NAMESPACE CRSP::
    DESTINATION lib/cmake/CRSP
)
