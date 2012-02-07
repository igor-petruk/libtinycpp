CFLAGS=-Os -fno-exceptions -fno-rtti

prog: start.o Makefile prog.o io.o memory.o
	ld -o prog -O0 *.o	# LINKING

.s.o:
	as $(EXTRAFLAGS) -o $*.o $*.s	

.c.o:
	gcc $(CFLAGS) -c $< -march=native -mtune=native

.cpp.o:
	g++ $(CFLAGS) -c $< -march=native -mtune=native

clean: 
	rm ./*.o ./prog
