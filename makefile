o ?= 323comp

all: $(o).exe

lex: lex.yy.c

bison: y.tab.c

yacc: bison

lex.yy.c: $(o).l
	flex $(o).l 
	
y.tab.c: $(o).y
	bison -dy $(o).y

y.tab.h: $(o).y

$(o).exe: lex.yy.c y.tab.c y.tab.h
	gcc lex.yy.c y.tab.c -o $(o).exe

clean:
	rm -rf lex.yy.c
	rm -rf y.tab.c
	rm -rf y.tab.h
	rm -rf $(o).exe
	rm -rf $(o).cc

