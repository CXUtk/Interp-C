//
// Created by DELL on 2018/11/1.
//

#include "Scanner.h"

std::map<int, TokenType> Scanner::singleTokenType = {
{'+', TokenType::Add},
{'-', TokenType::Sub},
{'*', TokenType::Mul},
{'/', TokenType::Div},
{'!', TokenType::Not},
{'>', TokenType::Gt},
{'<', TokenType::Lt},
{'|', TokenType::Or},
{'&', TokenType::And},
{'^', TokenType::Xor},
{'=', TokenType::Assign},
{'.', TokenType::Dot},
{';', TokenType::Semicolon},
{':', TokenType::Colon},
{',', TokenType::Comma},
{'?', TokenType::Cond},
{'(', TokenType::Paren_L},
{')', TokenType::Paren_R},
{'[', TokenType::Bracket_L},
{']', TokenType::Bracket_R},
{'{', TokenType::Brace_L},
{'}', TokenType::Brace_R},
};

Scanner::Scanner(const char *src) : src(src), lineNum(1), colNum(1) {

}

void Scanner::extract() {
	while (*src == ' ' || *src == '\n') {
		if (*src == '\n') {
			lineNum++;
			colNum = 0;
		}
		increase();
	}
	if (!*src) {
		curToken.setType(TokenType::Eof);
		return;
	}
	int tk = *src;
	curToken.setValue(tk);
	if (isdigit(tk)) {
		curToken.setExtraInfo(lineNum, colNum);
		const char *prev = src;
		while (isdigit(*src)) {
			increase();
		}
		std::string str(prev, src);
		curToken.setType(TokenType::NUM);
		curToken.setValue(std::stoi(str));
	} else if (isalpha(tk)) {
		curToken.setExtraInfo(lineNum, colNum);
		const char *prev = src;
		increase();
		while (isalpha(*src) || isdigit(*src) || *src == '_') {
			increase();
		}
		std::string str(prev, src);
		if (Token::KeyWord.find(str) != Token::KeyWord.end()) {
			curToken.setType(Token::KeyWord[str]);
		} else {
			curToken.setType(TokenType::Id);
		}
		curToken.setText(str);
	} else if (tk == '\"') {
		curToken.setExtraInfo(lineNum, colNum);
		increase();
		const char *prev = src;
		while (*src != '\"' && *src) {
			increase();
		}
		std::string str(prev, src);
		curToken.setType(TokenType::String);
		curToken.setText(str);
		increase();
	} else {
		curToken.setExtraInfo(lineNum, colNum);
		scanSpecialToken(tk);
	}

}

Token Scanner::nextToken() {
	extract();
	return curToken;
}

Scanner::~Scanner() {

}

void Scanner::scanSpecialToken(int tk) {
	increase();

	if (tk == '+') {
		if (*src == '+') {
			increase();
			curToken.setType(TokenType::Inc);
			return;
		}
	} else if (tk == '-') {
		if (*src == '-') {
			increase();
			curToken.setType(TokenType::Dec);
			return;
		}
	} else if (tk == '/') {
		if (*(src + 1) == '/') {
			increase();
			while (*src != '\0' && *src != '\n') {
				increase();
			}
			return;
		}
	} else if (tk == '!') {
		// parse '!='
		if (*src == '=') {
			increase();
			curToken.setType(TokenType::Ne);
			return;
		}
	} else if (tk == '<') {
		// parse '<=', '<<' or '<'
		if (*src == '=') {
			increase();
			curToken.setType(TokenType::Le);
			return;
		} else if (*src == '<') {
			increase();
			curToken.setType(TokenType::Shl);
			return;
		}
	} else if (tk == '>') {
		// parse '<=', '<<' or '<'
		if (*src == '=') {
			increase();
			curToken.setType(TokenType::Ge);
			return;
		} else if (*src == '>') {
			increase();
			curToken.setType(TokenType::Shr);
			return;
		}
	} else if (tk == '|') {
		// parse '|' or '||'
		if (*src == '|') {
			increase();
			curToken.setType(TokenType::Lor);
			return;
		}
	} else if (tk == '&') {
		// parse '&' or '&&'
		if (*src == '&') {
			increase();
			curToken.setType(TokenType::Land);
			return;
		}
	}
	assignToken(tk);
}

void Scanner::assignToken(int tk) {
	if (singleTokenType.find(tk) != singleTokenType.end())
		curToken.setType(singleTokenType[tk]);
	else
		throw std::runtime_error("Invalid character!");
}
