#ifndef FOOD_H
#define FOOD_H

#include "snake.h"
#include "point.h"

class Snake;
class Food : public Point {
public:
    Food(int, int);
    void drawFood(Snake, int);
    int getCnt();
private:
    int cnt;
    int x, y;
    friend class Snake;
};
#endif // FOOD_H