//
// Created by DELL on 2018/11/1.
//

#ifndef INTERP_C_SCANNER_H
#define INTERP_C_SCANNER_H

#include "Token.h"

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

	void extract();
};


#endif //INTERP_C_SCANNER_H
