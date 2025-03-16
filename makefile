main:
	bison -d -v -Wconflicts-rr -Wcounterexamples --report-file=output/parser.output parser.y 2> output/bison_out.txt
	flex lexer.l
	gcc lex.yy.c parser.tab.c parser_test.c ast.c symbol_table.c declarations.c types.c -o parser_test

run:
#	gcc -E sample_inputs/exprtests.c | ./parser_test > output/exprtests.txt
	gcc -E sample_inputs/ttests/base.c | ./parser_test > output/exprtests.txt
#	gcc -E sample_inputs/test.c | ./parser_test > output/exprtests.txt
