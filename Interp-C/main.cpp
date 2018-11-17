#include <iostream>

#include "Interpreter.h"

int main() {
	char str[] = "if(x > 0 && b < 0) return 1; \"test\"";
    Interpreter intp;
    intp.Parse(str);
    return 0;
}