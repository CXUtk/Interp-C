#include <iostream>

#include "Interpreter.h"

int main() {
    char str[] = "1 + 1";
    Interpreter intp;
    intp.Parse(str);

    return 0;
}