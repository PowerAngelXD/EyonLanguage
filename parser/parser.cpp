//
// Created by BALL on 2022/12/11
//
#include "parser.h"

using namespace parser;

void Parser::parse() {
    if (!WholeExprNode::is(token_group, offset)) {} // WILL ERROR

    tempParser.parse();
}

WholeExprNode Parser::get() { return *tempParser.get(); }