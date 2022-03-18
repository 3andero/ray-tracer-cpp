project(Google_tests)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run vec3_tests.cpp vec3wrapper_tests.cpp point_tests.cpp rand_tests.cpp vec_tests.cpp enumUtils_tests.cpp)

target_link_libraries(Google_Tests_run ray-tracer-cpp-lib)

target_link_libraries(Google_Tests_run gtest gtest_main)
