main:
	bison -d -v -Wconflicts-rr -Wcounterexamples parser.y 2> bison_out.txt
	flex lexer.l
	gcc lex.yy.c parser.tab.c parser_test.c ast.c -o parser_test

run:
	gcc -E sample_inputs/exprtests.c | ./parser_test > exprtests.txt

#	gcc -E sample_inputs/ttests/base.c | ./parser_test > exprtests.txt

clean:
	rm parser.tab.c parser.tab.h lex.yy.c
