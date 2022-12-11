//
// Created by BALL on 2022/12/9.
//

#include "node_base.h"

using namespace ast;

// BasicNode
BasicNode::BasicNode(int ln, int col): line(ln), column(col) {}

std::string BasicNode::to_string() { return "node"; }

bool BasicNode::is() { return true; }

std::tuple<int, int> BasicNode::getLnCol() {
    return {this->line, this->column};
}

// TokenNode
std::string TokenNode::to_string() {
    return "TokenNode: { kind: " + lexer::kind_to_string(this->content.kind) + ", content" + content.content + "}";
}

bool TokenNode::is(std::vector<lexer::Token> tg, int curr_pos) {
    return tg[curr_pos].line != -1;
}