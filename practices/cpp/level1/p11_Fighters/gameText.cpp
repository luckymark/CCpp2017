#include"stdafx.h"
#include"gameText.h"
#include<SFML/Graphics.hpp>
gameText::gameText(char type, int data) {
	switch (type) {
		case 's':
			font.loadFromFile("AdobeDevanagari-Regular.otf");
			text.setFont(font);
			text.setCharacterSize(20);
			text.setFillColor(sf::Color::White);
			text.setPosition(700, 580);
			text.setStyle(sf::Text::Bold);
			text.setString("Score:" + std::to_string(data));
			this->data = data;
			this->type = type;
			break;
		case 'l':
			font.loadFromFile("AdobeDevanagari-Regular.otf");
			text.setFont(font);
			text.setCharacterSize(20);
			text.setFillColor(sf::Color::White);
			text.setPosition(0, 580);
			text.setStyle(sf::Text::Bold);
			text.setString("Life:" + std::to_string(data));
			this->data = data;
			this->type = type;
			break;
		default:
			;
	}
}
void gameText::setGameText(std::string s) {
	text.setString(s);
}
void gameText::setData(int data) {
	this->data = data;
}
void gameText::setScore(int data) {
	this->setData(data);
	this->setGameText("Score:" + std::to_string(data));
}
void gameText::showText(sf::RenderWindow &thisWindow) {
	thisWindow.draw(this->text);
}