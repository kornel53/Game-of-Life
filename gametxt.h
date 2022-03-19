#pragma once
#include "gameoflife.h"

class GameTxt : public GameOfLife {
public:
	GameTxt();
    virtual ~GameTxt();
    virtual void view();

private:
    GameTxt(const GameTxt& g);
	GameTxt operator=(const GameTxt& g);
};
