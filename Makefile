all: compile run

compile: main.cpp
	g++ -o main.out main.cpp grid.cpp block.cpp Blocks.cpp game.cpp -lncurses
run: 
	./main.out