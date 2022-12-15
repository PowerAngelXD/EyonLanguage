//
// Created by BALL on 2022/12/14.
//

#ifndef EYON_EXPR_CODER_H
#define EYON_EXPR_CODER_H

#include "../basic_coder.h"

namespace coder {
    class ExprCoder {
        WholeExprNode expr;
        std::vector<Code> codes;
        ConstantPool constantPool;
    public:
        ExprCoder()=default;
        ExprCoder(WholeExprNode e);

        void visitPrimExprNode(PrimExprNode node);
        void visitMulOpNode(MulOpNode node);
        void visitAddOpNode(AddOpNode node);
        void visitMulExprNode(MulExprNode node);
        void visitAddExprNode(AddExprNode node);

        void visit();
    };
}

#endif //EYON_EXPR_CODER_H
