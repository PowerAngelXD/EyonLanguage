cmake_minimum_required(VERSION 3.24)
project(eyon)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Wimplicit-fallthrough -Wsequence-point -Wswitch-default -Wswitch-unreachable -Wswitch-enum -Wstringop-truncation -Wbool-compare -Wtautological-compare -Wfloat-equal -Wshadow=global -Wpointer-arith -Wpointer-compare -Wcast-align -Wcast-qual -Wwrite-strings -Wdangling-else -Wlogical-op -Wconversion -Werror")

file(GLOB SRC_FILES
        "main.cpp",
        "error/*.h", "error/*.cpp",
        "lexer/*.h", "lexer/*.cpp",
        "parser/asts/expr/*.h", "parser/asts/expr/*.cpp",
        "parser/asts/node_base.h", "parser/asts/node_base.cpp", "parser/asts/ast.h",
        "parser/parser.h", "parser/parser.cpp",
        "parser/parsers/*.h", "parser/parsers/*.cpp"
        "parser/parsers/expr/*.h", "parser/parsers/expr/*.cpp",
        "coder/basic_coder.h", "coder/basic_coder.cpp"
        "coder/expr/expr_coder.h", "coder/expr/expr_coder.cpp")

        
add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES} )