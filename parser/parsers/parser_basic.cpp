//
// Created by BALL on 2022/12/12
//
#include "parser_basic.h"

using namespace parser;

BasicParser::BasicParser(lexer::TokenGroup tg, size_t o):
        token_group(std::move(tg)), offset(o) {}


lexer::Token *BasicParser::peek(size_t p) {
    return new lexer::Token(token_group[p != 0 ? offset + p : offset + 1]);
}

lexer::Token *BasicParser::next() {
    return new lexer::Token(token_group[offset ++]);
}

lexer::Token *BasicParser::back() {
    return new lexer::Token(token_group[offset ++]);
}