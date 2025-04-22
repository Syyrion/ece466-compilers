main:
	bison -d -v -Wconflicts-rr -Wcounterexamples --report-file=output/parser.output parser.y 2> output/bison_out.txt
	flex lexer.l
	gcc *.c -o parser_test

run:
#	gcc -E sample_inputs/exprtests.c | ./parser_test > output/testing_out.txt
#	gcc -E sample_inputs/ttests/base.c | ./parser_test > output/testing_out.txt
#	gcc -E sample_inputs/ttests/struct1.c | ./parser_test > output/testing_out.txt
#   gcc -E sample_inputs/ttests/fn1.c | ./parser_test > output/testing_out.txt
	gcc -E sample_inputs/ttests/fn2.c | ./parser_test > output/testing_out.txt
#	gcc -E sample_inputs/test.c | ./parser_test > output/testing_out.txt
