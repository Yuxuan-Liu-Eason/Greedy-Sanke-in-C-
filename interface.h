#ifndef INTERFACE_H
#define INTERFACE_H
#include "map.h"
#include "food.h"
#include <string>

class Interface {
public:
	Interface();
	void startInterface();
	void statsInterface(Food);
	bool endInterface();
	bool pauseInterface();
	int diff;
	string name;
	int score;
	int second;
};

#endif
