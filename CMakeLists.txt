cmake_minimum_required(VERSION 3.21)
project(Projekt_1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Projekt_1 eratosthenes.c bitset.c error.c bitset.h eratosthenes.h error.h ppm.c ppm.h steg-decode.c)
target_link_libraries(Projekt_1 m)
