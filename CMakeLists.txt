cmake_minimum_required(VERSION 3.29)
project(BISMA C)

set(CMAKE_C_STANDARD 23)

add_executable(BISMA main.c
        Procedur.h
        Border.h
        DeklarasiTipeData.h
        ArrowKey.h
        Login.h)
