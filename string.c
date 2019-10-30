#include "string.h"

char *String_Append(char **a,char *b) {
	if(*a) {
		(*a)=realloc(*a,sizeof(**a)*(strlen(*a)+strlen(b)+1));
	} else {
		(*a)=realloc(*a,sizeof(**a)*(strlen(b)+1));
		(*a)[0]='\0';
	}
	strcat(*a,b);
	return *a;
}
