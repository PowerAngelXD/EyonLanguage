//
// Created by BALL on 2022/12/7.
//

#include "error.h"

error::ErrorBasic::ErrorBasic(std::string src, int ln, int col):
    source(src), line(ln), column(col) {}

std::string error::ErrorBasic::what() {
    return this->source;
}

std::tuple<int, int> error::ErrorBasic::getLineCol() {
    return {this->line, this->column};
}

void error::ErrorBasic::printError() {
    std::cout<<"Error: "<<std::endl;
    std::cout<<this->source<<std::endl;
    std::cout<<"line: "<<this->line<<"; column: "<<this->column<<std::endl;
}
