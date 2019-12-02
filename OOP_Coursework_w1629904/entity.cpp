#include "entity.h"

entity::entity(pair<int, int> _Pos) {
	Pos = _Pos;
	active = true;
}

void entity::Update() {
	setPos({ Pos.first + velocity.first, Pos.second + velocity.second });
}
pair<int, int> entity::getPos() {return this->Pos;}
void entity::setPos(pair<int, int> _newPos = { 0,0 }) { this->Pos = _newPos; }
bool entity::getActive() {return active;}
void entity::setActive(bool _active) { active = _active; }
char entity::getIden() { return iden; }

void entity::classAction(vector<entity>& _charList, int& _lives, int& _score) {
	//do different things depending on class
	switch (iden) {
	case 'V'://arrow
		for (entity& e : _charList) {
			//look for monsters only
			if (e.iden != 'O') { continue; }
			//if touching deactivate
			if (e.getPos().first == getPos().first && (e.getPos().second == getPos().second || e.getPos().second - 1 == getPos().second)) {
				e.setActive(false);
				setActive(false);
				_score += 50;
			}
		}
		break;
	case 'O':
		if (getPos().second == 0) {
			--_lives;
		}
		break;
	}
}