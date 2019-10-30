#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

#include "die.h"
#include "dllist.h"
#include "token.h"
#include "lexer.h"

#define BUFFER_MAX 1024

char *load(char *fn) {
  int fd,ln,nb;
  char *rt,*bf,*tmp;

  rt=NULL;
  ln=0;

  if(fn)
    fd=open(fn,0);
  else
    fd=0;

  if(fd==-1) {
    return NULL;
  }

  bf=malloc(sizeof(char)*BUFFER_MAX);

  while((nb=read(fd,bf,BUFFER_MAX))>0) {
    tmp=realloc(rt,sizeof(char)*(ln+nb+1));
    if(!tmp) {
      free(rt);
      rt=NULL;
      return NULL;
    }
    rt=tmp;
    memcpy(rt+ln,bf,nb);
    ln+=nb;
    rt[ln]=0;
  }

  return rt;
}

int main(int argc,char **argv) {

	char *code=NULL;
	DLList *tokens=NULL;

	if(argc==2) {
		code=load(argv[1]);
	} else {
		code=load(NULL);
	}

	tokens=lex(code);

	DLList *iter=tokens;
	while(iter) {
		printf("%s\n",Token_ToString(iter->data));
		iter=iter->next;
	}

}
