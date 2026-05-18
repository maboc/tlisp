tlisp : tlisp.o
gcc -ggdb -o tlisp tlisp.o

tlisp.o : tlisp.o
	gcc -c tlisp.c -ggdb


