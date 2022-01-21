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
void createRankFile(Interface, string);
void countDown();
bool sortcol(const vector<string>&, const vector<string>&);


// Driver function to sort the 2D vector
// on basis of a particular column
bool sortcol(const vector<string>& v1,
	const vector<string>& v2) {
	return stoi(v1[1]) > stoi(v2[1]);
}

// Create a csv file of ranking of each player
void createRankFile(Interface inter, string name) {

	ifstream input("rank.csv");
	string line, word;
	// Use a 2d vector to store the data
	vector<vector<string>> records;

	// Drop first row of title
	getline(input, line);
	int i = 1;
	vector<string> emptyVec;
	vector<string> currentGame = { name, to_string(inter.score), to_string(inter.diff) };
	records.push_back(currentGame); // Record current game score
	
	// Read csv file into 2d vector
	while (getline(input, line, input.widen('\n'))) {
		records.push_back(emptyVec);
		stringstream s(line);
		while (getline(s, word, ',')) {
			records[i].push_back(word);
		}
		i++;
	}
	input.close();

	ofstream rank("rank.csv");
	// Sort the 2d vector based on score
	sort(records.begin(), records.end(), sortcol);

	// Output to the ranking file
	int m = records.size();
	rank << "Name,Score,Difficulty" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 3; j++) {
			rank << records[i][j] << ",";
		}
		rank << endl;
	}
	rank.close();
}

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

void play() {
	Interface inter = Interface();
	Map mp = Map();
	int speed = 150;
	
	inter.startInterface();

	string name = inter.name;

	if (inter.diff == 1) {
		speed = 250;
	}
	else if (inter.diff == 3) {
		speed = 70;
	}

	mp.drawMap(inter.diff);
	
	Snake snk = Snake();
	snk.initSnake();
	Food fd = Food();

	fd.drawFood(snk, inter.diff);
	
	// Count 3, 2, 1 then START
	//countDown();

	while (true) {
		// if press ESC
		if (!snk.changeDirection()) {
			// if end game
			if (inter.pauseInterface()) {
				// if play again
				if (inter.endInterface()) {
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

		if (snk.getFood(fd)) {
			fd.drawFood(snk, inter.diff);
			snk.grow();
		}
		else {
			snk.move();
		}
		

		if (snk.hitEdge(inter.diff) || snk.hitSelf()) {
			if (inter.endInterface()) {
				system("cls");
				play();
			}
			break;
		}

		inter.statsInterface(fd);
		setCursorPosition(1, 31);
		Sleep(speed);
	}
	createRankFile(inter, name);
}


int main() {
	setWindowSize(50, 40);
	play();
}
