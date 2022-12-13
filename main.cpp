#include "lexer/lex.h"
#include "parser/parsers/expr/expr_parser.h"

int main() {
    lexer::Lexer lexer = lexer::Lexer("1+2~");

    try {
        lexer.generate();
        parser::AddExprParser addexpr(lexer.out);
        addexpr.parse();
        auto a=1;
        std::cout<<a<<std::endl;
    }
    catch (lexer_error::NotCorrectNumberError& e) { e.printError(); }
    catch (lexer_error::StringUnCloseError& e) { e.printError(); }
    catch (lexer_error::IllegalSymbolError& e) { e.printError(); }
    return 0;
}
