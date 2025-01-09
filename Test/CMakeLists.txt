cmake_minimum_required(VERSION 3.13)

project(googleSampleTest)
#get googletest
include(FetchContent)
FetchContent_Declare(googletest
                    GIT_REPOSITORY https://github.com/google/googletest
                    GIT_TAG release-1.12.1)

FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

# Assuming MyMathLib is at the same level as Test directory
set(MYMATHLIB_DIR "../MyMathLib/lib")  # Adjust path as necessary

# Include the headers from MyMathLib
include_directories("../MyMathLib/inc")

# Specify where the linker should look for libraries
link_directories(${MYMATHLIB_DIR})

# Enable debug symbols
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# Create the test executable
#add_executable(testRunner test.cpp)
add_executable(gMockRunner gMock.cpp)

# Link the test executable with GoogleTest and MyMathLib
# Link the test executable with GoogleTest and MyMathLib
#target_link_libraries(testRunner MyMathLib gtest_main gmock_main)
target_link_libraries(gMockRunner MyMathLib gtest_main gmock_main)