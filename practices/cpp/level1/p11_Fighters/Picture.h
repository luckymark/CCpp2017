#pragma once
#include <SFML/Graphics.hpp>

class Picture
{
public:
	Picture();
	bool exist();
	void produce(int i, int position_x, int position_y);
	void Picture::produce(int texture_position_x, int texture_position_y);
	sf::Sprite get();
	int getx();
	void initialize();
private:
	int x, y;
	sf::Texture boom_picture;
	sf::Sprite boom;
};