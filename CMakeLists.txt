CMAKE_MINIMUM_REQUIRED(VERSION 3.17)

PROJECT(
  tdsa LANGUAGES CXX
  DESCRIPTION "A collection of C++ thin data structures and algorithms.")

ADD_LIBRARY(tdsa INTERFACE)
TARGET_INCLUDE_DIRECTORIES(tdsa INTERFACE include)

# Override defaults if building this library as standalone
IF(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
  SET(BUILD_TESTING ON)
  SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
  #  SET(CMAKE_LINK_WHAT_YOU_USE TRUE)
  SET(CMAKE_BUILD_TYPE Release)
  SET(CMAKE_CXX_STANDARD_REQUIRED ON)
  SET(CMAKE_CXX_EXTENSIONS OFF)
  SET(CMAKE_CXX_STANDARD 20)
  TARGET_COMPILE_OPTIONS(
    tdsa
    INTERFACE -Wall
              -Warray-bounds
              -Wdouble-promotion
              -Weffc++
              -Wextra
              -Wimplicit-fallthrough
              -Winit-self
              -Wfloat-equal
              -Wformat=2
              -Wmissing-include-dirs
              -Wno-unused-const-variable
              -Wno-unused-function
              -Wnull-dereference
              -Wparentheses
              -Wpedantic
              -Wshift-overflow
              -Wshadow
              -Wstrict-aliasing=1
              -Wstrict-overflow=5
              -Wtautological-compare
              -Wuninitialized)
ENDIF()

IF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	INCLUDE(CTest)
	ADD_SUBDIRECTORY(tests)
ENDIF()
