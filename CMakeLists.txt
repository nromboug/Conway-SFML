cmake_minimum_required(VERSION 3.22)
project(Conway)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)


add_executable(Conway main.cpp)
add_subdirectory("src")
add_subdirectory("testing")

find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

target_include_directories(Conway PUBLIC "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(Conway sfml-graphics sfml-window sfml-system ConwayLib)