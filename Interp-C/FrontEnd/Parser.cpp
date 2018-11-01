//
// Created by DELL on 2018/11/1.
//

#include "Parser.h"

void Parser::parse() {
	while(!scanner->nextToken().isEOF()){
		printf("%s\n", scanner->currentToken().toString());
	}
}
