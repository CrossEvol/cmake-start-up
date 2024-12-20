cmake_minimum_required(VERSION 3.29)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_GENERATOR "MinGW Makefiles")

project(start_up)

set(CMAKE_CXX_STANDARD 17)

# Debug/Release configuration settings
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# Create separate output directories for Debug and Release
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)

# Include FetchContent
include(FetchContent)

# Declare fmt
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 10.2.1
)

# Declare Catch2
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.5.2
)

# Make the libraries available
FetchContent_MakeAvailable(fmt Catch2)

############################################################
# Create a library
############################################################

add_library(hello_library STATIC
        "src/hello.cpp"
)
add_library(hello::library ALIAS hello_library)

target_include_directories(hello_library
        PUBLIC
        ${PROJECT_SOURCE_DIR}/src/include/static
)

target_link_libraries(hello_library
        PRIVATE
        fmt::fmt-header-only)

############################################################
# Create Main executables (Debug and Release)
############################################################

# Debug executable
add_executable(start_up_debug src/main.cpp)
set_target_properties(start_up_debug PROPERTIES 
    OUTPUT_NAME "start_up"
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}
    COMPILE_FLAGS ${CMAKE_CXX_FLAGS_DEBUG}
)

target_include_directories(start_up_debug
    PUBLIC
    ${PROJECT_SOURCE_DIR}/src/include/static
)

target_link_libraries(start_up_debug
    PRIVATE
    hello::library
    fmt::fmt-header-only
)

# Release executable
add_executable(start_up_release src/main.cpp)
set_target_properties(start_up_release PROPERTIES 
    OUTPUT_NAME "start_up"
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}
    COMPILE_FLAGS ${CMAKE_CXX_FLAGS_RELEASE}
)

target_include_directories(start_up_release
    PUBLIC
    ${PROJECT_SOURCE_DIR}/src/include/static
)

target_link_libraries(start_up_release
    PRIVATE
    hello::library
    fmt::fmt-header-only
)

############################################################
# Create Test executable
############################################################

add_executable(unit_tests
        test/unit_tests.cpp
)

target_include_directories(unit_tests
        PUBLIC
        ${PROJECT_SOURCE_DIR}/src/include/static
)

# Link libraries to test executable
target_link_libraries(unit_tests PRIVATE
        hello::library
        Catch2::Catch2WithMain
)
