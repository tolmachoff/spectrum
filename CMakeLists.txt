project(spectrum)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(googletest)

add_subdirectory(3rd_party)

add_subdirectory(common)

add_subdirectory(fft)

add_subdirectory(filter)

add_subdirectory(source)

add_subdirectory(tests)
