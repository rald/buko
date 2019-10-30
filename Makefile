CFLAGS=-Wall -g
LDFLAGS=-Wall -g

buko: buko.o die.o string.o dllist.o token.o lexer.o

buko.o: buko.c

die.o: die.c die.h
string.o: string.c string.h
dllist.o: dllist.c dllist.h
token.o: token.c token.h
lexer.o: lexer.c lexer.h

.PHONY: clean

clean:
	rm *.o buko

