//
// Created by BALL on 2022/12/12
//
#include "expr_ast.h"

using namespace ast;

// AddOpNode
bool AddOpNode::is(std::vector<lexer::Token> tg, int curr_pos) {
    if (tg[curr_pos].content == "+"||"-") return true;
    else return false;
}
//

// MulOpNode
bool MulOpNode::is(std::vector<lexer::Token> tg, int curr_pos) {
    if (tg[curr_pos].content == "/" || "*") return true;
    else return false;
}

BasicOpKind MulOpNode::getOpKind() {
    if (op->content.content == "/") return BasicOpKind::Div;
    else if (op->content.content == "*") return BasicOpKind::Mul;
    return BasicOpKind::Null;
}  
//

// PrimExprNode
bool PrimExprNode::is(std::vector<lexer::Token> tg, int curr_pos) {
    return TokenNode::is(tg, curr_pos) || tg[curr_pos].content == "(";
}

lexer::TokenKind PrimExprNode::getKind() {
    return content->content.kind;
}
//

// MulExprNode
bool MulExprNode::is(std::vector<lexer::Token> tg, int curr_pos) {
    if (PrimExprNode::is(tg, curr_pos)) return true;
    else return false;
}
//

// AddExprNode
bool AddExprNode::is(std::vector<lexer::Token> tg, int curr_pos) {
    return MulExprNode::is(tg, curr_pos);
}
//