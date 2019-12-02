#include "world.h"
#include <Windows.h>
#include <typeinfo>
#include <conio.h>
world::world(pair<int, int> _gsize) {
	srand(time(NULL));
	addItem(3, 2, 'P');
	gridsize = _gsize;
	lives = 5;
	score = 0;
	gameDone = false;
	state = 0;
	spawnTimer = 0;
	maxSpawnTimer = 8;
}
//this allows me to add an item to a map
void world::addItem(int _xPos, int _yPos, char tag) {
	switch (tag){
	case 'P':
		charList.push_back(player({_xPos,_yPos}));
		break;
	case 'E':
		charList.push_back(enemy({ _xPos,_yPos }));
		break;
	case 'A':
		charList.push_back(arrow({ _xPos,_yPos }));
		break;
	}
}
void world::Draw() {
	//draw the HUD
	system("cls");
	printHUD();
	//go through grid vector print what's in the grid
	for (int i = 0; i < gridsize.second; i++) {
		for (int j = 0; j < gridsize.first; j++) {
			cout << "[";
			//possibly print out character or a space
			bool haschar = false;
			if (i == 0) { cout << '+'; haschar = true; }
			for (entity& e : charList) {
				if (pair<int, int>(j, i) == e.getPos()) { cout << e.getIden(); haschar = true; }
			}
			if(!haschar) { cout << " "; }
			cout << "]";
		}
		cout << endl;
	}
}
void world::printHUD() {
	cout << "Lives:";
	for (int i = 0; i < lives; i++) {
		cout << "<->";
	}
	cout << "\t Score:" << score;
	cout << endl;
}
void world::Update() {
	//check if gameis over
	checkGameEnd();
	//check if enemies or arrows need to be removed
	checktoDelete();
	//spawn enemies after some time
	//the enemies spawn on any tile on the bottom row
	if (spawnTimer == 0) { addItem((rand() % gridsize.first-1) + 1,14, 'E'); spawnTimer = (rand() % 10) +1; }
	else {
		spawnTimer--;
	}
	//get the players input
	getCharInput();
	//update the characters
	for (entity& e:charList) {
		e.classAction(charList,lives, score);
		e.Update();
	}
}
void world::getCharInput() {
	//don't continue until you get input
	while (input == NULL) {
		cout << "type in which action you want to take" << endl << "A  for left, D for right and space/s for arrow shot" << endl;
		input = _getch();
		//since the player will be the first item of the vector use that
		switch (input) {
		case 'a':
			if (charList[0].getPos().first > 0) {
				charList[0].setPos({ charList[0].getPos().first - 1, charList[0].getPos().second });
			}
			break;
		case 'd':
			if (charList[0].getPos().first < gridsize.first-1) {
				charList[0].setPos({ charList[0].getPos().first + 1, charList[0].getPos().second });
			}
			break;
		case ' '://arrow shooting
			addItem(charList[0].getPos().first, charList[0].getPos().second, 'A');
			break;
		default:
			cout << "type in a correct input please" << endl;
			input = NULL;
			break;

		}
	}
	input = NULL;
}
void world::checktoDelete() {
	//remove from list if out of bounds or not active
	for (unsigned i = 0; i < charList.size(); i++) {
		if (charList[i].getActive() == false|| 
			charList[i].getPos().first < 0 ||
			charList[i].getPos().first > gridsize.first ||
			charList[i].getPos().second < 0 ||
			charList[i].getPos().second > gridsize.second)
		{
			charList.erase(charList.begin()+i);
		}
	}
}
void world::checkGameEnd() {
	gameDone =  score > 1000 || lives == 0;
}