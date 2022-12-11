//
// Created by BALL on 2022/12/11
//
#include "add_expr.h"

using namespace ast;

std::string AddExprNode::to_string() {
    std::string ret = "AddExprNode: {[" + head.to_string() + ", ";
    for(size_t i = 0; i < ops.size(); i ++) {
        ret += ops[i].to_string() + ", ";
        ret += factors[i].to_string() + ", ";
    }
    ret.erase(ret.end() - 1, ret.end());
    ret += "]}";
    return ret;
}

bool AddExprNode::is(std::vector<lexer::Token> tg, int curr_pos) {
    return MulExprNode::is(tg, curr_pos);
}