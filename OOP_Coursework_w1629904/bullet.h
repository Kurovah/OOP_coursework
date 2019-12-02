#include "enemy.h"
class bullet :public entity {
public:
	bullet(pair<int, int> _Pos = {0,0});
	void classAction(vector<enemy>& _charList);
};