//
// Created by BALL on 2022/12/9.
//

#include "node_base.h"

using namespace ast;

// BasicNode
BasicNode::BasicNode(int ln, int col): line(ln), column(col) {}

std::string BasicNode::to_string() {}

bool BasicNode::is(std::vector<lexer::Token> tg, int curr_pos) {}

std::tuple<int, int> BasicNode::getLnCol() {
    return std::tuple<int, int>(this->line, this->column);
}

// TokenNode
TokenNode::TokenNode(lexer::Token c, int ln, int col): content(c), BasicNode(ln, col) {}

std::string TokenNode::to_string() { 
    return "TokenNode: { kind: " + lexer::kind_to_string(this->content.kind) + ", content" + content.content + "}";
}

bool TokenNode::is(std::vector<lexer::Token> tg, int curr_pos) {
    return true;
}