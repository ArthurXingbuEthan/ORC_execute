all: prog.out

prog.out: orc.o orcinput.o main.o orcrunner.o
	g++ -std=c++11 -o $@ $^

main.o: main.cpp
	g++ -std=c++11 -c $^ 

orc.o: orc.cpp
	g++ -std=c++11 -c $^

orcinput.o: orcinput.cpp
	g++ -std=c++11 -c $^

orcrunner.o: orcrunner.cpp
	g++ -std=c++11 -c $^
	


clean:
	rm *.out *.o 