#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include<windows.h>
#define screenY 800
#define screenX 480
#define boss 4
#define hero 3
#define elite 2
#define normal 1

class Entity:public sf::Sprite
{
public:
	Entity();
	Entity(int sHP);
	void setText(char* filePath,int x1,int y1,int x2,int y2);
	sf::Texture* getText();
	void setSpeed(int a);
	void setHP(int a);
	float getSpeed();
	void die();
	int checkAlive();
private:
	sf::Texture mTexture;
	float Speed;
	int HP;
};
