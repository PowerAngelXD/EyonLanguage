//
// Created by BALL on 2022/12/12
//
#ifndef EYON_EXPR_PARSER_H
#define EYON_EXPR_PARSER_H

#include "../parser_basic.h"

using namespace ast;

namespace parser {
    class PrimExprParser: public BasicParser {
        PrimExprNode *result = new PrimExprNode;
    public:
        using BasicParser::BasicParser;

        PrimExprParser& parse();
        PrimExprNode *get();
        size_t getOffset();
    };

    class MulExprParser: public BasicParser {
        MulExprNode *result = new MulExprNode;
    public:
        using BasicParser::BasicParser;

        MulExprParser& parse();
        MulExprNode *get();
        size_t getOffset();
    };

    class AddExprParser: public BasicParser {
        AddExprNode *result = new AddExprNode;
    public:
        using BasicParser::BasicParser;

        AddExprParser& parse();
        AddExprNode *get();
        size_t getOffset();
    };

    class WholeExprParser: public BasicParser {
        WholeExprNode *result = new WholeExprNode;
    public:
        using BasicParser::BasicParser;

        WholeExprParser& parse();
        WholeExprNode *get();
        size_t getOffset();
    };
}

#endif // !EYON_EXPR_PARSER_H