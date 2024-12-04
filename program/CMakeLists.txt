# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(GraphTraversal VERSION 1.0)

# Set the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the executable
add_executable(Program
    main.c
    data_to_graph.c
    traverse.c
    min_heap/min_heap.c
    shortest_path.c
)

# Include header files for compilation
target_include_directories(Program PRIVATE ${CMAKE_SOURCE_DIR})

# Add fully_connected_graph.txt as a resource to the build directory
configure_file(fully_connected_graph.txt fully_connected_graph.txt COPYONLY)