#include "gametxt.h"
#include <iostream>
#include <windows.h>

using namespace std;

GameTxt::GameTxt() {}

GameTxt::~GameTxt() {}

void GameTxt::view() {
    //Windows console implementation
    const int ANIMATION_TIME = 500;

    system("cls");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (board[i][j]) {
				cout << "x ";
			}
			else cout << "- ";
		}
		cout << endl;
	}
	    Sleep(ANIMATION_TIME);
}
