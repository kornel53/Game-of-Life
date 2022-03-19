#include "engine.h"
#include <fstream>

using namespace std;

Engine::Engine() {}

Engine::~Engine() {
    if(board) {
        for (int i = 0; i < width; i++) {
            delete[] board[i];
        }
        delete[] board;
    }
    if(tmpBoard) {
        for (int i = 0; i < width; i++) {
            delete[] tmpBoard[i];
        }
        delete[] tmpBoard;
    }
}
void Engine::init(const char* fName) {
	ifstream inputFile;
	inputFile.open(fName);
	inputFile >> width >> height;
    board = new bool* [height];
    tmpBoard = new bool* [height];

	for (int i = 0; i < height; i++) {
		board[i] = new bool[width];
		tmpBoard[i] = new bool[width];
		for (int j = 0; j < width; j++) {
			board[i][j] = false;
			tmpBoard[i][j] = false;
		}
	}
	while(!inputFile.eof()) {
		int w, h;
		inputFile >> w >> h;
		board[h][w] = true;
	}
	inputFile.close();
}

void Engine::analyze() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int neighbors = neighborsAlive(i, j);
			if (board[i][j] && (neighbors < 2 || neighbors > 3)) {
				tmpBoard[i][j] = false;
			}
			else if ((board[i][j] && (neighbors >= 2 && neighbors <= 3)) || (!board[i][j] && neighbors == 3)) {
				tmpBoard[i][j] = true;
			}
		}
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			board[i][j] = tmpBoard[i][j];
		}
	}
}

bool Engine::getElement(int i, int j) {
	//CPP: (-1)%10 = -1
	//Python: (-1)%10 = 9
    return board[((i % height) + height) % height][((j % width) + width) % width];
}

int Engine::neighborsAlive(int i, int j) {
	int alive = 0;
	//checking up->down, left->right
	if (getElement(i-1, j-1)) alive++;
	if (getElement(i-1, j)) alive++;
	if (getElement(i-1, j+1)) alive++;
	if (getElement(i, j-1)) alive++;
	if (getElement(i, j+1)) alive++;
	if (getElement(i+1, j-1)) alive++;
	if (getElement(i+1, j)) alive++;
	if (getElement(i+1, j+1)) alive++;
	return alive;
}
