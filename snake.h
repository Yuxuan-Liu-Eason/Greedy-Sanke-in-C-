#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "point.h"
#include "food.h"

using namespace std;

class Food; // Food as friend class
// Snake class controls the snake in the game, derived from Point
class Snake : public Point {
public:
    enum Direction { UP, DOWN, LEFT, RIGHT };
	Snake();
    void initSnake();
    void grow();
    void move();
    bool bHitWall(int);
    bool bHitSelf();
    bool bChangeDirection();
    bool bGetFood(Food*);
private:
    void drawPoint(const int, const int);
    deque<Point> dqeSnake; // use deque to store the points as snake. Back of the deque is the head of the snake
    Direction direction;
    friend class Food;
};

#endif
