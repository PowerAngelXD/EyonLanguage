//
// Created by BALL on 2022/12/10.
//

#include "prim_expr.h"

using namespace ast;

bool PrimExprNode::is(std::vector<lexer::Token> tg, int curr_pos) {
    return TokenNode::is(tg, curr_pos) || tg[curr_pos].content == "(";
}

lexer::TokenKind PrimExprNode::getKind() {
    return content.content.kind;
}
