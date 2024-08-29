cmake_minimum_required(VERSION 3.27)
project(forward_list)

set(CMAKE_CXX_STANDARD 17)

add_executable(forward_list main.cpp)

# Incluir Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Añadir el ejecutable para los tests
add_executable(ForwardListTests test_forward_list.cpp)

# Vincular Google Test con el ejecutable
target_link_libraries(ForwardListTests gtest gtest_main)