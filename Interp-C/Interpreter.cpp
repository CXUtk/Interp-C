//
// Created by DELL on 2018/10/30.
//

#include <cstdio>
#include "Interpreter.h"

Interpreter::Interpreter() {

}

Interpreter::~Interpreter() {

}

void Interpreter::Parse(const char *code) {
    src = code;
    next();                  // get next token
    while (token > 0) {
        printf("token is: %c\n", token);
        next();
    }
}

int Interpreter::eval() {
    return 0;
}

void Interpreter::expression(int level) {

}

void Interpreter::next() {
    token = *src++;
}
