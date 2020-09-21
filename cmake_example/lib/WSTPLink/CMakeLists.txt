cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

add_library(WSTPLink WSTPLink.cpp)
target_include_directories(WSTPLink PUBLIC .)
target_link_directories(WSTPLink PUBLIC .)
target_link_libraries(WSTPLink WSTP64i4 m pthread rt stdc++ dl uuid)
set_target_properties(WSTPLink PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY lib
)