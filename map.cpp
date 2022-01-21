#include "map.h"
#include "point.h"
#include "tools.h"
#include <windows.h>
#include <iostream>

using namespace std;

// Default constructor sets the map to 30*30
Map::Map() : width(30), height(30) {

}

void Map::drawMap(int diff) {
	setColor(8);
	// Draw top boundary
	for (int i = 1; i <= width; i++) {
		Point(i, 1).square();
	}
	// Draw left boundary
	for (int i = 2; i < height; i++) {
		Point(1, i).square();
	}
	// Draw right boundary
	for (int i = 2; i < height; i++) {
		Point(width, i).square();
	}
	// Draw bottom boundary
	for (int i = 1; i <= width; i++) {
		Point(i, height).square();
	}
	// Draw obstacles for difficult game
	if (diff == 3) {
		for (int i = 2; i <= 15; i++) {
			Point(10, i).square();
			Point(20, height + 1 - i).square();
		}
	}
}