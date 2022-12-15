//
// Created by BALL on 2022/12/14.
//

#include "expr_coder.h"

using namespace coder;

ExprCoder::ExprCoder(WholeExprNode e) {
    expr = e;
}

void ExprCoder::visitPrimExprNode(PrimExprNode node) {
    if (node.content != nullptr) {
        auto token = node.content->content;

        if (token->kind == lexer::TokenKind::Number) {
            if (token->content.find('.')) {
                codes.emplace_back(CodeKind::push_num, token->line, token->column, std::stof(token->content));
            }
            else {
                codes.emplace_back(CodeKind::push_num, token->line, token->column, std::stoi(token->content));
            }
        }

        else if (token->kind == lexer::TokenKind::String) {
            constantPool.stringRes.emplace_back(token->content);
            codes.emplace_back(CodeKind::push_str, token->line, token->column, constantPool.stringRes.size() - 1);
        }

        else if (token->kind == lexer::TokenKind::Bool) {
            codes.emplace_back(CodeKind::push_bool, token->line, token->column, std::stoi(token->content));
        }
    }
}
void ExprCoder::visitMulOpNode(MulOpNode node) {
    if (node.op->content->content == "*") {
        codes.emplace_back(CodeKind::mul, node.op->content->line, node.op->content->column);
    }
    else if (node.op->content->content == "/") {
        codes.emplace_back(CodeKind::div, node.op->content->line, node.op->content->column);
    }
}
void ExprCoder::visitAddOpNode(AddOpNode node) {
    if (node.op->content->content == "+") {
        codes.emplace_back(CodeKind::add, node.op->content->line, node.op->content->column);
    }
    else if (node.op->content->content == "-") {
        codes.emplace_back(CodeKind::sub, node.op->content->line, node.op->content->column);
    }
}

void ExprCoder::visit() {

}