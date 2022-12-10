//
// Created by BALL on 2022/12/7.
//

#ifndef EYON_TOKEN_H
#define EYON_TOKEN_H
#include <iostream>
#include <string>
#include <vector>

namespace lexer {
    static std::vector<std::string> keywords = {"let", "if", "dynic", "static", "repeat", "loop", "until", "while", "for",
                                                "if", "else", "import", "typeof"};
    bool is_keyword(const std::string& str);

    static std::vector<char> symbols = {'=', '+', '-', '/', '*', 
                                        ',', '.', '?', ':', '|', 
                                        '!', '%', '^', '&', '=', 
                                        '@', ';', '(', ')', '[',
                                        ']', '{', '}'};
    bool is_symbol_char(char ch);

    enum TokenKind {
        Number, String, Ident,
        Keyword, Symbol, Eof, NullToken
    };
    std::string kind_to_string(TokenKind kind);

    struct Token {
        TokenKind kind = TokenKind::NullToken;
        std::string content = "NullToken";
        int line = 1;
        int column = 1;

        Token(TokenKind k, std::string c, int ln, int col);
        Token()=default;

        std::string to_string() const;
    };
    static Token null_token = {TokenKind::NullToken, "NullToken", -1, -1};
}

#endif //EYON_TOKEN_H
