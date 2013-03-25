CFLAGS=-g
FLEX=flex
BISON=bison

sintatico.out: sint.c
	$ gcc -o sintatico.out sint.c

sint.c: bison.y lex.c
	$(BISON) -d -o sint.c bison.y 


lex.c: teste_v6.lex sint.c sintatico.out
	$(FLEX) -olex.c teste_v6.lex



