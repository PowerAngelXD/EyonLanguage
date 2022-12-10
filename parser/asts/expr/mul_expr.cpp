//
// Created by BALL on 2022/12/10
//
#include "mul_expr.h"

using namespace ast;

std::string MulExprNode::to_string() {
    std::string ret = "MulExprNode: {[" + head.to_string() + ", ";
    for(int i = 0; i < ops.size(); i ++) {
        ret += ops[i].to_string() + ", ";
        ret += factors[i].to_string() + ", ";
    }
    ret.erase(ret.end() - 1, ret.end());
    ret += "]}";
    return ret;
}

bool MulExprNode::is(std::vector<lexer::Token> tg, int curr_pos) {
    if (PrimExprNode::is(tg, curr_pos)) return true;
    else return false;
}