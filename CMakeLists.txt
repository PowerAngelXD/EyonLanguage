cmake_minimum_required(VERSION 3.24)
project(eyon)

set(CMAKE_CXX_STANDARD 20)

add_executable(eyon main.cpp lexer/token.cpp lexer/token.h
        lexer/lex.cpp lexer/lex.h
        error/lexer_error.cpp error/lexer_error.h error/error.cpp error/error.h)
