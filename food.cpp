#include "food.h"
#include "tools.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

Food::Food(int x, int y) : Point(x, y){
	cnt = 0;
	x = 0;
	y = 0;
}

void Food::drawFood(Snake s, int diff) {
	setColor(4);
	bool overlap = false;
	while (true) {
		overlap = false;
		// generate random int between 2 and 29
		srand(time(0));
		x = rand() % 27 + 2;
		y = rand() % 27 + 2;
		// If food overlap with sanke, regenerate one
		for (Point p : s.snake) {
			if (x == p.getX() && y == p.getY()) {
				overlap = true;
				break;
			}
		}
		// If food overlap with obstacles (only when diff = 3), regenerate one as well
		if ((diff == 3) && ((x == 10 && (y >= 2 && y <= 15)) || (x == 20 && (y >= 16 && y <= 29)))) {
			overlap = true;
		}
		if (overlap) {
			continue;
		}
		else {
			setCursorPosition(x, y);
			cout << "бя";
			cnt++;
			break;
		}
	}	
}

int Food::getCnt() {
	return cnt;
}