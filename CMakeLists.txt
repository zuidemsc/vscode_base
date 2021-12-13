cmake_minimum_required(VERSION 3.0.0)
project(gtest-test VERSION 0.1.0)

#include(CTest)
#add_subdirectory(Core/Src)
#include_directories(${GTEST_INCLUDE_DIR})
include_directories(Core/Inc/ Drivers/STM32L4xx_HAL_Driver/Inc/ Drivers/CMSIS/Device/ST/STM32L4xx/Include/)
enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)

#add_executable(gtest-test Core/Src/main.c)
add_executable(test-all Core/Src/gtest.cpp)
target_link_libraries(test-all GTest::GTest GTest::Main)
#add_test(NAME Test1 COMMAND test-all)
gtest_discover_tests(test-all)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
