# The Game of Life \[C++\]

The Game of Life  is a cellular automaton, and was invented by Cambridge mathematician John Conway.

This game became widely known when it was mentioned in an article published by Scientific American in 1970. It consists of a grid of cells which, based on a few mathematical rules, can live, die or multiply. Depending on the initial conditions, the cells form various patterns throughout the course of the game.

Rules:

* Each *alive* cell with one or no neighbors dies, as if by solitude.

* Each *alive* cell with four or more neighbors dies, as if by overpopulation.

* Each *alive* cell with two or three neighbors survives.

* Each *dead* cell with three neighbors becomes populated.

# How to play

Use the file named *init.txt* in the project directory to initialize a **toroidal** game board. Each line consists of two numbers separated by spaces: width and height.
* in the first line put board size,
* in the next lines put the coordinates (x, y) of the alive cells

e.g. *init.txt* file
```
30 20
10 10
10 11
10 12
9 12
8 11
2 3
3 2
2 2
1 1
7 7
3 8
4 4
4 5
4 6
0 0
```

The game will automatically count the number of alive cells, so feel free to add more lines.

# Technical section

### The game was meant to be written with the principles of OOP.

Classes *Engine* and *GameOfLife* are the platform-independent files which are the brains of the game, 
while the *GameTxt* class is the implementation for the specific system (in this case: Windows console).
You can simply create a new class that inherits from *GameOfLife* and use any GUI library to show and animate the game board.
