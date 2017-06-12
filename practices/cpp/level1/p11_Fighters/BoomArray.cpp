#include "BoomArray.h"

BoomArray::BoomArray(int num)
{
	this->num = num;
	b = new Picture[num];
}

void BoomArray::produce(int i, int position_x, int position_y)
{
	for (int j = 0; j < num; j++) {
		if (b[j].getx()<=0|| b[j].getx() >= 1080) {
 			b[j].produce(i, position_x,position_y);
			break;
		}
	}
}

sf::Sprite BoomArray::get(int No)
{
	return b[No].get();
}

bool BoomArray::exist(int No)
{
	if (b[No].exist()) {
		return true;
	}
	return false;
}

void BoomArray::initialize(int No, int time)
{
	if (time % 20 == 0) {
		b[No].initialize();
	}
}