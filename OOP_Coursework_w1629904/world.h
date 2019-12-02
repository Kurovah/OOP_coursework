#pragma once
#include <vector>
#include "entity.h"
#include "player.h"
#include "enemy.h"
#include "arrow.h"
#include <time.h>
using namespace std;
class world {
public:
	pair<int, int> gridsize;
	vector<entity> charList;
	int state, lives, score, spawnTimer,maxSpawnTimer;
	bool gameDone;
	char input, input2;
	world(pair<int, int> _gsize = {0,0});
	//this allows me to add a player whereever I want on a map
	void addItem(int _xPos, int _yPos, char _tag);
	void Draw();
	void printHUD();
	void Update();
	void getCharInput();
	void checktoDelete();
	void checkGameEnd();
};