//
// Created by BALL on 2022/12/11
//
#include "parser.h"

using namespace parser;

void Parser::parse() {
    if (!AddExprNode::is(token_group, offset)) {} // WILL ERROR

    tempParser.parse();
}

AddExprNode Parser::get() { return *tempParser.get(); }