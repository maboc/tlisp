tlisp : tlisp.o
	gcc -ggdb -o tlisp tlisp.o

tlisp.o : tlisp.c
	gcc -ggdb -c tlisp.c

clean:
	rm *~
	rm *.o
