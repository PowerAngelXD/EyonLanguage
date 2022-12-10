//
// Created by BALL on 2022/12/7.
//

#include "lexer_error.h"

#include <utility>

lexer_error::NotCorrectNumberError::NotCorrectNumberError(std::string src, int line, int col) :
    ErrorBasic(std::move(src),line, col) {}

void lexer_error::NotCorrectNumberError::printError() {
    ERROR_HEAD_DISPLAY
    std::cout<<"NotCorrectNumberError Error"<<std::endl;
    std::cout<<"    Provide the number text: '"<<this->source<<"' is not a correct number format!"<<std::endl;
    std::cout<<"At line: "<<this->line<<"; column: "<<this->column<<std::endl;
}

//

lexer_error::StringUnCloseError::StringUnCloseError(std::string src, int ln, int col) :
    ErrorBasic(std::move(src), ln, col) {}

void lexer_error::StringUnCloseError::printError() {
    ERROR_HEAD_DISPLAY
    std::cout<<"StringUnClose Error"<<std::endl;
    std::cout<<"    String text: '"<<this->source<<"' is not closed!"<<std::endl;
    std::cout<<"At line: "<<this->line<<"; column: "<<this->column<<std::endl;
}
