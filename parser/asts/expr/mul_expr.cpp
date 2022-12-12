//
// Created by BALL on 2022/12/10
//
#include "mul_expr.h"

using namespace ast;

bool MulExprNode::is(std::vector<lexer::Token> tg, int curr_pos) {
    if (PrimExprNode::is(tg, curr_pos)) return true;
    else return false;
}