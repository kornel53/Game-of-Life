#pragma once

class Engine {
protected:
	int width, height;
	bool** board;
	bool** tmpBoard;
protected:
	Engine();
	virtual ~Engine();
    void analyze();
	void init(const char* fName);
private:
	int neighborsAlive(int i, int j);
	bool getElement(int i, int j);
	Engine(const Engine& s);
	Engine& operator=(const Engine& s);
};
