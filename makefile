main:
	bison -d -v -Wconflicts-rr --report-file=output/parser.output parser.y 2> output/bison_out.txt
	flex lexer.l
	gcc -g *.c -o rcc

run:
#	gcc -E sample_inputs/exprtests.c | ./rcc > output/testing_out.txt
#	gcc -E sample_inputs/ttests/base.c | ./rcc > output/testing_out.txt
#	gcc -E sample_inputs/ttests/struct1.c | ./rcc > output/testing_out.txt
#   gcc -E sample_inputs/ttests/fn1.c | ./rcc > output/testing_out.txt
	gcc -E sample_inputs/ttests/fn2.c | ./rcc > output/testing_out.txt
#	gcc -E sample_inputs/test.c | ./rcc > output/testing_out.txt
