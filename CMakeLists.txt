cmake_minimum_required(VERSION 3.22)
project(Conway)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_subdirectory("src")
add_subdirectory("testing")

find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

add_executable(game-of-life main.cpp)

target_include_directories(game-of-life PUBLIC "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(game-of-life  ConwayLib)

