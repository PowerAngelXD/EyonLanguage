//
// Created by BALL on 2022/12/10
//
#ifndef EYON_MUL_EXPR_H
#include "prim_expr.h"
#include "op/mul_op.h"

namespace ast { 
    struct MulExprNode: public BasicNode {
        PrimExprNode head default_prim_expr_node;
        std::vector<PrimExprNode> factors;
        std::vector<MulOpNode> ops;

        using BasicNode::BasicNode;
        
        std::string to_string() override;
        static bool is(std::vector<lexer::Token> tg, int curr_pos);
    };
}

#endif // !EYON_MUL_EXPR_H