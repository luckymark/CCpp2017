#pragma once
#include <SFML/Graphics.hpp>
#include<string.h>

class Text
{
public:
	Text();
	void setmark(int type,std::string Str);
	sf::Text draw();
	void setsize(int i);
private:
	sf::Text text;
	sf::Font font;
};