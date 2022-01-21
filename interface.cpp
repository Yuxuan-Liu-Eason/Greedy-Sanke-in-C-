#include "interface.h"
#include "tools.h"
#include "map.h"
#include "food.h"
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <chrono>

using namespace std;
using namespace chrono;

// Interface class controls the game interfaces
Interface::Interface() {
	iScore = 0;
	iDifficulty = 2;
	sName = "Unknown";
	iSecond = 0;
}

// Game start interface
void Interface::startInterface() {

	// Animation of title
	for (int i = 1; i <= 9; i++) {
		Sleep(70);
		system("cls");
		setCursorPosition(i, 15);
		cout << "Welcome to Greedy Snake\n";
		setCursorPosition(18 - i, 16);
		cout << "Press any key to start";
	}

	// Press any key to start
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
	cin >> sName;
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
	while ((ch != 13)) { // 13=ENTER
		ch = _getch();
		switch (ch) {
		case 72: // up
			if (iDifficulty == 2) {
				setCursorPosition(12, 16);
				iDifficulty = 1;
			}
			else if (iDifficulty == 3) {
				setCursorPosition(13, 17);
				iDifficulty = 2;
			}
			break;

		case 80: // down
			if (iDifficulty == 2) {
				setCursorPosition(12, 18);
				iDifficulty = 3;
			}
			else if (iDifficulty == 1) {
				setCursorPosition(13, 17);
				iDifficulty = 2;
			}
			break;

		default:
			break;
		}
	}
	system("cls");
}

// Pause interface
bool Interface::bPauseInterface() {

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

	// Select continue or quit
	int ch = 0;
	bool quit = false;
	while ((ch != 13)) {
		ch = _getch();
		switch (ch) {
		case 72:// up
			if (quit == false) {
				setCursorPosition(39, 8);
				quit = true;
			}
			break;

		case 80:// down
			if (quit == true) {
				setCursorPosition(40, 9);
				quit = false;
			}
			break;

		default:
			break;
		}
	}
	return quit;
}

// Game statistics interface
void Interface::statsInterface(Food* ptrFood) {

	setColor(7); // set color to white
	// Count food*100 as score
	setCursorPosition(32, 1);
	cout << "Score:";
	iScore = (ptrFood->getCnt() - 1) * 100;
	setCursorPosition(36, 1);
	cout << iScore << endl;

	// Count seconds since game starts
	static auto start = high_resolution_clock::now();
	auto end = high_resolution_clock::now();
	iSecond = duration_cast<seconds>(end - start).count();
	setCursorPosition(32, 2);
	cout << "Seconds:";
	setCursorPosition(36, 2);
	cout << duration_cast<seconds>(end - start).count();
}

// Game over interface
bool Interface::bEndInterface() {

	system("cls");
	Sleep(500);
	setColor(7);
	setCursorPosition(12, 15);
	cout << "Game Over";
	Sleep(1000);
	system("cls");

	setCursorPosition(9, 15);
	cout << "Your score is: " << iScore;
	setCursorPosition(7, 17);
	cout << "Do you want to play again?";
	setCursorPosition(10, 18);
	cout << "Yes";
	setCursorPosition(14, 18);
	cout << "No";
	setCursorPosition(15, 18);

	// Selet if play again or not
	int ch = 0;
	bool playAgain = false;
	while ((ch != 13)) {
		ch = _getch();
		switch (ch) {
		case 75:// Left
			if (playAgain == false) {
				setCursorPosition(12, 18);
				playAgain = true;
			}
			break;

		case 77:// right
			if (playAgain == true) {
				setCursorPosition(15, 18);
				playAgain = false;
			}
			break;

		default:
			break;
		}
	}
	setCursorPosition(0, 30); // Set cursor at the bottom
	return playAgain;
}