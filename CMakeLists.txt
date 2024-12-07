cmake_minimum_required(VERSION 3.29)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 23)

add_executable(Proyecto1 main.cpp
        includes/Usuario.h
        src/Usuario.cpp
        includes/Cliente.h
        includes/Administrador.h
        src/Cliente.cpp
        src/Administrador.cpp
)
