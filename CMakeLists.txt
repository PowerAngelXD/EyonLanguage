cmake_minimum_required(VERSION 3.24)
project(eyon)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SRC_FILES
        "main.cpp",
        "error/*.h", "error/*.cpp",
        "lexer/*.h", "lexer/*.cpp",
        "parser/asts/expr/*.h", "parser/asts/expr/*.cpp",
        "parser/asts/node_base.h", "parser/asts/node_base.cpp",
        "parser/asts/expr/op/*.h", "parser/asts/expr/op/*.cpp")
add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES} )