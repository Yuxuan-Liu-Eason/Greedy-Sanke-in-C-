#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "tools.h"
#include "snake.h"
#include "food.h"
#include "point.h"
#include "interface.h"

using namespace std;

void play();
void createRankFile(Interface*, const string);
void countDown();
bool sortcol(const vector<string>&, const vector<string>&);

// Play a greedy snake game
int main() {
	setWindowSize(50, 40);
	play();
	return 0;
}

// Play the game
void play() {

	Interface* ptrInterface = new Interface();
	Map* ptrMap = new Map();
	int iSpeed = 150; // Default speed

	ptrInterface->startInterface(); // Run start interface
	string name = ptrInterface->sName;

	// Adjust speed according to difficulty
	if (ptrInterface->iDifficulty == 1) {
		iSpeed = 250;
	}
	else if (ptrInterface->iDifficulty == 3) {
		iSpeed = 70;
	}

	ptrMap->drawMap(ptrInterface->iDifficulty); // Draw map

	Snake* ptrSnake = new Snake();
	ptrSnake->initSnake(); // Draw snake
	Food* ptrFood = new Food();

	ptrFood->drawFood(ptrSnake, ptrInterface->iDifficulty); // Draw the first food

	// Count 3, 2, 1 then START
	countDown();

	while (true) {
		// if press ESC
		if (!ptrSnake->bChangeDirection()) {
			// if end game
			if (ptrInterface->bPauseInterface()) {
				// if play again
				if (ptrInterface->bEndInterface()) {
					system("cls");
					play();
				}
				break;
			}
			else {
				// clear pause text
				for (int i = 4; i <= 11; i++) {
					setCursorPosition(31, i);
					cout << "                          ";
				}
			}
		}

		// If get food, snake grows, draw next food
		if (ptrSnake->bGetFood(ptrFood)) {
			ptrFood->drawFood(ptrSnake, ptrInterface->iDifficulty);
			ptrSnake->grow();
		}
		else {
			ptrSnake->move(); // Else just normal move
		}

		// If hit wall or hit self, game ends. Otherwise, continue in loop
		if (ptrSnake->bHitWall(ptrInterface->iDifficulty) || ptrSnake->bHitSelf()) {
			delete ptrSnake; // release memory
			delete ptrFood;
			delete ptrMap;

			if (ptrInterface->bEndInterface()) { // If play again, call play() recursively
				system("cls");
				play();
			}
			break; // Else, quit game
		}

		// Show scores and times
		ptrInterface->statsInterface(ptrFood);
		setCursorPosition(1, 31); // Set cursor at lower left corner
		Sleep(iSpeed);
	}

	createRankFile(ptrInterface, name); // Create a rank file after each game
	delete ptrInterface;
}

// Create a csv file of ranking of each player
void createRankFile(Interface* ptrInterface, const string sName) {

	ifstream input("rank.csv");
	string sLine, sWord;
	// Use a 2d vector to store the data
	vector<vector<string>> vecRecords;

	// Drop first row of title
	getline(input, sLine);
	int i = 1;
	vector<string> emptyVec;
	vector<string> currentGame = { sName, to_string(ptrInterface->iScore), to_string(ptrInterface->iDifficulty) };
	vecRecords.push_back(currentGame); // Record current game score

	// Read csv file into 2d vector
	while (getline(input, sLine, input.widen('\n'))) {
		vecRecords.push_back(emptyVec);
		stringstream s(sLine);
		while (getline(s, sWord, ',')) {
			vecRecords[i].push_back(sWord);
		}
		i++;
	}
	input.close();

	ofstream rank("rank.csv");
	// Sort the 2d vector based on score
	sort(vecRecords.begin(), vecRecords.end(), sortcol);

	// Output to the ranking file
	rank << "Name,Score,Difficulty" << endl;
	for (int i = 0; i < vecRecords.size(); i++)
	{
		for (int j = 0; j < 3; j++) {
			rank << vecRecords[i][j] << ",";
		}
		rank << endl;
	}
	rank.close();
}

// A simple count down before game starts
void countDown() {
	setColor(7);
	setCursorPosition(15, 15);
	cout << "3";
	Sleep(800);
	setCursorPosition(15, 15);
	cout << "2";
	Sleep(800);
	setCursorPosition(15, 15);
	cout << "1";
	Sleep(800);
	setCursorPosition(14, 15);
	cout << "START";
	Sleep(800);
	setCursorPosition(14, 15);
	cout << "     ";
}

// Driver function to sort the 2D vector on basis of a particular column
bool sortcol(const vector<string>& v1,
	const vector<string>& v2) {
	return stoi(v1[1]) > stoi(v2[1]);
}