p = prog
c = code
test: $(p).o code.o
	gcc $(p).o $(c).o -o test
prog.o: prog.c code.h
	gcc -c $(p).c -o $(p).o
code.o: code.c code.h
	gcc -c $(c).c -o $(c).o
clean:
	rm -f *.o test
