#include"entity.h"
class Bullet:public Entity
{
public:
	Bullet(int x,int y,float bulletx,float bullety,int type);
	void moveNode(sf::Time deltaTime);
private:
    float bulletx,bullety;
};
