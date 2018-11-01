//
// Created by DELL on 2018/11/1.
//

#ifndef INTERP_C_PARSER_H
#define INTERP_C_PARSER_H
#include "Scanner.h"

class Parser {
public:
	Parser(Scanner * scanner) : scanner(scanner) {}
	void parse();

private:
	Scanner * scanner;
};


#endif //INTERP_C_PARSER_H
