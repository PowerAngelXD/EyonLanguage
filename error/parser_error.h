//
// Created by BALL on 2022/12/14.
//

#ifndef EYON_PARSER_ERROR_H
#define EYON_PARSER_ERROR_H

#include "error.h"

namespace parser_error {
    struct UnexpectedTokenError: public error::ErrorBasic {
        UnexpectedTokenError(std::string src, int ln, int col);

        void printError() override;
    };
}

#endif //EYON_PARSER_ERROR_H
