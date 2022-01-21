#include "point.h"
#include "tools.h"
#include <iostream>

using namespace std;

// Default constructor set x and y to 0
Point::Point() {
	this->iX = 0;
	this->iY = 0;
}

// Constructor with given x and y
Point::Point(int x, int y) {
	this->iX = x;
	this->iY = y;
}

// Clear a point by printing a blank
void Point::clear() {
	setCursorPosition(iX, iY);
	cout << "  ";
}

// Getters
int Point::getX() {
	return this->iX;
}

int Point::getY() {
	return this->iY;
}

// Equal operator
bool Point::operator==(const Point& point) {
	return (point.iX == this->iX) && (point.iY == this->iY);
}