#include <iostream>
#include <vector>

#include "CompilerParser.h"
#include "Token.h"

using namespace std;

int main(int argc, char *argv[]) {
    /* Tokens for:
     *     class MyClass {
     *
     *     }
     */
    vector<Token*> tokens;
    tokens.push_back(new Token("keyword","class"));
    tokens.push_back(new Token("identifier","Main"));
    tokens.push_back(new Token("symbol","{"));

    tokens.push_back(new Token("keyword", "static"));
    tokens.push_back(new Token("keyword", "int"));
    tokens.push_back(new Token("identifier", "a"));
    tokens.push_back(new Token("symbol", ";"));

    tokens.push_back(new Token("keyword","function"));
    tokens.push_back(new Token("keyword","void"));
    tokens.push_back(new Token("identifier","test"));
    tokens.push_back(new Token("symbol","("));

    tokens.push_back(new Token("keyword", "int")); 
    tokens.push_back(new Token("identifier", "a")); 
    tokens.push_back(new Token("symbol", ",")); 
    tokens.push_back(new Token("keyword", "char")); 
    tokens.push_back(new Token("identifier", "b")); 

    tokens.push_back(new Token("symbol",")"));

    tokens.push_back(new Token("symbol","{"));

    tokens.push_back(new Token("keyword", "var")); 
    tokens.push_back(new Token("keyword", "int")); 
    tokens.push_back(new Token("identifier", "a")); 
    tokens.push_back(new Token("symbol", ";")); 

    tokens.push_back(new Token("keyword", "let")); 
    tokens.push_back(new Token("identifier", "a")); 
    tokens.push_back(new Token("symbol", "=")); 
    tokens.push_back(new Token("integerConstant", "1")); 
    tokens.push_back(new Token("symbol", ";")); 

    tokens.push_back(new Token("keyword", "do")); 
    tokens.push_back(new Token("keyword", "skip")); 
    tokens.push_back(new Token("symbol", ";")); 

    tokens.push_back(new Token("keyword","while"));
    tokens.push_back(new Token("symbol","("));

    tokens.push_back(new Token("integerConstant","1"));
    tokens.push_back(new Token("symbol","+"));
    tokens.push_back(new Token("symbol","("));
    tokens.push_back(new Token("identifier","a"));
    tokens.push_back(new Token("symbol","-"));
    tokens.push_back(new Token("identifier","b"));
    tokens.push_back(new Token("symbol",")"));

    tokens.push_back(new Token("symbol",")"));
    tokens.push_back(new Token("symbol","{"));
    tokens.push_back(new Token("keyword", "let")); 
    tokens.push_back(new Token("identifier", "b")); 
    tokens.push_back(new Token("symbol", "=")); 
    tokens.push_back(new Token("integerConstant", "1")); 
    tokens.push_back(new Token("symbol", ";")); 
    tokens.push_back(new Token("symbol","}"));

    tokens.push_back(new Token("keyword","if"));
    tokens.push_back(new Token("symbol","("));
    tokens.push_back(new Token("keyword","skip"));
    tokens.push_back(new Token("symbol",")"));
    tokens.push_back(new Token("symbol","{"));
    tokens.push_back(new Token("symbol","}"));
    tokens.push_back(new Token("keyword","else"));
    tokens.push_back(new Token("symbol","{"));
    tokens.push_back(new Token("symbol","}"));

    tokens.push_back(new Token("keyword", "return")); 
    tokens.push_back(new Token("keyword", "skip")); 
    tokens.push_back(new Token("symbol", ";")); 

    tokens.push_back(new Token("symbol","}"));
    tokens.push_back(new Token("symbol","}"));

    // tokens.push_back(new Token("keyword","class"));
    // tokens.push_back(new Token("identifier","Main"));
    // tokens.push_back(new Token("symbol","{"));
    // tokens.push_back(new Token("keyword","static"));
    // tokens.push_back(new Token("keyword","int"));
    // tokens.push_back(new Token("identifier","test"));
    // tokens.push_back(new Token("symbol",";"));
    // tokens.push_back(new Token("keyword","static"));
    // tokens.push_back(new Token("keyword","int"));
    // tokens.push_back(new Token("identifier","test2"));
    // tokens.push_back(new Token("symbol",";"));
    // tokens.push_back(new Token("keyword","function"));
    // tokens.push_back(new Token("keyword","void"));
    // tokens.push_back(new Token("identifier","test3"));
    // tokens.push_back(new Token("symbol","("));
    // tokens.push_back(new Token("symbol",")"));
    // tokens.push_back(new Token("symbol","{"));
    // tokens.push_back(new Token("symbol","}"));
    // tokens.push_back(new Token("keyword","function"));
    // tokens.push_back(new Token("keyword","void"));
    // tokens.push_back(new Token("identifier","test4"));
    // tokens.push_back(new Token("symbol","("));
    // tokens.push_back(new Token("symbol",")"));
    // tokens.push_back(new Token("symbol","{"));
    // tokens.push_back(new Token("symbol","}"));
    // tokens.push_back(new Token("symbol","}"));



    // tokens.push_back(new Token("keyword", "function")); 
    // tokens.push_back(new Token("keyword", "void")); 
    // tokens.push_back(new Token("identifier", "myFunc")); 
    // tokens.push_back(new Token("symbol", "(")); 
    // tokens.push_back(new Token("keyword", "int")); 
    // tokens.push_back(new Token("identifier", "a")); 
    // tokens.push_back(new Token("symbol", ")")); 
    // tokens.push_back(new Token("symbol", "{")); 
    // tokens.push_back(new Token("keyword", "var")); 
    // tokens.push_back(new Token("keyword", "int")); 
    // tokens.push_back(new Token("identifier", "a")); 
    // tokens.push_back(new Token("symbol", ";")); 
    // tokens.push_back(new Token("keyword", "let")); 
    // tokens.push_back(new Token("identifier", "a")); 
    // tokens.push_back(new Token("symbol", "=")); 
    // tokens.push_back(new Token("integerConstant", "1")); 
    // tokens.push_back(new Token("symbol", ";")); 
    // tokens.push_back(new Token(" ", "}"));


    // tokens.push_back(new Token("keyword","class"));
    // tokens.push_back(new Token("identifier","Main"));
    // tokens.push_back(new Token("symbol","{"));
    // tokens.push_back(new Token("keyword","function"));
    // tokens.push_back(new Token("keyword","void"));
    // tokens.push_back(new Token("identifier","test"));
    // tokens.push_back(new Token("symbol","("));
    // tokens.push_back(new Token("symbol",")"));
    // tokens.push_back(new Token("symbol","{"));
    // tokens.push_back(new Token("symbol","}"));
    // tokens.push_back(new Token("symbol","}"));



    // tokens.push_back(new Token("keyword","class"));
    // tokens.push_back(new Token("identifier","Main"));
    // tokens.push_back(new Token("symbol","{"));
    // tokens.push_back(new Token("symbol","}"));

    try {
        CompilerParser parser(tokens);
        ParseTree* result = parser.compileProgram();
        if (result != NULL){
            cout << result->tostring() << endl;
        }
    } catch (ParseException e) {
        cout << "Error Parsing!" << endl;
    }
}