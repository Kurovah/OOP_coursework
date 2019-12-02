// OOP_Coursework_w1629904.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <io.h>
#include <fcntl.h>
#include "world.h"
using namespace std;
int main()
{
	world nw({7, 15});
	nw.Draw();
	while (!nw.gameDone) {
		nw.Update();
		nw.Draw();
	}
	return 0;
}
