//
// Created by BALL on 2022/12/12
//
#ifndef EYON_EXPR_AST_H
#define EYON_EXPR_AST_H

#include "../node_base.h"

#define init_default = nullptr;

namespace ast {
    // definitions
    class AddExprNode;
    //

    enum BasicOpKind {
        Plus, Sub, Mul, Div,
        Null // warn!
    };

    /// @brief Operators of multiplication and division operation (*, /)
    struct MulOpNode: public BasicNode {
        TokenNode *op init_default;

        using BasicNode::BasicNode;

        static bool is(std::vector<lexer::Token> tg, int curr_pos);

        /// @brief Get operator's kind
        /// @return ast::BasicOpKind
        BasicOpKind getOpKind();
    };

    struct AddOpNode: public BasicNode {
        TokenNode *op init_default;

        using BasicNode::BasicNode;

        static bool is(std::vector<lexer::Token> tg, int curr_pos);
    };

    /// @brief Basis of all expressions
    struct PrimExprNode: public BasicNode {
        TokenNode *content init_default;

        TokenNode *left init_default;
        AddExprNode *addexpr init_default;
        TokenNode *right init_default;

        using BasicNode::BasicNode;

        static bool is(std::vector<lexer::Token> tg, int curr_pos);

        lexer::TokenKind getKind();
    };

    struct MulExprNode: public BasicNode {
        PrimExprNode *head init_default;
        std::vector<PrimExprNode*> factors;
        std::vector<MulOpNode*> ops;

        using BasicNode::BasicNode;
        
        static bool is(std::vector<lexer::Token> tg, int curr_pos);
    };

    struct AddExprNode: public BasicNode {
        MulExprNode *head init_default;
        std::vector<MulExprNode*> factors;
        std::vector<AddOpNode*> ops;

        using BasicNode::BasicNode;

        static bool is(std::vector<lexer::Token> tg, int curr_pos);    
    };
}

#endif // !EYON_EXPR_AST_H