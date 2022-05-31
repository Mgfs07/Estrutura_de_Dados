cmake_minimum_required(VERSION 3.21)
project(PilhaDinamica C)

set(CMAKE_C_STANDARD 99)

add_executable(PilhaDinamica main.c pilha.h pilha.c)
