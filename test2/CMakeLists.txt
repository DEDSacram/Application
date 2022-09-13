cmake_minimum_required(VERSION 3.0)

# Set the name and the supported language of the project
project(hello-world C)
# Set the minimum version of cmake required to build this project
cmake_minimum_required(VERSION 2.6)
# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk+-4.0)
# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})
# Add other flags to the compiler
add_definitions(${GTK4_CFLAGS_OTHER})
# Add an executable compiled from hello.c
add_executable(hello main.c)
# Link the target to the GTK+ libraries
target_link_libraries(hello ${GTK4_LIBRARIES})