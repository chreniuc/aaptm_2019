cmake_minimum_required(VERSION 3.5)

project(aaptm_project_hca LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(aaptm_project_hca main.cpp
    dices_game.cpp
    dices_game.hpp
    )
