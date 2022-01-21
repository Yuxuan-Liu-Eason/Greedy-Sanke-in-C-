#include "point.h"
#include "tools.h"
#include <iostream>

using namespace std;

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

void Point::square() {
	setCursorPosition(x, y);
	cout << "■";
}

void Point::circle() {
	setCursorPosition(x, y);
	cout << "●";
}

void Point::clear() {
	setCursorPosition(x, y);
	cout << "  ";
}

int Point::getX() {
	return this->x;
}

int Point::getY() {
	return this->y;
}

bool Point::operator==(const Point& point) {
	return (point.x == this->x) && (point.y == this->y);
}