add_library(ConwayLib STATIC 
                game/cell.cpp
                game/grid.cpp)
add_executable(Conway main.cpp)
target_include_directories(ConwayLib PUBLIC "${PROJECT_SOURCE_DIR}/include")