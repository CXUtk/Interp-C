//
// Created by DELL on 2018/10/30.
//

#include <cstdio>
#include "Interpreter.h"

Interpreter::Interpreter() : token(TokenType::Eof, 0) {

}

Interpreter::~Interpreter() {

}

void Interpreter::Parse(const char *code) {
    src = code;
    next();                  // get next token
    while (!token.isEOF()) {
        printf("token is: %s\n", token.toString());
        next();
    }
}

int Interpreter::eval() {
    return 0;
}

void Interpreter::expression(int level) {

}

void Interpreter::next() {
    if(*src == ' '){
        src++;
    }
    int tk = *src;
    token = Token(TokenType::Eof, 0);
    token.setValue(tk);
    if(isdigit(tk)){
        const char * prev = src;
        while(isdigit(*src)){
            src++;
        }
        std::string str(prev, src);
        token.setType(TokenType::NUM);
        token.setValue(std::stoi(str));
    }
    else if(tk == '+'){
        src++;
        token.setType(TokenType::Add);
    }


}
