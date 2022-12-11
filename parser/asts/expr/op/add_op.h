//
// Created by BALL on 2022/12/11
//
#ifndef EYON_ADD_OP_H
#define EYON_ADD_OP_H

#include "../../node_base.h"

#define default_add_op_node = null_add_op_node

namespace ast {
    struct AddOpNode: public BasicNode {
        TokenNode op default_token_node;

        using BasicNode::BasicNode;

        std::string to_string();
        static bool is(std::vector<lexer::Token> tg, int curr_pos);
    };
    static AddOpNode null_add_op_node = AddOpNode(-1, -1);
}

#endif // !EYON_ADD_OP_H