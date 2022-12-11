//
// Created by BALL on 2022/12/10.
//

#ifndef EYON_MUL_OP_H
#define EYON_MUL_OP_H

#include "../../node_base.h"

#define default_mul_op_node = null_mul_op_node

namespace ast {
    enum BasicOpKind {
        Plus, Sub, Mul, Div
    };

    /// @brief Operators of multiplication and division operation (*, /)
    struct MulOpNode: public BasicNode {
        TokenNode op default_token_node;

        using BasicNode::BasicNode;

        std::string to_string() override;
        static bool is(std::vector<lexer::Token> tg, int curr_pos);

        /// @brief Get operator's kind
        /// @return ast::BasicOpKind
        BasicOpKind getOpKind();
    };
    static MulOpNode null_mul_op_node = MulOpNode(-1, -1);
}

#endif //EYON_QUARD_OP_H
