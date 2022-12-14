//
// Created by BALL on 2022/12/11
//
#ifndef EYON_PARSER_H
#define EYON_PARSER_H

#include "parsers/all_parser.h"

namespace parser {
    class Parser: public BasicParser{
        WholeExprParser tempParser = WholeExprParser(token_group, offset);
    public:
        using BasicParser::BasicParser;

        void parse();
        WholeExprNode get();
    };
}

#endif // !EYON_PARSER_H