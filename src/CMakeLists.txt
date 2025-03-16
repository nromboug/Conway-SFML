add_library(ConwayLib STATIC 
                game/cell.cpp
                game/grid.cpp
                core/application.cpp)
target_include_directories(ConwayLib PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(ConwayLib sfml-graphics sfml-window sfml-system)