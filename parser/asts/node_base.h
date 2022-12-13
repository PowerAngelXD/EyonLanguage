//
// Created by BALL on 2022/12/9.
//

#ifndef EYON_NODE_BASE_H
#define EYON_NODE_BASE_H
#include "../../lexer/lex.h"
#include <memory>

namespace ast {
    /**
     * @brief Foundation of all nodes
     * @attention Other nodes must inherit this node to generate an abstract syntax tree
    */
    struct BasicNode {
        BasicNode()=default;
        BasicNode(int ln, int col);

        static bool is();

        std::tuple<int, int> getLnCol();

    protected:
        int line = 0;
        int column = 0;
    };

    /// @brief The most basic node, which is used to bear the Token
    struct TokenNode: public BasicNode {
        lexer::Token *content = new lexer::Token;
        
        // Inherit the constructor of the parent class
        using BasicNode::BasicNode;
        TokenNode(lexer::Token *tok, int ln, int col);
        TokenNode(lexer::Token *tok);

        bool operator ==(const TokenNode& token_node);
        bool operator !=(const TokenNode& token_node);

        static bool is(lexer::TokenGroup tg, size_t curr_pos);
    };
}

#endif // !EYON_NODE_BASE_H