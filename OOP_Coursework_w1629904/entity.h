#pragma once
#include <iostream>
#include <vector>
using namespace std;
class entity {
public:
	pair<int, int> Pos, velocity;
	char iden;
	bool active;
	entity(pair<int, int> _Pos) ;
	pair<int, int> getPos();
	void setPos(pair<int, int> _newPos);
	bool getActive();
	void setActive(bool _active);
	char getIden();
	void Update();
	virtual void classAction(vector<entity>& _charList, int& _lives, int& _score);
};
