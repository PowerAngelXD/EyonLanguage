//
// Created by BALL on 2022/12/9.
//

#include "node_base.h"

#include <utility>

using namespace ast;

// BasicNode
BasicNode::BasicNode(int ln, int col): line(ln), column(col) {}

bool BasicNode::is() { return true; }

std::tuple<int, int> BasicNode::getLnCol() {
    return {line, column};
}

// TokenNode
TokenNode::TokenNode(lexer::Token *tok, int ln, int col):
    BasicNode(ln, col), content(tok) {}
TokenNode::TokenNode(lexer::Token *tok):
    content(tok) {}

bool TokenNode::operator ==(const TokenNode& token_node) const {
    return content == token_node.content;
}

bool TokenNode::operator !=(const TokenNode& token_node) const {
    return content != token_node.content;
}

bool TokenNode::is(lexer::TokenGroup tg, size_t curr_pos) {
    return tg[curr_pos].line != -1;
}
