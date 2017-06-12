#include"enemy.h"

Enemy::Enemy(int type):Entity()
{
    if(type==normal)
    {
        this->setText("resources/image/enemy1.jpg",0,0,0,0);//("resources/image/enemy1.jpg",534,612,57,43);
        this->setTexture(*(getText()));
        crashTexture1.loadFromFile("resources/image/shoot.png",sf::IntRect(267, 347, 57, 51));
        crashTexture2.loadFromFile("resources/image/shoot.png",sf::IntRect(873, 697, 57, 51));
        crashTexture3.loadFromFile("resources/image/shoot.png",sf::IntRect(930, 697, 57, 51));
    }
    if(type==elite)
    {
        this->setText("resources/image/enemy3.jpg",0,0,69,95);//设置飞机的初始图像
        this->setTexture(*(getText()));
        crashTexture1.loadFromFile("resources/image/shoot.png",sf::IntRect(534, 653, 69, 95));//("resources/image/shoot.png",sf::IntRect(534, 653, 69, 95))
        crashTexture2.loadFromFile("resources/image/shoot.png",sf::IntRect(672, 653, 69, 95));
        crashTexture3.loadFromFile("resources/image/shoot.png",sf::IntRect(741, 653, 69, 95));
        this->setHP(6);
    }
    if(type==boss)
    {
        this->setText("resources/image/young.gif",0,0,0,0);//("resources/image/it.jpg",166,750,169,258);
        this->setTexture(*(getText()));
        crashTexture1.loadFromFile("resources/image/shoot.png",sf::IntRect(839, 748, 165, 260));
        crashTexture2.loadFromFile("resources/image/shoot.png",sf::IntRect(673, 748, 165, 260));
        crashTexture3.loadFromFile("resources/image/shoot.png",sf::IntRect(0, 747, 165, 260));
        this->setHP(100);
    }
	this->setPosition(rand()%screenX, 0);
    this->setSpeed(100);
    this->type=type;
    deleteTimer=1000;
    bossMoveLeft=true;

    crashSound1.openFromFile("resources/sound/enemy1_down.ogg");
    crashSound2.openFromFile("resources/sound/enemy2_down.ogg");
}

void Enemy::moveNode(sf::Time deltaTime)
{

    //移动子弹
	for (std::vector<Bullet*>::iterator it = allBullet.begin(); it != allBullet.end(); ++it)
    {
        if((*it)->getPosition().y>=screenY)
        {
            delete *it;
            allBullet.erase(it);
            it--;
            continue;
        }
        (*it)->moveNode(deltaTime);
    }

    //如果飞机已经坠毁，则不移动飞机
    if(checkAlive()<=0)
    {
        return;
    }

    //移动飞机
    if(type!=boss)
    {
        sf::Vector2f movement(0.f,0.f);
        movement.y += getSpeed();
        this->move(movement*deltaTime.asSeconds());
    }
    else
    {
        sf::Vector2f movement(0.f,0.f);
        if(this->getPosition().x<40)
        {
            bossMoveLeft=false;
            //movement.x=1.f;
        }
        if(this->getPosition().x>400)
        {
            bossMoveLeft=true;
        }
        if(bossMoveLeft)
        {
            movement.x=-1.f;
        }
        else movement.x=1.f;
        movement.x*=100;
        this->move(movement*deltaTime.asSeconds());
    }
}

void Enemy::fire()
{
    if(type!=boss)
        allBullet.push_back(new Bullet(this->getPosition().x+34,this->getPosition().y,0,1,1));
    else
    {
        int i=30*(rand()%3+1);
        allBullet.push_back(new Bullet(this->getPosition().x+i,this->getPosition().y,0.2,1,1));
        allBullet.push_back(new Bullet(this->getPosition().x+i,this->getPosition().y,-0.2,1,1));
        allBullet.push_back(new Bullet(this->getPosition().x+i,this->getPosition().y,0,1,1));
        if(i==30)
        {
            allBullet.push_back(new Bullet(this->getPosition().x+i,this->getPosition().y,0.4,1,1));
            allBullet.push_back(new Bullet(this->getPosition().x+i,this->getPosition().y,-0.4,1,1));
        }
    }
}

std::vector<Bullet*> Enemy::getBulletVector()
{
    return allBullet;
}

bool Enemy::checkHit(int x1,int y1)
{
    if(this->checkAlive()<=0)return false;
    int myx,myy;
    myx=this->getPosition().x;
    myy=this->getPosition().y;
    if(type==elite)
    {
        if(x1<=myx+69&&
           x1>=myx&&
           y1>=myy&&
           y1<=myy+95)
        {
            this->die();
            if(this->checkAlive()<=0)
                this->crash();
            return true;
        }
    }
    if(type==normal)
    {
        if(x1<=myx+57&&
           x1>=myx&&
           y1>=myy&&
           y1<=myy+43)
        {
            this->die();
            if(this->checkAlive()<=0)
                this->crash();
            return true;
        }
    }
    if(type==boss)
    {
        if(x1<=myx+165&&
           x1>=myx&&
           y1>=myy&&
           y1<=myy+260)
        {
            this->die();
            if(this->checkAlive()<=0)
                this->crash();
            return true;
        }
    }
    return false;
}

void Enemy::crash()
{
    if(type!=boss)crashSound1.play();
    else crashSound2.play();
    this->setTexture(crashTexture1);
}

bool Enemy::canDelete()
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

int Enemy::getType()
{
    return type;
}
