//
// Created by DELL on 2018/10/31.
//

#include <cstring>
#include "Token.h"

std::map<std::string, TokenType> Token::KeyWord = {
{"if",     TokenType::If},
{"else",   TokenType::Else},
{"return", TokenType::Return},
};

const int BUFFER_SIZE = 256;

const char *Token::toString() {
	static char buffer[BUFFER_SIZE];
	char typestr[25];
	switch (type) {
		case TokenType::Eof:
			strcpy(typestr, "EOF");
			break;
		case TokenType::NUM:
			strcpy(typestr, "Number");
			break;
		case TokenType::FUNC:
			break;
		case TokenType::Sys:
			break;
		case TokenType::Glo:
			break;
		case TokenType::Loc:
			break;
		case TokenType::Id:
			strcpy(typestr, "Identifier");
			break;
		case TokenType::Char:
			break;
		case TokenType::Else:
			break;
		case TokenType::Enum:
			break;
		case TokenType::If:
			strcpy(typestr, "IF");
			break;
		case TokenType::Int:
			break;
		case TokenType::Return:
			strcpy(typestr, "Return");
			break;
		case TokenType::Sizeof:
			break;
		case TokenType::While:
			break;
		case TokenType::Assign:
			break;
		case TokenType::Cond:
			break;
		case TokenType::Lor:
			break;
		case TokenType::Land:
			strcpy(typestr, "Logic And");
			break;
		case TokenType::Or:
			break;
		case TokenType::Xor:
			break;
		case TokenType::And:
			strcpy(typestr, "And");
			break;
		case TokenType::Eq:
			break;
		case TokenType::Ne:
			break;
		case TokenType::Lt:
			strcpy(typestr, "Less");
			break;
		case TokenType::Gt:
			strcpy(typestr, "Greater");
			break;
		case TokenType::Le:
			break;
		case TokenType::Ge:
			strcpy(typestr, "Greater Equal");
			break;
		case TokenType::Shl:
			break;
		case TokenType::Shr:
			break;
		case TokenType::Add:
			strcpy(typestr, "Add");
			break;
		case TokenType::Sub:
			strcpy(typestr, "Subtract");
			break;
		case TokenType::Mul:
			strcpy(typestr, "Multiply");
			break;
		case TokenType::Div:
			strcpy(typestr, "Divide");
			break;
		case TokenType::Mod:
			break;
		case TokenType::Inc:
			break;
		case TokenType::Dec:
			break;
		case TokenType::Break:
			break;
		case TokenType::Semicolon:
			strcpy(typestr, "Semicolon");
			break;
		case TokenType::Paren_L:
			strcpy(typestr, "L Parentheses");
			break;
		case TokenType::Paren_R:
			strcpy(typestr, "R Parentheses");
			break;
		case TokenType::String:
			strcpy(typestr, "String");
			break;
	}
	if (type == TokenType::NUM) {
		sprintf_s(buffer, BUFFER_SIZE, "Line: %d, Col: %d -> TOKEN(%s, %d)", line, col, typestr, value);
	} else if (type == TokenType::Id || type == TokenType::String) {
		sprintf_s(buffer, BUFFER_SIZE, "Line: %d, Col: %d -> TOKEN(%s, \"%s\")", line, col, typestr, word.c_str());
	} else {
		sprintf_s(buffer, BUFFER_SIZE, "Line: %d, Col: %d -> TOKEN(%s, '%c')", line, col, typestr, value);
	}
	return buffer;
}

Token::~Token() {

}

Token::Token(TokenType type, int value) : type(type), value(value) {

}

void Token::setText(const std::string &str) {
	word = str;
}
