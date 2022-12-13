#include "lexer/lex.h"
#include "parser/parser.h"

int main() {
    lexer::Lexer lexer = lexer::Lexer("1+2*3");

    try {
        lexer.generate();
        parser::Parser parser(lexer.out, 0);
        parser.parse();
        auto a=1;
        std::cout<<a<<std::endl;
    }
    catch (lexer_error::NotCorrectNumberError& e) { e.printError(); }
    catch (lexer_error::StringUnCloseError& e) { e.printError(); }
    catch (lexer_error::IllegalSymbolError& e) { e.printError(); }
    return 0;
}
