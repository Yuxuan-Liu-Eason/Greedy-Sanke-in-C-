#ifndef POINT_H
#define POINT_H

// Base class point
class Point {
public:
	Point();
	Point(int, int);
	virtual ~Point() {};
	bool operator== (const Point&);
	virtual void drawPoint(const int, const int) {}; // virtual function that can be overriden in the derived classes
	void clear(); // clear a point
	int getX();
	int getY();
private:
	int iX, iY;
};

#endif // POINT_H