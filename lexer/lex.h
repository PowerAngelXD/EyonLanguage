//
// Created by BALL on 2022/12/7.
//

#ifndef EYON_LEX_H
#define EYON_LEX_H
#include "token.h"
#include "../error/lexer_error.h"

namespace lexer {
    struct Lexer {
        Lexer()=default;
        Lexer(std::string src);

        Token makeNumber();
        Token makeString();
        Token makeIdentifier();
        Token makeSymbol();
        void makeComment();

        void make(char chk);
        char next();
        char peekNext();
        void back();

        void generate();
        std::vector<Token> out;

    private:
        std::string source;
        int pos = 0;
        int column = 0, line = 1;
    };
}

#endif //EYON_LEX_H
