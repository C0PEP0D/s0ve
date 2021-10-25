cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(csv)

# Build target
add_executable(csv main.cpp)
target_include_directories(csv PRIVATE .)

# Link modules
target_include_directories(csv PRIVATE ../../include)
# Link thirdparty
target_include_directories(csv PRIVATE ../../../../thirdparty/eigen)
