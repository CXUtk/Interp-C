//
// Created by DELL on 2018/10/30.
//

#ifndef INTERP_C_INTERPRETER_H
#define INTERP_C_INTERPRETER_H


#include "Token.h"

class Interpreter {
public:
    Interpreter();

    ~Interpreter();

    void Parse(const char *code);

private:
    void next();

    void expression(int level);

    int eval();


    //---------------DATA--------------
    const char *src;
    Token token;
    int line;
};


#endif //INTERP_C_INTERPRETER_H
