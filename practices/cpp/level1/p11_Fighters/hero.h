#include"Bullet.h"

class Hero:public Entity
{
public:
	Hero();
	void moveNode(sf::Time deltaTime);
	void fire();
	void isMovingUp(bool b)
	{
	    mIsMovingUp=b;
	}
	void isMovingDown(bool b)
	{
	    mIsMovingDown=b;
	}
	void isMovingLeft(bool b)
	{
	    mIsMovingLeft=b;
	}
	void isMovingRight(bool b)
	{
	    mIsMovingRight=b;
	}
	void deleteDie();
	std::vector<Bullet*> getBulletVector();
	void crash();
	bool ruin();
private:
	bool mIsMovingUp = false, mIsMovingDown = false, mIsMovingLeft = false, mIsMovingRight=false;
	//static int HP=3;
	sf::Texture crashTexture1;
	sf::Texture crashTexture2;
	sf::Texture crashTexture3;
	std::vector<Bullet*>allBullet;
	sf::Music fireSound;
	int deleteTimer;
};
