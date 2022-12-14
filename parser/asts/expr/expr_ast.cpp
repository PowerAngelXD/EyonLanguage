//
// Created by BALL on 2022/12/12
//
#include "expr_ast.h"

#include <utility>

using namespace ast;

// WholeExprNode
bool WholeExprNode::is(lexer::TokenGroup tg, size_t curr_pos) {
    if (AddExprNode::is(std::move(tg), curr_pos)) return true;
    else return false;
}
//

// AddOpNode
AddOpNode::AddOpNode(TokenNode *tok, int ln, int col):
        BasicNode(ln, col), op(tok) {}

bool AddOpNode::is(lexer::TokenGroup tg, size_t curr_pos) {
    if (tg[curr_pos].content == "+" || tg[curr_pos].content == "-") return true;
    else return false;
}

BasicOpKind AddOpNode::getOpKind() const {
    if (op->content->content == "+") return BasicOpKind::Plus;
    else if (op->content->content == "-") return BasicOpKind::Sub;
    return BasicOpKind::Null;
}
//

// MulOpNode
MulOpNode::MulOpNode(TokenNode *tok, int ln, int col) :
        BasicNode(ln, col), op(tok) {}

bool MulOpNode::is(lexer::TokenGroup tg, size_t curr_pos) {
    if (tg[curr_pos].content == "/" || tg[curr_pos].content == "*") return true;
    else return false;
}

BasicOpKind MulOpNode::getOpKind() const {
    if (op->content->content == "/") return BasicOpKind::Div;
    else if (op->content->content == "*") return BasicOpKind::Mul;
    return BasicOpKind::Null;
}  
//

// PrimExprNode
bool PrimExprNode::is(lexer::TokenGroup tg, size_t curr_pos) {
    return TokenNode::is(tg, curr_pos) || tg[curr_pos].content == "(";
}

lexer::TokenKind PrimExprNode::getKind() const {
    if (content != nullptr) return content->content->kind;
    else return left->content->kind; // If it is symbol, it not a unit prim expr
}
//

// MulExprNode
bool MulExprNode::is(lexer::TokenGroup tg, size_t curr_pos) {
    return TokenNode::is(std::move(tg), curr_pos);
}
//

// AddExprNode
bool AddExprNode::is(lexer::TokenGroup tg, size_t curr_pos) {
    return MulExprNode::is(std::move(tg), curr_pos);
}
//
