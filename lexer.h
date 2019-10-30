#ifndef LEXER_H
#define LEXER_H

#include <stdlib.h>
#include <ctype.h>

#include "string.h"
#include "dllist.h"
#include "token.h"

typedef enum LexState LexState;

enum LexState {
	LEX_STATE_UNKNOWN=0,
	LEX_STATE_DEFAULT,
	LEX_STATE_IDENT,
	LEX_STATE_INT,
	LEX_STATE_STR,
	LEX_STATE_MAX
};

DLList *lex(char *code);

#endif
