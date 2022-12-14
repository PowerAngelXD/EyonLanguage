//
// Created by BALL on 2022/12/12
//
#ifndef EYON_EXPR_AST_H
#define EYON_EXPR_AST_H

#include "../node_base.h"

namespace ast {
    // definitions
    struct AddExprNode;
    struct WholeExprNode;
    //

    enum BasicOpKind {
        Plus, Sub, Mul, Div,
        Null // warn!
    };

    /// @brief Operators of multiplication and division operation (*, /)
    struct MulOpNode: public BasicNode {
        TokenNode *op = new TokenNode;

        using BasicNode::BasicNode;
        MulOpNode(TokenNode *tok, int ln, int col);

        static bool is(lexer::TokenGroup tg, size_t curr_pos);

        /**
         * @brief Get operator's kind
         * @return ast::BasicOpKind
         */
        [[nodiscard]] BasicOpKind getOpKind() const;
    };

    struct AddOpNode: public BasicNode {
        TokenNode *op = new TokenNode;

        using BasicNode::BasicNode;
        AddOpNode(TokenNode *tok, int ln, int col);

        static bool is(lexer::TokenGroup tg, size_t curr_pos);

        /**
         * @brief Get operator's kind
         * @return ast::BasicOpKind
         */
        [[nodiscard]] BasicOpKind getOpKind() const;
    };

    /// @brief Basis of all expressions
    struct PrimExprNode: public BasicNode {
        TokenNode *content = new TokenNode;

        TokenNode *left = new TokenNode;
        WholeExprNode *expr = nullptr;
        TokenNode *right = new TokenNode;

        using BasicNode::BasicNode;

        static bool is(lexer::TokenGroup tg, size_t curr_pos);

        [[nodiscard]] lexer::TokenKind getKind() const;
    };

    struct MulExprNode: public BasicNode {
        PrimExprNode *head = new PrimExprNode;
        std::vector<PrimExprNode*> factors;
        std::vector<MulOpNode*> ops;

        using BasicNode::BasicNode;
        
        static bool is(lexer::TokenGroup tg, size_t curr_pos);
    };

    struct AddExprNode: public BasicNode {
        MulExprNode *head = new MulExprNode;
        std::vector<MulExprNode*> factors;
        std::vector<AddOpNode*> ops;

        using BasicNode::BasicNode;

        static bool is(lexer::TokenGroup tg, size_t curr_pos);
    };

    struct WholeExprNode: public BasicNode {
        AddExprNode* addexpr = new AddExprNode;

        using BasicNode::BasicNode;

        static bool is(lexer::TokenGroup tg, size_t curr_pos);
    };
}

#endif // !EYON_EXPR_AST_H