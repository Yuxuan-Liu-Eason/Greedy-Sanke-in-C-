#include "tools.h"
#include <windows.h>
#include <stdio.h>

void setWindowSize(int cols, int lines) {
    system("Greedy Snake");
    char cmd[30];
    sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);
    system(cmd);
}

void setCursorPosition(const int x, const int y)
{
    COORD position;
    position.X = x * 2;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void setColor(int colorID)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}
