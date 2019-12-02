#include "enemy.h"
enemy::enemy(pair<int, int> _Pos):entity(_Pos) {
	iden = 'O';
	velocity = { 0,-1 };
}