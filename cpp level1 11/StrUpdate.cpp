#include "stdafx.h"
#include "StrUpdate.h"


int StrUpdate::life = 3;
int StrUpdate::score = 0;

extern sf::RenderWindow mainWindow;
void StrUpdate::update()
{
	
		sf::Font font;
		font.loadFromFile("D:\\SFML-2.4.2-windows-vc14-32-bit\\SFML-2.4.2\\Sansation.ttf");
		std::string s1 = NumToStr(life);
		std::string s2 = NumToStr(score);
		std::string s= "life:" + s1 +" "+ "score:" + s2;
		sf::Text text(s, font, 30);	
		mainWindow.draw(text);
		
}

std::string StrUpdate::NumToStr(int i)
{
	std::stringstream ss;
	ss << i;
	return ss.str();
}