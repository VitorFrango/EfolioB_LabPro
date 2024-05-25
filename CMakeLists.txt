cmake_minimum_required(VERSION 3.15)
project(AF3 C)

set(CMAKE_C_STANDARD 99)

add_executable(AF3
        main.c
        menu.c
        grelha.c
        retangulo.c
        menu.h
        grelha.h
        retangulo.h)
