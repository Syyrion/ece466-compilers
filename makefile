main:
	flex lexer.l
	gcc lex.yy.c -o lextest

run:
	gcc -E ltests/*.c | ./lextest >ltest.out 2>ltest.err

clean:
	rm lextest