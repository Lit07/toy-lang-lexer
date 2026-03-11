#include <stdio.h>
#include "parser.h"

int main() {

    char input[100];

    printf("Enter expression (end with $): ");
    scanf("%s", input);

    predictive_parse(input);

    return 0;
}