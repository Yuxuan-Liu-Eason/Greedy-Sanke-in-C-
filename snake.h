#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "point.h"
#include "food.h"

using namespace std;

class Food;
class Snake {
public:
    enum Direction { UP, DOWN, LEFT, RIGHT };

	Snake();
    void initSnake();
    void grow();
    void move();
    bool hitEdge(int);
    bool hitSelf();
    bool changeDirection();
    bool getFood(const Food);
    
private:
    deque<Point> snake;
    Direction direction;
    friend class Food;
};

#endif
