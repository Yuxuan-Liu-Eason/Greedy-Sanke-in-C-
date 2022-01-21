#include "snake.h"
#include <conio.h>
#include "tools.h"
#include "Map.h"
#include <iostream>

using namespace std;

// Snake class controls the snake in the game. Initialize the snake with 3 points, direction to up
Snake::Snake() : Point() {
	dqeSnake.push_back(Point(15, 22));
    dqeSnake.push_back(Point(15, 21));
    dqeSnake.push_back(Point(15, 20));
    direction = Direction::UP;
}

// Override the virtual function in base class. Use circle as snake
void Snake::drawPoint(int x, int y) {
    setCursorPosition(x, y);
    cout << "¡ñ";
}

// draw initial snake
void Snake::initSnake() {
    setColor(2); // set color to green
	for (auto& p : dqeSnake) {
        this->drawPoint(p.getX(), p.getY());
	}
}

// Snake growth
void Snake::grow() {

    setColor(2); // set color to green

    switch (direction)
    {
    case Direction::UP: // when face up, add one point on the top of the current head as growth
        dqeSnake.emplace_back(Point(dqeSnake.back().getX(), dqeSnake.back().getY() - 1));
        break;
    case Direction::DOWN: // when face down, add one point on the bottom of the current head as growth
        dqeSnake.emplace_back(Point(dqeSnake.back().getX(), dqeSnake.back().getY() + 1));
        break;
    case Direction::LEFT: // when face left, add one point on the left of the current head as growth
        dqeSnake.emplace_back(Point(dqeSnake.back().getX() - 1, dqeSnake.back().getY()));
        break;
    case Direction::RIGHT: // when face right, add one point on the right of the current head as growth
        dqeSnake.emplace_back(Point(dqeSnake.back().getX() + 1, dqeSnake.back().getY()));
        break;
    default:
        break;
    }
    this->drawPoint(dqeSnake.back().getX(), dqeSnake.back().getY()); // draw the added point
}

// Snake move: add one point at head, remove one point at tail
void Snake::move() {
    grow();
    dqeSnake.front().clear();
    dqeSnake.pop_front();
}

// Determine if hit wall with the parameter of difficulty
bool Snake::bHitWall(int diff) {

    Point p = dqeSnake.back();

    // When the head is beyond the map, then hit map
    if (diff != 3) {
        return (p.getX() >= 30
            or p.getX() <= 1
            or p.getY() >= 30
            or p.getY() <= 1);
    }
    else { // If difficulty is hard, add obstacles
        return (p.getX() >= 30
            or p.getX() <= 1
            or p.getY() >= 30
            or p.getY() <= 1 
            or (p.getX() == 10 && (p.getY() >= 2 && p.getY() <= 15))
            or (p.getX() == 20 && (p.getY() >= 16 && p.getY() <= 29)));
    }
}

// Determine if hit self
bool Snake::bHitSelf() {

    Point p1 = dqeSnake.back();
    
    deque<Point> body = dqeSnake;
    body.pop_back(); // remove the head, only keep body
    // If head equals body, then means hit self.
    for (auto& p2 : body) {
        if (p1 == p2) {
            return true;
        }
    }
    return false;
}

// Change direction
bool Snake::bChangeDirection() {

    char ch;
    if (_kbhit()) { // If hit keyboard
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

// If get food
bool Snake::bGetFood(Food* food) {
    // If head overlaps with food, then means get food
    if (dqeSnake.back().getX() == food->iX && dqeSnake.back().getY() == food->iY) {
        return true;
    }
    else {
        return false;
    }
}