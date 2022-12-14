//
// Created by BALL on 2022/12/14.
//

#include "parser_error.h"

#include <utility>

// UnexpectedTokenError
parser_error::UnexpectedTokenError::UnexpectedTokenError(std::string src, int ln, int col):
    error::ErrorBasic(std::move(src), ln, col) {}

void parser_error::UnexpectedTokenError::printError() {
    ERROR_HEAD_DISPLAY
    std::cout<<"UnexpectedToken Error"<<std::endl;
    std::cout<<"    The tree type being parsed is '" + source +"', but an unexpected TOKEN is given"<<std::endl;
    std::cout<<"At line: "<<line<<"; column: "<<column<<std::endl;
}
//