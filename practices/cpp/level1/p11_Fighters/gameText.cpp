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
		case 't':
			font.loadFromFile("AdobeDevanagari-Regular.otf");
			text.setFont(font);
			text.setCharacterSize(20);
			text.setFillColor(sf::Color::White);
			text.setPosition(300, 580);
			text.setStyle(sf::Text::Bold);
			text.setString("Time:" + std::to_string(data));
			this->data = data;
			this->type = type;
			break;
		default:
			font.loadFromFile("AdobeDevanagari-Regular.otf");
			text.setFont(font);
			text.setCharacterSize(20);
			text.setFillColor(sf::Color::Blue);
			text.setStyle(sf::Text::Bold);
			this->data = 0;
			this->type = 'h';
			break;
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
void gameText::setPosition(int x, int y) {
	text.setPosition(x, y);
}
void gameText::setScale(int size) {
	text.setCharacterSize(size);
}
void gameText::showText(sf::RenderWindow &thisWindow) {
	thisWindow.draw(this->text);
}

void setInformation(gameText & information, std::string s, int x, int y, int size){
	information.setGameText(s);
	information.setPosition(x, y);
	information.setScale(size);
}
