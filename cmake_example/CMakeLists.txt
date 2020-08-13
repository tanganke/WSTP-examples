cmake_minimum_required(VERSION 3.10)

project(WSTPLinkExample)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/WSTPLink)
add_executable(example src/example.cpp)
target_link_libraries(example WSTPLink)
set_target_properties(example PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY bin
)