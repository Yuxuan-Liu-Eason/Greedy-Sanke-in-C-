#include "tools.h"
#include <windows.h>
#include <stdio.h>

// Apply the windows library to enable some basic tools that will be used in the program

// set window size and title
void setWindowSize(int cols, int lines) {
    SetConsoleTitleA("Greedy Snake");
    char cmd[30];
    sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);
    system(cmd);
}

// Set cursor position. This is the most important method to accomplish the dynamic move of snake
void setCursorPosition(const int x, const int y) {
    COORD position; // Use a coordinate
    position.X = x * 2;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

// Set text color
void setColor(int colorID) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}
