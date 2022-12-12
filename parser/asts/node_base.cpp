//
// Created by BALL on 2022/12/9.
//

#include "node_base.h"

using namespace ast;

// BasicNode
BasicNode::BasicNode(int ln, int col): line(ln), column(col) {}

bool BasicNode::is() { return true; }

std::tuple<int, int> BasicNode::getLnCol() {
    return {this->line, this->column};
}

// TokenNode
bool TokenNode::operator ==(TokenNode token_node) {
    return this->content == token_node.content;
}

bool TokenNode::operator !=(TokenNode token_node) {
    return this->content != token_node.content;
}

bool TokenNode::is(std::vector<lexer::Token> tg, int curr_pos) {
    return tg[curr_pos].line != -1;
}