//
// Created by DELL on 2018/10/31.
//

#ifndef INTERP_C_TOKEN_H
#define INTERP_C_TOKEN_H

#include <string>

enum class TokenType {
	Eof = -1,
	NUM = 128, FUNC, Sys, Glo, Loc, Id,
	Char, Else, Enum, If, Int, Return, Sizeof, While,
	Assign, Cond, Lor, Lan, Or, Xor, And, Eq, Ne, Lt, Gt, Le, Ge, Shl, Shr, Add, Sub, Mul, Div, Mod, Inc, Dec, Brak
};

class Token {
public:
	Token(TokenType type, int value);

	~Token();

	const char * toString();

	TokenType getType() const { return type; }

	void setType(TokenType type) { this->type = type; }

	int getValue() const { return value; }

	void setValue(int v) { this->value = v; }

	bool isEOF() const { return type == TokenType::Eof; }

private:
	TokenType type;
	int value;
};

#endif //INTERP_C_TOKEN_H
