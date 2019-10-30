#include "token.h"

char *TokenNames[]={
	"UNKNOWN",
	"IDENT",
	"INT",
	"STR",
	"OPEN_PAREN",
	"CLOSE_PAREN",
	"SEMICOLON",
	"TAB",
	"NEWLINE",
	"EOF"
};

Token *Token_New(TokenType type,char *text) {
	Token *token=malloc(sizeof(*token));
  if(token) {
    token->type=type;
    token->text=text?strdup(text):NULL;
  }
	return token;
}

void Token_Delete(void *token) {
  ((Token*)token)->type=TOKEN_TYPE_UNKNOWN;
  free(((Token*)token)->text);
  ((Token*)token)->text=NULL;
  free((Token*)token);
  token=NULL;
}

char *Token_ToString(Token *token) {
  char *tokenStr=malloc(sizeof(*tokenStr)*TOKEN_STRING_MAX);
  char *text=NULL;
	switch(token->type) {
    case TOKEN_TYPE_NEWLINE: text="\\n"; break;
    case TOKEN_TYPE_TAB: text="\\t"; break;
    default:
      text=token->text;
  }
  snprintf(tokenStr,TOKEN_STRING_MAX,"{\"Type\":\"%s\",\"Text\":\"%s\"}",TokenNames[token->type],text);
  return tokenStr;
}
