%{
#include <stdio.h>
#include "token.h"
#include "keywords.h"
%}

DIGIT      [0-9]
LETTER     [a-zA-Z_]

IDENTIFIER {LETTER}({LETTER}|{DIGIT})*
NUMBER     {DIGIT}+(\.{DIGIT}+)?
STRING     \"([^\\\"]|\\.)*\"

%%

{IDENTIFIER} {
    if(is_keyword(yytext))
        printf("<KEYWORD, %s>\n", yytext);
    else
        printf("<IDENTIFIER, %s>\n", yytext);
}

{NUMBER} {
    printf("<NUMBER, %s>\n", yytext);
}

{STRING} {
    printf("<STRING, %s>\n", yytext);
}

"=="|"!="|"<="|">=" {
    printf("<OPERATOR, %s>\n", yytext);
}

"+"|"-"|"*"|"/"|"="|"<"|">" {
    printf("<OPERATOR, %s>\n", yytext);
}

";"|","|"("|")"|"{"|"}" {
    printf("<DELIMITER, %s>\n", yytext);
}

[ \t\n]+   ;

. {
    printf("<UNKNOWN, %s>\n", yytext);
}

%%

int yywrap() {
    return 1;
}