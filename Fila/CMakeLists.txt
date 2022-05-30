cmake_minimum_required(VERSION 3.21)
project(Fila C)

set(CMAKE_C_STANDARD 99)

add_executable(Fila main.c fila.h fila.c filaPrioridade.h filaPrioridade.c)
