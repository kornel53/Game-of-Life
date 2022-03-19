#pragma once

#include "engine.h"

class GameOfLife : public Engine {
public:
	GameOfLife();
	void init(const char* fName);
	virtual ~GameOfLife();
    void startGame();
	virtual void view()=0;
private:
	GameOfLife(const GameOfLife& g);
	GameOfLife& operator=(const GameOfLife& g);
};
