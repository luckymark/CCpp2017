#include"hero.h"


class Enemy:public Entity
{
public:
    Enemy(int type);//type设置敌机种类
    void moveNode(sf::Time deltaTime);
    void fire();
    std::vector<Bullet*> getBulletVector();
    bool checkHit(int x1,int y1);
    void crash();
    bool canDelete();
    int getType();
private:
    std::vector<Bullet*>allBullet;
    sf::Texture crashTexture1;
    sf::Texture crashTexture2;
    sf::Texture crashTexture3;
    int type;
    int deleteTimer;
    bool bossMoveLeft;
    sf::Music crashSound1,crashSound2;
};
