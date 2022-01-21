#ifndef INTERFACE_H
#define INTERFACE_H
#include "map.h"
#include "food.h"
#include <string>

// Game interfaces 
class Interface {
public:
	Interface();
	~Interface() {};
	void startInterface();
	void statsInterface(Food*);
	bool bEndInterface();
	bool bPauseInterface();
	int iDifficulty;
	string sName;
	int iScore;
	int iSecond;
};

#endif
