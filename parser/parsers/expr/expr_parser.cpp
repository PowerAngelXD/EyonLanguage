//
// Created by BALL on 2022/12/12.
//
#include "expr_parser.h"

using namespace parser;

// PrimExprParser
PrimExprParser& PrimExprParser::parse() {
    if (!PrimExprNode::is(token_group, offset)) {} // TODO: WILL ERROR

    auto head_token = next();
    *result = PrimExprNode(head_token->line, head_token->column);

    // Check if it is a '('
    if (head_token->content == "(") {
        
    }
    else {
        *result->content = TokenNode(head_token, result->content->content->line, result->content->content->column);
    }

    return *this;
}

PrimExprNode *PrimExprParser::get() { return result; }

size_t PrimExprParser::getOffset() { return offset; }
//

// MulExprParser
MulExprParser& MulExprParser::parse() {
    if (!MulExprNode::is(token_group, offset)) {} // TODO: WILL ERROR

    auto temp_parser = PrimExprParser(token_group, offset).parse();
    result->head = temp_parser.get();
    offset = temp_parser.getOffset();
    if (MulOpNode::is(token_group, offset)) {
        while (MulOpNode::is(token_group, offset)) {
            auto temp_op = next();
            result->ops.push_back(new MulOpNode(new TokenNode(temp_op), temp_op->line, temp_op->column));

            if (!PrimExprNode::is(token_group, offset)) {} // TODO: WILL ERROR
            PrimExprParser temp_prim(token_group, offset);
            temp_prim.parse();   // parse prim-expr node

            result->factors.push_back(temp_prim.get());
        }
    }
    return *this;
}

MulExprNode *MulExprParser::get() { return result; }

size_t MulExprParser::getOffset() { return offset; }
//

// AddExprParser
AddExprParser& AddExprParser::parse() {
    if (!AddExprNode::is(token_group, offset)) {} // TODO: WILL ERROR

    auto temp_parser = MulExprParser(token_group, offset).parse();
    result->head = temp_parser.get();
    offset = temp_parser.getOffset();
    if (AddOpNode::is(token_group, offset)) {
        while (AddOpNode::is(token_group, offset)) {
            auto temp_op = next();
            result->ops.push_back(new AddOpNode(new TokenNode(temp_op), temp_op->line, temp_op->column));

            if (!MulExprNode::is(token_group, offset)) {} // TODO: WILL ERROR
            MulExprParser temp_mul(token_group, offset);
            temp_mul.parse();   // parse prim-expr node

            result->factors.push_back(temp_mul.get());
        }
    }

    return *this;
}

AddExprNode *AddExprParser::get() { return result; }

size_t AddExprParser::getOffset() { return offset; }
//
