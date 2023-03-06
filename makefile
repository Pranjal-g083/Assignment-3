output: a.out A3_38.nc
		./a.out < A3_38.nc > output.txt

a.out:  lex.yy.c A3_38.c
		cc lex.yy.c A3_38.c -lfl

lex.yy.c: A3_38.l
		flex A3_38.l

clean:
	rm a.out lex.yy.c output.txt