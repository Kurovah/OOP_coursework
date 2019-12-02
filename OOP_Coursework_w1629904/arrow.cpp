#include "arrow.h"
arrow::arrow(pair<int, int> _Pos) :entity(_Pos) {
	iden = 'V';
	velocity = { 0,1 };
}