#include <stdio.h>

extern int yylex();

int main() {
    printf("Tokenizing input...\n");
    yylex();
    return 0;
}