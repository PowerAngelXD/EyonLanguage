//
// Created by BALL on 2022/12/9.
//

#ifndef EYON_NODE_BASE_H
#define EYON_NODE_BASE_H
#include "../../lexer/lex.h"

namespace ast {
    struct BasicNode {
        BasicNode()=default;
        BasicNode(int ln, int col);

        virtual std::string to_string();
        virtual bool is(std::vector<lexer::Token> tg, int curr_pos);

        std::tuple<int, int> getLnCol();
    
    private:
        int line = 0;
        int column = 0;
    };

    struct TokenNode: public BasicNode {
        lexer::Token content;
        
        // Inherit the constructor of the parent class
        using BasicNode::BasicNode;
        TokenNode(lexer::Token c, int ln, int col);

        std::string to_string() override;
        bool is(std::vector<lexer::Token> tg, int curr_pos) override;
    };
}

#endif // !EYON_NODE_BASE_H