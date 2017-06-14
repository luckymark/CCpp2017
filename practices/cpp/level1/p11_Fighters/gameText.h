#ifndef GAMETEXT_H
#include<SFML/Graphics.hpp>
#define GAMETEXT_H
class gameText {
		char type;
		int data;
		sf::Font font;
		sf::Text text;
	public:
		gameText(char type='h',int data=0);
		void setGameText(std::string s);
		void setData(int data);
		void setScore(int data);
		void setPosition(int x, int y);
		void setScale(int size);
		void showText(sf::RenderWindow &thisWindow);
		
};
void setInformation(gameText & information, std::string s, int x, int y, int size);
#endif
