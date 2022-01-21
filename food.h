#ifndef FOOD_H
#define FOOD_H

#include "snake.h"
#include "point.h"

// Food class controls the position of food and counts the food.
class Snake;
class Food : public Point {
public:
    Food();
    ~Food() {};
    void drawFood(Snake*, const int);
    int getCnt();
private:
    void drawPoint(const int, const int);
    int iCnt;
    int iX, iY;
    friend class Snake; // Let class Snake be a friend class and have access to the private variables
};
#endif // FOOD_H