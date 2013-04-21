calculate : calc.o OpNumChar.o
	g++ -g -o calculate OpNumChar.o calc.o
main.o : calc.cpp OpNumChar.o
	g++ -g -c calc.cpp
OpNumChar.o : OpNumChar.h OpNumChar.cpp
	g++ -g -c OpNumChar.cpp
clean : 
	rm calculate calc.o OpNumChar.o
