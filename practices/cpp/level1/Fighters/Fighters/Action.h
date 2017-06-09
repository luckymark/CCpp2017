#ifndef ACTION_H
#define ACTION_H
#include <SFML/Graphics.hpp>
#include <cmath>
#define Pi 3.14
class Action :public sf::Sprite
{
public:
	Action();
	virtual ~Action();
	void move(sf::Vector2f direction);
	void move();
	void bossBulletMove(int i);
	void setSpeed(float speed);
	void setBulletSpeed(float bullet_speed);
	
protected:
	sf::Vector2f direction;

private:
	float speed = 1.0f;
	float bullet_speed = 1.0f;
};

#endif // ACTION_H
