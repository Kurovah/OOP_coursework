#include "player.h"
player::player(pair<int, int> _Pos) :entity(_Pos) {
	iden = 'P';
	Pos = _Pos;
}