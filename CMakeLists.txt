cmake_minimum_required(VERSION 3.17)
project(Projekt_Statki)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projekt_Statki main.cpp Czesc_grywalna/Gracz.cpp Czesc_grywalna/Gracz.h Czesc_grywalna/Walka.cpp Czesc_grywalna/Walka.h)