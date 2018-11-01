//
// Created by DELL on 2018/10/30.
//

#include <cstdio>
#include "Interpreter.h"
#include "FrontEnd/Parser.h"

Interpreter::Interpreter() {

}

Interpreter::~Interpreter() {

}

void Interpreter::Parse(const char *code) {
	Scanner scanner(code);
	Parser parser(&scanner);
	parser.parse();
}
