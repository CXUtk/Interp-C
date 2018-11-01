//
// Created by DELL on 2018/10/30.
//

#ifndef INTERP_C_INTERPRETER_H
#define INTERP_C_INTERPRETER_H


#include "FrontEnd/Token.h"
#include "FrontEnd/Scanner.h"

class Interpreter {
public:
    Interpreter();

    ~Interpreter();

    void Parse(const char *code);

private:

    //---------------DATA--------------
};


#endif //INTERP_C_INTERPRETER_H
