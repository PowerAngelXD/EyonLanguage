//
// Created by BALL on 2022/12/14.
//

#include "basic_coder.h"

using namespace coder;

Code::Code(CodeKind k, int ln, int col, double v, void *hp):
    kind(k), val(v), heapPointer(hp), line(ln), column(col) {}

bool Code::operator!= (Code code) const {
    return this->kind != code.kind && static_cast<int>(this->val) != static_cast<int>(code.val);
}

bool Code::operator== (Code code) const {
    return this->kind == code.kind && static_cast<int>(this->val) == static_cast<int>(code.val);
}
