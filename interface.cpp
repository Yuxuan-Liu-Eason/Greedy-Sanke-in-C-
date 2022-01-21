#include "interface.h"
#include "tools.h"
#include "map.h"
#include "food.h"
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

Interface::Interface() {
	score = 0;
	diff = 2;
	name = "Unknown";
	second = 0;
}

void Interface::startInterface() {

	for (int i = 1; i <= 9; i++) {
		Sleep(70);
		system("cls");
		setCursorPosition(i, 15);
		cout << "Welcome to Greedy Snake\n";
		setCursorPosition(18 - i, 16);
		cout << "Press any key to start";
	}
	int ch = 0;
	while (true) {
		ch = _getch();
		if (ch != 0) {
			system("cls");
			break;
		}
	}

	// Enter player name
	setCursorPosition(9, 15);
	cout << "Please enter your name: ";
	setCursorPosition(9, 16);
	cin >> name;
	system("cls");

	// Print difficulty for player to choose
	setCursorPosition(7, 14);
	cout << "Enter select difficulty:";
	setCursorPosition(10, 16);
	cout << "Easy";
	setCursorPosition(10, 17);
	cout << "Medium";
	setCursorPosition(10, 18);
	cout << "Hard";
	setCursorPosition(13, 17);
	
	// Select difficulty
	ch = 0;
	while ((ch != 13)) {
		ch = _getch();
		switch (ch) {
		case 72:// up
			if (diff == 2) {
				setCursorPosition(12, 16);
				diff = 1;
			}
			else if (diff == 3) {
				setCursorPosition(13, 17);
				diff = 2;
			}
			break;

		case 80:// down
			if (diff == 2) {
				setCursorPosition(12, 18);
				diff = 3;
			}
			else if (diff == 1) {
				setCursorPosition(13, 17);
				diff = 2;
			}
			break;

		default:
			break;
		}
	}
	system("cls");
}

bool Interface::pauseInterface() {

	setCursorPosition(31, 4);
	cout << "--------------------------";
	setCursorPosition(31, 5);
	cout << "|                        |";
	setCursorPosition(31, 6);
	cout << "|         Pause          |";
	setCursorPosition(31, 7);
	cout << "|                        |";
	setCursorPosition(31, 8);
	cout << "|          quit          |";
	setCursorPosition(31, 9);
	cout << "|        continue        |";
	setCursorPosition(31, 10);
	cout << "|                        |";
	setCursorPosition(31, 11);
	cout << "--------------------------";
	setCursorPosition(40, 9);

	int ch = 0;
	bool flag = false;
	while ((ch != 13)) {
		ch = _getch();
		switch (ch) {
		case 72:// up
			if (flag == false) {
				setCursorPosition(39, 8);
				flag = true;
			}
			break;

		case 80:// down

			if (flag == true) {
				setCursorPosition(40, 9);
				flag = false;
			}
			break;

		default:
			break;
		}
	}
	return flag;
}

void Interface::statsInterface(Food fd) {
	setColor(7);
	setCursorPosition(32, 1);
	cout << "Score:";
	score = (fd.getCnt() - 1) * 100;
	setCursorPosition(36, 1);
	cout << score << endl;

	// Count seconds
	static auto start = high_resolution_clock::now();
	auto end = high_resolution_clock::now();
	second = duration_cast<seconds>(end - start).count();
	setCursorPosition(32, 2);
	cout << "Seconds:";
	setCursorPosition(36, 2);
	cout << duration_cast<seconds>(end - start).count();
}

bool Interface::endInterface() {
	system("cls");
	Sleep(500);
	setColor(7);
	setCursorPosition(12, 15);
	cout << "Game Over";
	Sleep(1000);
	system("cls");
	setCursorPosition(9, 15);
	cout << "Your score is: " << score;
	setCursorPosition(7, 17);
	cout << "Do you want to play again?";
	setCursorPosition(10, 18);
	cout << "Yes";
	setCursorPosition(14, 18);
	cout << "No";
	setCursorPosition(15, 18);

	int ch = 0;
	bool flag = false;
	while ((ch != 13)) {
		ch = _getch();
		switch (ch) {
		case 75:// Left
			if (flag == false) {
				setCursorPosition(12, 18);
				flag = true;
			}
			break;

		case 77:// right
			
			if (flag == true) {
				setCursorPosition(15, 18);
				flag = false;
			}
			break;

		default:
			break;
		}
	}
	setCursorPosition(0, 30);
	return flag;
}