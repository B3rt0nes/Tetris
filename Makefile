all: compile run

compile: main.cpp
	g++ -o main.out main.cpp grid.cpp block.cpp Blocks.cpp -lncurses
run: 
	./main.out