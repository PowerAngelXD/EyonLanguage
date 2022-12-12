//
// Created by BALL on 2022/12/11
//
#include "add_expr.h"

using namespace ast;

bool AddExprNode::is(std::vector<lexer::Token> tg, int curr_pos) {
    return MulExprNode::is(tg, curr_pos);
}