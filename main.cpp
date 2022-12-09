#include "lexer/lex.h"

int main() {
    lexer::Lexer lexer = lexer::Lexer("dynic let a: String = \"hello!");

    try {
        lexer.generate();
    }
    catch (lexer_error::NotCorrectNumberError e) { e.printError(); }
    catch (lexer_error::StringUnCloseError e) { e.printError(); }

    for (auto tok: lexer.out) {
        std::cout<< tok.to_string() <<std::endl;
    }
    return 0;
}
