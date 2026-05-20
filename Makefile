tlisp : tlisp.o dll.o
	gcc -ggdb -o tlisp tlisp.o dll.o

tlisp.o : tlisp.c
	gcc -c tlisp.c -ggdb

dll.o : dll.c
	gcc -c dll.c -ggdb

clean:
	rm *.o
	rm *~
