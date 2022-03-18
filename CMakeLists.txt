cmake_minimum_required(VERSION 3.0.0)
project(ray-tracer-cpp VERSION 0.1.0)

include(CTest)
enable_testing()
add_subdirectory(Google_tests)
add_subdirectory(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD 17)
include(CPack)
include_directories("${PROJECT_SOURCE_DIR}/inc/")

add_executable(ray-tracer-cpp ./main.cpp)
target_link_libraries(ray-tracer-cpp ray-tracer-cpp-lib)