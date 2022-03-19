#include "gameoflife.h"

GameOfLife::GameOfLife() {}

GameOfLife::~GameOfLife() {}

void GameOfLife::init(const char* fName) {
    Engine::init(fName);
}

void GameOfLife::startGame() {
    const int ITERATIONS = 100;

    view();
	for(int i = 0; i < ITERATIONS; i++) {
        analyze();
        view();
	}
}
