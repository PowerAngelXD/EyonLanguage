//
// Created by BALL on 2022/12/10.
//

#ifndef EYON_PRIM_EXPR_H
#define EYON_PRIM_EXPR_H
#include "../node_base.h"

#define default_prim_expr_node = ast::null_prim_expr_node

namespace ast {
    /// @brief Basis of all expressions
    struct PrimExprNode: public BasicNode {
        TokenNode content default_token_node;

        using BasicNode::BasicNode;

        std::string to_string() override;
        static bool is(std::vector<lexer::Token> tg, int curr_pos);

        lexer::TokenKind getKind();
    };
    static PrimExprNode null_prim_expr_node = PrimExprNode(-1, -1);
}


#endif //EYON_PRIM_EXPR_H
