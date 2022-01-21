#include "map.h"
#include "tools.h"
#include <iostream>

using namespace std;

// Map class controls the map in the game. Default constructor sets the map to 30*30
Map::Map() : iWidth(30), iHeight(30), Point() {

}

// Draw square as walls
void Map::drawPoint(const int x, const int y) {
	setCursorPosition(x, y);
	cout << "¡ö";
}

// Draw the map with difficulty as parameter
void Map::drawMap(const int difficulty) {
	
	setColor(8); // Set color to gray

	// Draw top boundary
	for (int i = 1; i <= iWidth; i++) {
		this->drawPoint(i, 1);
	}
	// Draw left boundary
	for (int i = 2; i < iHeight; i++) {
		this->drawPoint(1, i);
	}
	// Draw right boundary
	for (int i = 2; i < iHeight; i++) {
		this->drawPoint(iWidth, i);
	}
	// Draw bottom boundary
	for (int i = 1; i <= iWidth; i++) {
		this->drawPoint(i, iHeight);
	}
	// Draw obstacles for difficult game only
	if (difficulty == 3) {
		for (int i = 2; i <= 15; i++) {
			this->drawPoint(10, i);
			this->drawPoint(20, iHeight + 1 - i);
		}
	}
}