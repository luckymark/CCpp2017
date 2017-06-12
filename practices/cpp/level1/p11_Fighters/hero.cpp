#include"hero.h"
Hero::Hero():Entity()
{
	//mTexture.loadFromFile("resources/image/shoot.png",sf::IntRect(0, 100, 100, 135));
	this->setText("resources/image/he1.jpg",0,0,0,0);//("resources/image/shoot.jpg",0,99,102,126)
	crashTexture1.loadFromFile("resources/image/he2.jpg",sf::IntRect(0,0,0,0));//("resources/image/shoot.png",sf::IntRect(165, 234, 102, 126))
	crashTexture2.loadFromFile("resources/image/he3.jpg",sf::IntRect(0,0,0,0));//("resources/image/shoot.png",sf::IntRect(330, 498, 102, 126))
	crashTexture3.loadFromFile("resources/image/shoot.png",sf::IntRect(432, 624, 102, 126));//还没改
	this->setTexture(*(getText()));
	this->setPosition(screenX - 300, screenY - 100);
    this->setSpeed(500);
    mIsMovingUp = false; mIsMovingDown = false; mIsMovingLeft = false; mIsMovingRight=false;
    deleteTimer=1000;
    this->setHP(500);//他的 生命值

    fireSound.openFromFile("resources/sound/bullet.ogg");
}

void Hero::moveNode(sf::Time deltaTime)
{

	sf::Vector2f movement(0.f,0.f);
	if (mIsMovingUp&&this->getPosition().y>0)
		movement.y -= getSpeed();
	if (mIsMovingDown&&this->getPosition().y<700)
		movement.y += getSpeed();
	if (mIsMovingLeft&&this->getPosition().x>0)
		movement.x -= getSpeed();
	if (mIsMovingRight&&this->getPosition().x<380)
		movement.x += getSpeed();
	this->move(movement*deltaTime.asSeconds());

	//移动子弹
	for (std::vector<Bullet*>::iterator it = allBullet.begin(); it != allBullet.end(); ++it)
    {
        if((*it)->getPosition().y<=0)
        {
            delete *it;
            allBullet.erase(it);
            it--;
            continue;
        }
        (*it)->moveNode(deltaTime);
    }

}

std::vector<Bullet*> Hero::getBulletVector()
{
    return allBullet;
}

void Hero::fire()
{
    fireSound.play();
    allBullet.push_back(new Bullet(this->getPosition().x+51,this->getPosition().y,0,-1,hero));
    allBullet.push_back(new Bullet(this->getPosition().x+51,this->getPosition().y,0.2f,-1.f,hero));
    allBullet.push_back(new Bullet(this->getPosition().x+51,this->getPosition().y,-0.2f,-1,hero));
}

void Hero::deleteDie()
{
    for (std::vector<Bullet*>::iterator it = allBullet.begin(); it != allBullet.end(); ++it)
    {
        if((*it)->checkAlive()<=0)
        {
            delete *it;
            allBullet.erase(it);
            it--;
        }
    }
}

void Hero::crash()
{
    this->die();
    this->setTexture(crashTexture1);
}

bool Hero::ruin()
{
    deleteTimer--;
    if(deleteTimer==0)
        return true;

    if(deleteTimer==666)
    {
        this->setTexture(crashTexture2);
    }
    if(deleteTimer==333)
    {
        this->setTexture(crashTexture3);
    }

    return false;
}

