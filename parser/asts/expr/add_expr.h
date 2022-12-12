//
// Created by BALL on 2022/12/11
//
#ifndef EYON_ADD_EXPR_h
#define EYON_ADD_EXPR_H

#include "mul_expr.h"

#define default_add_expr_node = null_add_expr_node

namespace ast {
    struct AddExprNode: public BasicNode {
        MulExprNode head default_mul_expr_node;
        std::vector<MulExprNode> factors;
        std::vector<AddOpNode> ops;

        using BasicNode::BasicNode;

        static bool is(std::vector<lexer::Token> tg, int curr_pos);    
    };
    static AddExprNode null_add_expr_node = AddExprNode(-1, -1);
}

#endif // !EYON_ADD_EXPR_h