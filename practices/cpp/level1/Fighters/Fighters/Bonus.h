#ifndef BONUS_H
#define BONUS_H
#include <SFML/Graphics.hpp>
#include "Action.h"
#include "RTexture.h"

class Bonus:public Action
{
public:
	Bonus(float x, float y);
    virtual~Bonus();
    void MoveRand();
	void set_bonusstate(int bonusstate);
	int get_bonusstate();

private:
	sf::Vector2f direction;
	sf::Texture *texture;
	int bonusstate = 0;
};
#endif //BONUS_H
