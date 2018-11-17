//
// Created by DELL on 2018/11/1.
//

#ifndef INTERP_C_SCANNER_H
#define INTERP_C_SCANNER_H

#include "Token.h"
#include <stdexcept>

class Scanner {
public:
	explicit Scanner(const char * src);
	~Scanner();

	Token currentToken() const { return curToken; }
	Token nextToken();

private:
	const char * src;
	int lineNum;
	int colNum;
	Token curToken;

	static std::map<int, TokenType> singleTokenType;

	void extract();

	void scanSpecialToken(int tk);

	void assignToken(int tk);

	void increase() {
		src++;
		colNum++;
	}
};


#endif //INTERP_C_SCANNER_H
