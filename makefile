main:
	bison -d -v --report=all parser.y 2> bison_out.txt
	flex lexer.l
	gcc lex.yy.c parser.tab.c parser_test.c ast.c -o parser_test

run:
	gcc -E sample_inputs/exprtests2.c | ./parser_test > exprtests.txt

clean:
	rm parser.tab.c parser.tab.h lex.yy.c
