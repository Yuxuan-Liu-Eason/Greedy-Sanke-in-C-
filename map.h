#ifndef MAP_H
#define MAP_H
#include <vector>
#include "point.h"

// Map class controls the map of the game, derived from point
class Map : public Point {
public:
	Map();
	~Map() {};
	void drawMap(const int);
private:
	void drawPoint(const int, const int);
	const int iWidth, iHeight; // constant width and height
};


#endif // MAP_H
