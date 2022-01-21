#include "snake.h"
#include <conio.h>
#include "tools.h"
#include "Map.h"
#include <iostream>

using namespace std;

Snake::Snake() {
	snake.push_back(Point(15, 22));
	snake.push_back(Point(15, 21));
	snake.push_back(Point(15, 20));
    direction = Direction::UP;
}

void Snake::initSnake() {
    setColor(2);
	for (Point p : snake) {
        p.circle();
	}
}

void Snake::grow() {
    setColor(2);
    switch (direction)
    {
    case Direction::UP:
        snake.emplace_back(Point(snake.back().getX(), snake.back().getY() - 1));
        break;
    case Direction::DOWN:
        snake.emplace_back(Point(snake.back().getX(), snake.back().getY() + 1));
        break;
    case Direction::LEFT:
        snake.emplace_back(Point(snake.back().getX() - 1, snake.back().getY()));
        break;
    case Direction::RIGHT:
        snake.emplace_back(Point(snake.back().getX() + 1, snake.back().getY()));
        break;
    default:
        break;
    }
    snake.back().circle();
}

void Snake::move() {
    grow();
    snake.front().clear();
    snake.pop_front();
}

bool Snake::hitEdge(int diff) {
    Point p = snake.back();
    if (diff != 3) {
        return (p.getX() >= 30
            or p.getX() <= 1
            or p.getY() >= 30
            or p.getY() <= 1);
    }
    else {
        return (p.getX() >= 30
            or p.getX() <= 1
            or p.getY() >= 30
            or p.getY() <= 1 
            or (p.getX() == 10 && (p.getY() >= 2 && p.getY() <= 15))
            or (p.getX() == 20 && (p.getY() >= 16 && p.getY() <= 29)));
    }
}

bool Snake::hitSelf() {
    Point p1 = snake.back();
    bool hitSelf = false;
    deque<Point> body = snake;
    body.pop_back();
    // If head equals body, then means hit self.
    for (Point p2 : body) {
        if (p1 == p2) {
            hitSelf = true;
            break;
        }
    }
    return hitSelf;
}

bool Snake::changeDirection() {
    char ch;
    if (_kbhit()) {
        ch = _getch();
        switch (ch) {
        case -32:
            ch = _getch();
            switch (ch) {
            case 72: // 72 is the up in the keyboard
                // Cannot change to the opposite direction as the current direction
                if (direction != Direction::DOWN) {
                    direction = Direction::UP;
                }
                break;
            case 80: // 80 is down
                if (direction != Direction::UP)
                    direction = Direction::DOWN;
                break;
            case 75: // 75 is left
                if (direction != Direction::RIGHT)
                    direction = Direction::LEFT;
                break;
            case 77: // 77 is right
                if (direction != Direction::LEFT)
                    direction = Direction::RIGHT;
                break;
            default:
                break;
            }
            return true;

        case 27://ESC
            return false;

        default:
            return true;
        }
    }
    return true;
}

bool Snake::getFood(const Food food) {
    if (snake.back().getX() == food.x && snake.back().getY() == food.y) {
        return true;
    }
    else {
        return false;
    }
}