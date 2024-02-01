all: compile run

compile: main.cpp
	g++ -o main.out main.cpp -lncurses
run: 
	./main.out