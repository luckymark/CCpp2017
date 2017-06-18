#include "stdafx.h"
#include "StrUpdate.h"
#define section 50

int StrUpdate::life = 40;
int StrUpdate::score = 0;

extern sf::RenderWindow mainWindow;
void StrUpdate::update()
{
	
		sf::Font font;
		font.loadFromFile("D:\\SFML-2.4.2-windows-vc14-32-bit\\SFML-2.4.2\\Sansation.ttf");
		
		if (score > upper)
		{
			level++;
			range = range + section;
			upper = upper + range;

		}
		std::string s1 = NumToStr(life);
		std::string s2 = NumToStr(score);
		std::string s3 = NumToStr(level);
		std::string s;
		if (Plane::weaponStatus == 0)
		{
			s = "life:" + s1 + " " + "score:" +s2+" "+"weapon:"+" "+"missile"+" level: "+ s3;
		}
		else if (Plane::weaponStatus == 1)
		{
			s = "life:" + s1 + " " + "score:" +s2+" "+"weapon:"+" "+"shot" + " level: " + s3;
		}
		sf::Text text(s, font, 30);	
		mainWindow.draw(text);

}

std::string StrUpdate::NumToStr(int i)
{
	std::stringstream ss;
	ss << i;
	return ss.str();
}

int StrUpdate::level = 1;
int StrUpdate::range = section;
int  StrUpdate::upper = section;