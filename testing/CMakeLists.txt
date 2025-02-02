add_executable(GridTest gridtest.cpp)

target_include_directories(GridTest PRIVATE "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(GridTest PUBLIC ConwayLib)

add_test(NAME GridTest COMMAND GridTest)