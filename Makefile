all: prog.out

prog.out: orc.o orcinput.o main.o
	g++ -o $@ $^


clean:
	rm *.out *.o 