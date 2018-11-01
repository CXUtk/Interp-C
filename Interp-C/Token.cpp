//
// Created by DELL on 2018/10/31.
//

#include <cstring>
#include "Token.h"

const char * Token::toString() {
	static char buffer[128];
	char typestr[20];
	switch (type){
		case TokenType::Eof:
			strcpy(typestr, "EOF");
			break;
		case TokenType::NUM:
			strcpy(typestr, "Number");
			break;
		case TokenType::FUNC:break;
		case TokenType::Sys:break;
		case TokenType::Glo:break;
		case TokenType::Loc:break;
		case TokenType::Id:break;
		case TokenType::Char:break;
		case TokenType::Else:break;
		case TokenType::Enum:break;
		case TokenType::If:break;
		case TokenType::Int:break;
		case TokenType::Return:break;
		case TokenType::Sizeof:break;
		case TokenType::While:break;
		case TokenType::Assign:break;
		case TokenType::Cond:break;
		case TokenType::Lor:break;
		case TokenType::Lan:break;
		case TokenType::Or:break;
		case TokenType::Xor:break;
		case TokenType::And:break;
		case TokenType::Eq:break;
		case TokenType::Ne:break;
		case TokenType::Lt:break;
		case TokenType::Gt:break;
		case TokenType::Le:break;
		case TokenType::Ge:break;
		case TokenType::Shl:break;
		case TokenType::Shr:break;
		case TokenType::Add:
			strcpy(typestr, "Add");
			break;
		case TokenType::Sub:break;
		case TokenType::Mul:break;
		case TokenType::Div:break;
		case TokenType::Mod:break;
		case TokenType::Inc:break;
		case TokenType::Dec:break;
		case TokenType::Brak:break;
	}
	if(type == TokenType::NUM) {
		sprintf_s(buffer, 128, "TOKEN(%s, %d)", typestr, value);
	}
	else{
		sprintf_s(buffer, 128, "TOKEN(%s, '%c')", typestr, value);
	}
	return buffer;
}

Token::~Token() {

}

Token::Token(TokenType type, int value) : type(type), value(value) {

}
