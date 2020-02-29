cmake_minimum_required(VERSION 3.15)

### Global Configuration
project(OAT)
set(EXECUTABLE_NAME "oat")
set(CMAKE_BUILD_TYPE Debug)

# Directory Structure
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")     # Source Files
set(BIN_DIR "${CMAKE_SOURCE_DIR}/bin")     # Binaries
set(LIB_DIR "${CMAKE_SOURCE_DIR}/lib")     # Static libraries
set(INC_DIR "${CMAKE_SOURCE_DIR}/include") # Additional include

set (INCS ${INC_DIR}) # Include directories for compiling
set (LIBS glfw GL)    # Libraries to link target against


# Source configuration file
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)
set(OPENGL_VERSION_MAJOR 3)
set(OPENGL_VERSION_MINOR 3)

configure_file (
  "${CMAKE_SOURCE_DIR}/cmake/config.hpp.in"
  "${SRC_DIR}/config.hpp")


# External dependencies
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenGL REQUIRED)


# Compiler Config
set(CMAKE_C_FLAGS "-Wall -Wextra -Wpedantic")
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-03")


# Input Path
include_directories(${INCS})
link_directories(${LIB_DIR})

# Output Path
set(LIBRARY_OUTPUT_PATH ${LIB_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})


# Compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPEx Release)
endif()


# Output Executable
set (SOURCE_FILES
  # Header
  ${SRC_DIR}/config.hpp
  # Source
  ${SRC_DIR}/main.cpp)


add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} ${LIBS})
