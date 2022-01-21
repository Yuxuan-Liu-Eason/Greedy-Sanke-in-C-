#include "food.h"
#include "tools.h"
#include <iostream>
#include <ctime>

using namespace std;

// Food class controls the food in the game, derived from Point
Food::Food() : Point(){
	iCnt = 0;
	iX = 0;
	iY = 0;
}

// Override the virtual function in base class, draw a star as food
void Food::drawPoint(const int x, const int y) {
	setCursorPosition(x, y);
	cout << "бя";
}

// Draw food
void Food::drawFood(Snake* ptrSnake, const int difficulty) {
	setColor(4); // Set color to red
	bool overlap = false; // Bool used to decide if the food is overlap with snake or wall. Initialized to false

	while (true) {

		overlap = false;
		// generate random int between 2 and 29 (with the map)
		srand(time(0));
		iX = rand() % 27 + 2;
		iY = rand() % 27 + 2;

		// If food overlap with sanke, regenerate one
		for (auto& p : ptrSnake->dqeSnake) {
			if (iX == p.getX() && iY == p.getY()) {
				overlap = true;
				break;
			}
		}

		// If food overlap with walls (only when diff = 3), regenerate one as well
		if ((difficulty == 3) && ((iX == 10 && (iY >= 2 && iY <= 15)) || (iX == 20 && (iY >= 16 && iY <= 29)))) {
			overlap = true;
		}

		if (overlap) {
			continue;
		}
		else { // if not overlap, draw the food and count
			this->drawPoint(iX, iY);
			iCnt++;
			break;
		}
	}	
}

int Food::getCnt() {
	return iCnt;
}