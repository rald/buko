#include "die.h"

void die(char *fmt,...) {
	va_list args;
	va_start(args,fmt);
	vprintf(fmt,args);
	va_end(args);
	exit(-1);
}
