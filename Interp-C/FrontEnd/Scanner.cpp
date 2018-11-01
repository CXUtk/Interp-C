//
// Created by DELL on 2018/11/1.
//

#include "Scanner.h"

Scanner::Scanner(const char *src) : src(src), lineNum(1), colNum(0) {

}

void Scanner::extract() {
	while(*src == ' '){
		src++;
	}
	if(!*src) {
		curToken.setType(TokenType::Eof);
		return;
	}
	int tk = *src;
	curToken.setValue(tk);
	if(isdigit(tk)){
		const char * prev = src;
		while(isdigit(*src)){
			src++;
		}
		std::string str(prev, src);
		curToken.setType(TokenType::NUM);
		curToken.setValue(std::stoi(str));
	}
	else if(tk == '+'){
		src++;
		curToken.setType(TokenType::Add);
	}
}

Token Scanner::nextToken() {
	extract();
	return curToken;
}

Scanner::~Scanner() {

}
