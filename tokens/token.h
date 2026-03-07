#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    TOK_IDENTIFIER,
    TOK_NUMBER,
    TOK_STRING,
    TOK_KEYWORD,
    TOK_OPERATOR,
    TOK_DELIMITER,
    TOK_UNKNOWN
} TokenType;

#endif