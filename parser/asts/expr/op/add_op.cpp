//
// Created by BALL on 2022/12/11
//
#include "add_op.h"

using namespace ast;

std::string AddOpNode::to_string() {
    return "AddOpNode: {" + op.to_string() + "}";
}

bool AddOpNode::is(std::vector<lexer::Token> tg, int curr_pos) {
    if (tg[curr_pos].content == "+"||"-") return true;
    else return false;
}