#include <iostream>

#include "Interpreter.h"

int main() {
    char str[] = "#include <iostream>";
    Interpreter intp;
    intp.Parse(str);

    return 0;
}