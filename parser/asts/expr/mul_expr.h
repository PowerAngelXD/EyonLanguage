//
// Created by BALL on 2022/12/10
//
#ifndef EYON_MUL_EXPR_H
#define EYON_MUL_EXPR_H

#include "prim_expr.h"
#include "op/add_op.h"
#include "op/mul_op.h"

#define default_mul_expr_node = null_mul_expr_node

namespace ast { 
    struct MulExprNode: public BasicNode {
        PrimExprNode head default_prim_expr_node;
        std::vector<PrimExprNode> factors;
        std::vector<MulOpNode> ops;

        using BasicNode::BasicNode;
        
        std::string to_string() override;
        static bool is(std::vector<lexer::Token> tg, int curr_pos);
    };
    static MulExprNode null_mul_expr_node = MulExprNode(-1, -1);
}

#endif // !EYON_MUL_EXPR_H