//
// Created by BALL on 2022/12/12
//
#ifndef EYON_PARSER_BASIC_H
#define EYON_PARSER_BASIC_H
#include "../asts/ast.h"

namespace parser {
    class BasicParser {
    protected:
        lexer::TokenGroup token_group;
        size_t offset {};
    public:
        BasicParser()=default;
        BasicParser(lexer::TokenGroup tg, size_t o = 0);

        /**
         * @brief The method of obtaining the next token with the offset unchanged
         * 
         * @param p steps
         * @return lexer::Token 
         */
        lexer::Token *peek(size_t p);
        /**
         * @brief Offset gets the next token without restoring
         * 
         * @return lexer::Token 
         */
        lexer::Token *next();
        /**
         * @brief Offset gets the back token without restoring
         * 
         * @return lexer::Token 
         */
        lexer::Token *back();
    };
}

#endif // !EYON_PARSER_BASIC_H