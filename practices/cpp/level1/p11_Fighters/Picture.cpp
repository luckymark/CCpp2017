#include "Picture.h"

Picture::Picture()
{
	x = 0;
	y = 0;
}

bool Picture::exist()
{
	if (x == 0) {
		return false;
	}
	return true;
}

void Picture::produce(int i, int position_x, int position_y)
{
	using namespace std;
	string s;
	s = to_string(i);
	s = "xiao_" + s + ".png";
	x = position_x;
	y = position_y;
	boom_picture.loadFromFile(s);
	boom.setTexture(boom_picture);
	boom.setPosition(x, y);
}

void Picture::produce(int texture_position_x, int texture_position_y)
{
	boom.setTexture(boom_picture);
	boom.setTextureRect(sf::IntRect(texture_position_x, texture_position_y, 1200, 1080));
}

sf::Sprite Picture::get()
{
	return boom;
}

int Picture::getx()
{
	return x;
}

void Picture::initialize()
{
	x = 0;
	y = 0;
	boom.setPosition(x, y);
}