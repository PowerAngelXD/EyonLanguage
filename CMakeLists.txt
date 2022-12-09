cmake_minimum_required(VERSION 3.24)
project(eyon)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SRC_FILES "main.cpp", "lexer/*.cpp",
        "parser/asts/*.cpp", "error/*.cpp")

add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES} )