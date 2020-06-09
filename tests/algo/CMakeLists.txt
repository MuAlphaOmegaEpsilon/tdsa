FILE(GLOB_RECURSE TESTS CONFIGURE_DEPENDS "*.cpp")

FOREACH(TEST_FILE ${TESTS})
  FILE(RELATIVE_PATH TEST_FILE_REL ${CMAKE_SOURCE_DIR}/tests/algo ${TEST_FILE})
  STRING(REPLACE ".cpp" "" TEST_NAME ${TEST_FILE_REL})
  ADD_EXECUTABLE(${TEST_NAME} ${TEST_FILE})
  TARGET_LINK_LIBRARIES(${TEST_NAME} tdsa)
  TARGET_COMPILE_OPTIONS(
    ${TEST_NAME}
    PRIVATE -Werror
            -Wall
            -Warray-bounds
            -Wdouble-promotion
            -Weffc++
            -Wextra
            -Wimplicit-fallthrough
            -Winit-self
            -Wfloat-equal
            -Wformat=2
            -Wmissing-include-dirs
            -Wnull-dereference
            -Wparentheses
            -Wpedantic
            -Wshift-overflow
            -Wshadow
            -Wstrict-aliasing=1
            -Wstrict-overflow=5
            -Wtautological-compare
            -Wuninitialized)
  ADD_TEST("[algo]${TEST_NAME}" ${TEST_NAME})
ENDFOREACH()
