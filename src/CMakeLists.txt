add_library(ConwayLib STATIC 
                Game/Cell.cpp
                Game/Grid.cpp)
target_include_directories(ConwayLib PUBLIC "${PROJECT_SOURCE_DIR}/include")