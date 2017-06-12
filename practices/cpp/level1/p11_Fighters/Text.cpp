#include "Text.h"

Text::Text()
{
	font.loadFromFile("CroissantD.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::Yellow);
}

void Text::setmark(int type, std::string Str)
{
	std::string s;
	if (type == 1) {
		s = "The score is:  ";
		text.setPosition(850, 10);
		text.setCharacterSize(50);
	}
	if (type == 2) {
		s = "Your life left:  ";
		text.setPosition(10, 10);
		text.setCharacterSize(50);
	}
	if (type == 3) {
		s = "The time left:  ";
		text.setPosition(450, 10);
		text.setCharacterSize(50);
	}
    if (type == 4) {
		s = "mode: ";
		text.setPosition(450,400);
		text.setCharacterSize(50);
	}
	if (type == 5) {
		s = "level:";
		text.setPosition(450, 500);
		text.setCharacterSize(50);
	}
	if (type == 6) {
		s = "direction:     Fire:space  ";
		text.setPosition(400, 650);
		text.setCharacterSize(50);
	}
	if (type == 7) {
		s = "        You have death,your scores is ";
		s = s + Str;
		Str = ". \nPlease press R if you want to play again, press Q if you want quit!";
		s = s + Str;
		Str = "";
		text.setFillColor(sf::Color::Red);
		text.setPosition(200, 400);
		text.setCharacterSize(50);
	}
	if (type == 8) {
		s = "        Congradulations! You have death,your scores is ";
		s = s + Str;
		Str = ". \nPlease press R if you want to play again, press Q if you want quit! ";
		s = s + Str;
		Str = "";
		text.setFillColor(sf::Color::Red);
		text.setPosition(200, 400);
		text.setCharacterSize(50);
	}
	s = s + Str;
	text.setString(s);
};

sf::Text Text::draw()
{
	return text;
}

void Text::setsize(int i)
{
	text.setCharacterSize(i);
}
