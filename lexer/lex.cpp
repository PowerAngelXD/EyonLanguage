//
// Created by BALL on 2022/12/7.
//

#include "lex.h"
#include <utility>

using namespace lexer;

Lexer::Lexer(std::string src) {
    this->source = std::move(src);
}

char Lexer::next() {
    char ch = source[++ pos];
    if (ch == '\n') {
        this->column = 1;
        this->line ++;
    }
    else this->column ++;

    return ch;
}

char Lexer::peekNext() {
    return source[pos + 1];
}

void Lexer::back() {
    char ch = source[-- pos];
    if (ch == '\n') {
        this->column = 1;
        this->line --;
    }
    else this->column --;
}

Token Lexer::makeNumber() {
    char chk = this->source[this->pos];
    if (!isdigit(chk)) {}

    std::string content;
    bool _dot_check = false;
    for (; this->pos < this->source.size(); chk = this->next()) {
        if (isdigit(chk)) content.push_back(chk);
        else if (chk == '.' && !_dot_check) {
            _dot_check = true;
            content.push_back(chk);
        }
        else if (chk == '.' && _dot_check) {
            content.push_back(chk);
            throw lexer_error::NotCorrectNumberError(content, this->line, this->column);
        }
        else break;
    }
    back();

    return {TokenKind::Number, content, this->line, this->column};
}

Token Lexer::makeIdentifier() {
    char chk = this->source[this->pos];
    if (!isalpha(chk)) {}

    std::string content;
    for(; this->pos < this->source.size(); chk = this->next()) {
        if (isalpha(chk) || isdigit(chk) || chk == '_') content.push_back(chk);
        else break;
    }
    back();

    return {
        is_keyword(content)?TokenKind::Keyword:TokenKind::Ident,
        content,
        this->line,
        this->column
    };
}

Token Lexer::makeSymbol() {
    char chk = this->source[this->pos];
    if (!is_symbol_char(chk)) {}

    std::string content;
    switch (chk) {
        case '(':
        case ')':
        case '[':
        case ']':
        case '{':
        case '}': { content.push_back(chk); this->next(); break; }
    
        default: {
            for (; this->pos < this->source.size(); chk = this->next()) {
                if (is_symbol_char(chk)) content.push_back(chk);
                else break;
            }
            break;
        }
    }
    back();

    return {TokenKind::Symbol, content, this->line, this->column};
}

Token Lexer::makeString() {
    char chk = this->source[this->pos];
    if (chk != '"') {}

    std::string content;
    chk = this->next();
    for (; this->pos < this->source.size(); chk = this->next()) {
        if (chk != '"' && this->pos >= this->source.size() - 1) {
            throw lexer_error::StringUnCloseError(content, this->line, this->column);
        }

        if (chk == '"') break;
        else content.push_back(chk);
    }

    return {TokenKind::String, content, this->line, this->column};
}

void Lexer::makeComment() {
    char chk = this->source[this->pos];

    std::string debug;
    for (; this->pos < this->source.size(); chk = this->next()) {
        if (chk == '\n') break;
        debug.push_back(this->next());
    }
    this->next();
}

void Lexer::make(char chk) {
    if (chk == '/' && this->source[this->pos + 1] == '/') {
        makeComment();
        return;
    }

    if (isdigit(chk)) this->out.push_back(makeNumber());
    else if (isalpha(chk) || chk == '_') this->out.push_back(makeIdentifier());
    else if (is_symbol_char(chk)) this->out.push_back(makeSymbol());
    else if (chk == '"') this->out.push_back(makeString());
    else {} // TODO: ERROR
}

void Lexer::generate() {
    char chk = this->source[this->pos];
    for (; this->pos < this->source.size(); chk = this->next()) {
        this->make(chk);
    }
    auto a=1;
}

