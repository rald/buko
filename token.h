#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOKEN_STRING_MAX 256

typedef struct Token Token;
typedef enum TokenType TokenType;

enum TokenType {
	TOKEN_TYPE_UNKNOWN=0,
	TOKEN_TYPE_IDENT,
	TOKEN_TYPE_INT,
	TOKEN_TYPE_STR,
	TOKEN_TYPE_OPEN_PAREN,
	TOKEN_TYPE_CLOSE_PAREN,
	TOKEN_TYPE_SEMICOLON,
	TOKEN_TYPE_TAB,
	TOKEN_TYPE_NEWLINE,
	TOKEN_TYPE_EOF,
	TOKEN_TYPE_MAX
};

struct Token {
	TokenType type;
	char *text;
};

extern char *TokenNames[];

Token *Token_New(TokenType type,char *text);
void Token_Delete(void *token);
char *Token_ToString(Token *token);

#endif
