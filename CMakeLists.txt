CMAKE_MINIMUM_REQUIRED(VERSION 3.17)

PROJECT(
  thin LANGUAGES CXX
  DESCRIPTION "A collection of C++ data structures that are actually thin.")

ADD_LIBRARY(thin INTERFACE)
TARGET_INCLUDE_DIRECTORIES(thin INTERFACE include)

# Override defaults if building this library as standalone
IF(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
  SET(BUILD_TESTING ON)
  SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
  #  SET(CMAKE_LINK_WHAT_YOU_USE TRUE)
  SET(CMAKE_BUILD_TYPE Release)
  SET(CMAKE_CXX_STANDARD_REQUIRED ON)
  SET(CMAKE_CXX_EXTENSIONS OFF)
  SET(CMAKE_CXX_STANDARD 20)
  SET(CMAKE_CXX_INCLUDE_WHAT_YOU_USE iwyu -Xiwyu --transitive-includes-only)
  SET(CMAKE_CXX_CLANG_TIDY clang-tidy-10)
  TARGET_COMPILE_OPTIONS(
    thin
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

INCLUDE(CTest)
ADD_SUBDIRECTORY(tests)
