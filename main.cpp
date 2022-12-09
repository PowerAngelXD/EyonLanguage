#include "lexer/lex.h"

int main() {
    lexer::Lexer lexer = lexer::Lexer("dynic let a: String = \"hello!\"");

    try {
        lexer.generate();

        for (auto tok: lexer.out) {
            std::cout<< tok.to_string() <<std::endl;
        }
    }
    catch (lexer_error::NotCorrectNumberError e) { e.printError(); }
    catch (lexer_error::StringUnCloseError e) { e.printError(); }
    return 0;
}
