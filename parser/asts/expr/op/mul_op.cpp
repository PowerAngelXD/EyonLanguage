//
// Created by BALL on 2022/12/10.
//

#include "mul_op.h"

using namespace ast;

std::string MulOpNode::to_string() {
    return "MulOpNode: {" + op.to_string() + "}";
}

bool MulOpNode::is(std::vector<lexer::Token> tg, int curr_pos) {
    if (tg[curr_pos].content == "/" || "*") return true;
    else return false;
}

BasicOpKind MulOpNode::getOpKind() {
    if (op.content.content == "/") return BasicOpKind::Div;
    else if (op.content.content == "*") return BasicOpKind::Mul;
    return BasicOpKind::Null;
}  