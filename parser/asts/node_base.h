//
// Created by BALL on 2022/12/9.
//

#ifndef EYON_NODE_BASE_H
#define EYON_NODE_BASE_H
#include "../../lexer/lex.h"
#include <memory>

#define default_token = lexer::null_token
#define default_token_node = ast::null_token_node

namespace ast {
    /**
     * @brief Foundation of all nodes
     * @attention Other nodes must inherit this node to generate an abstract syntax tree
    */
    struct BasicNode {
        BasicNode()=default;
        BasicNode(int ln, int col);

        virtual std::string to_string();
        static bool is();

        std::tuple<int, int> getLnCol();
    
    private:
        int line = 0;
        int column = 0;
    };

    /// @brief The most basic node, which is used to bear the Token
    struct TokenNode: public BasicNode {
        lexer::Token content default_token;
        
        // Inherit the constructor of the parent class
        using BasicNode::BasicNode;

        std::string to_string() override;
        static bool is(std::vector<lexer::Token> tg, int curr_pos);
    };
    static TokenNode null_token_node = TokenNode(-1, -1);
}

#endif // !EYON_NODE_BASE_H