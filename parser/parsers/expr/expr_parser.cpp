//
// Created by BALL on 2022/12/12.
//
#include "expr_parser.h"

using namespace parser;

// PrimExprParser
PrimExprParser& PrimExprParser::parse() {
    if (!PrimExprNode::is(token_group, offset)) {
        throw parser_error::UnexpectedTokenError("PrimExpr", token_group[offset].line, token_group[offset].column);
    }

    auto head_token = next();
    *result = PrimExprNode(head_token->line, head_token->column);

    // Check if it is a '('
    if (head_token->content == "(") {
        result->expr = new WholeExprNode;

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
    if (!MulExprNode::is(token_group, offset)) {
        throw parser_error::UnexpectedTokenError("MulExpr", token_group[offset].line, token_group[offset].column);
    }

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
    if (!AddExprNode::is(token_group, offset)) {
        throw parser_error::UnexpectedTokenError("AddExpr", token_group[offset].line, token_group[offset].column);
    }

    auto temp_parser = MulExprParser(token_group, offset).parse();
    result->head = temp_parser.get();
    offset = temp_parser.getOffset();
    if (AddOpNode::is(token_group, offset)) {
        while (AddOpNode::is(token_group, offset)) {
            auto temp_op = next();
            result->ops.push_back(new AddOpNode(new TokenNode(temp_op), temp_op->line, temp_op->column));

            MulExprParser temp_mul(token_group, offset);
            temp_mul.parse();   // parse prim-expr node

            result->factors.push_back(temp_mul.get());
            offset = temp_mul.getOffset();
        }
    }

    return *this;
}

AddExprNode *AddExprParser::get() { return result; }

size_t AddExprParser::getOffset() { return offset; }
//

// WholeExprParser
WholeExprParser& WholeExprParser::parse() {
    if (AddExprNode::is(token_group, offset)) {
        auto temp_parser = AddExprParser(token_group, offset);
        offset = temp_parser.parse().getOffset();
        result->addexpr = temp_parser.get();
    }
    else {
        throw parser_error::UnexpectedTokenError("WholeExpr", token_group[offset].line, token_group[offset].column);
    }

    return *this;
}
WholeExprNode *WholeExprParser::get() { return result; }
size_t WholeExprParser::getOffset() { return offset; }
//
