#ifndef POINT_H
#define POINT_H

class Point {
public:
	Point(int x, int y);
	void square();
	void circle();
	virtual void drawPoint() {};
	void clear();
	int getX();
	int getY();
	bool operator== (const Point& point);
private:
	int x, y;
};

#endif // POINT_H