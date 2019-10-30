#include "lexer.h"

static int isAlpha(int ch) {
	return isalpha((unsigned char)ch);
}

static int isDigit(int ch) {
	return isdigit((unsigned char)ch);
}

static int isAlnum(int ch) {
	return isalnum((unsigned char)ch);
}

DLList *lex(char *code) {
	DLList *tokens=NULL;
	LexState state=LEX_STATE_DEFAULT;
	char *text=NULL;
	int i=0;
	while(code[i]) {
		switch(state) {
			case LEX_STATE_DEFAULT:
				if(isAlpha(code[i]) || code[i]=='_') {
					String_Append(&text,(char[2]){code[i],'\0'});
					state=LEX_STATE_IDENT;
				} else if(isDigit(code[i]) || code[i]=='+' || code[i]=='-') {
					String_Append(&text,(char[2]){code[i],'\0'});
					state=LEX_STATE_INT;
				} else if(code[i]=='\"') {
					state=LEX_STATE_STR;
				} else if(code[i]=='(') {
					DLList_Append(&tokens,Token_New(TOKEN_TYPE_OPEN_PAREN,(char[2]){code[i],'\0'}));
				} else if(code[i]==')') {
					DLList_Append(&tokens,Token_New(TOKEN_TYPE_CLOSE_PAREN,(char[2]){code[i],'\0'}));
				} else if(code[i]==';') {
					DLList_Append(&tokens,Token_New(TOKEN_TYPE_SEMICOLON,(char[2]){code[i],'\0'}));
				}
			break;
			case LEX_STATE_IDENT:
				if(isAlnum(code[i]) || code[i]=='_') {
					String_Append(&text,(char[2]){code[i],'\0'});
				} else {
					DLList_Append(&tokens,Token_New(TOKEN_TYPE_IDENT,text));
					free(text);
					text=NULL;
					i--;
					state=LEX_STATE_DEFAULT;
				}
			break;
			case LEX_STATE_INT:
				if(!text && (code[i]=='+' || code[i]=='-')) {
						String_Append(&text,(char[2]){code[i],'\0'});
				} else if(isDigit(code[i])) {
						String_Append(&text,(char[2]){code[i],'\0'});
				} else {
					DLList_Append(&tokens,Token_New(TOKEN_TYPE_INT,text));
					free(text);
					text=NULL;
					i--;
					state=LEX_STATE_DEFAULT;
				}
			break;
			case LEX_STATE_STR:
				if(code[i]!='\"') {
					String_Append(&text,(char[2]){code[i],'\0'});
				} else {
					DLList_Append(&tokens,Token_New(TOKEN_TYPE_STR,text));
					free(text);
					text=NULL;
					state=LEX_STATE_DEFAULT;
				}
			break;
			default: break;
		}
		i++;
	}

	DLList_Append(&tokens,Token_New(TOKEN_TYPE_EOF,NULL));

	return tokens;
}
