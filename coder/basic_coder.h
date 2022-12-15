//
// Created by BALL on 2022/12/14.
//

#ifndef EYON_BASIC_CODER_H
#define EYON_BASIC_CODER_H

#include "../parser/parser.h"

namespace coder {
    enum CodeKind {
        // VM operation
        push_num, push_str, push_bool,
        //

        // calc
        add, sub, mul, div,
        //

        // null
        null_kind
        //
    };

    struct Code {
        CodeKind kind = CodeKind::null_kind;
        double val = 0.0;
        void *heapPointer = nullptr;
        int line = -1, column = -1;

        Code(CodeKind k, int ln, int col, double v = 0.0, void *hp = nullptr);

        bool operator ==(Code code) const;
        bool operator !=(Code code) const;
    };

    struct ConstantPool {
        std::vector<std::string> stringRes;


    };
}

#endif //EYON_BASIC_CODER_H
