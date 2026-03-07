#include <string.h>

const char *keywords[] = {
    "if",
    "else",
    "while",
    "for",
    "return",
    "int",
    "float",
    "char",
    "void",
    NULL
};

int is_keyword(const char *str) {
    int i = 0;
    while (keywords[i]) {
        if (strcmp(keywords[i], str) == 0)
            return 1;
        i++;
    }
    return 0;
}