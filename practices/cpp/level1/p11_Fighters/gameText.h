#ifndef GAMETEXT_H
#include<SFML/Graphics.hpp>
#define GAMETEXT_H
class gameText {
		char type;
		int data;
		sf::Font font;
		sf::Text text;
	public:
		gameText(char type,int data);
		void setGameText(std::string s);
		void setData(int data);
		void setScore(int data);
		void showText(sf::RenderWindow &thisWindow);
		
};
#endif
