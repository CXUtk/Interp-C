//
// Created by DELL on 2018/10/31.
//

#ifndef INTERP_C_TOKEN_H
#define INTERP_C_TOKEN_H

#include <string>
#include <map>

enum class TokenType {
	Eof = -1,
	NUM = 100, FUNC, Sys, Glo, Loc, Id,
	Char, Else, Enum, If, Int, Return, Sizeof, While,
	Assign, Cond, Lor, Land, Or, Xor, And, Eq, Ne, Lt, Gt, Le, Ge,
	Shl, Shr, Add, Sub, Mul, Div, Mod, Inc, Dec, Break, Not,
	Dot, Comma, Semicolon, Colon, Paren_L, Paren_R, Bracket_L, Bracket_R,
	Brace_L, Brace_R, String
};

class Token {
public:
	static std::map<std::string, TokenType> KeyWord;

	Token() : type(TokenType::Eof), value(0), word(), line(0), col(0) {}

	Token(TokenType type, int value);

	~Token();

	const char *toString();

	TokenType getType() const { return type; }

	void setType(TokenType type) { this->type = type; }

	int getValue() const { return value; }

	void setValue(int v) { this->value = v; }

	void setText(const std::string &str);

	bool isEOF() const { return type == TokenType::Eof; }

	void setExtraInfo(int line, int col) { this->line = line, this->col = col; }


private:
	TokenType type;
	int value;
	std::string word;
	int line;
	int col;
};

#endif //INTERP_C_TOKEN_H
