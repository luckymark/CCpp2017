//
//  Boss.h
//  Fighters
//
//  Created by Jimmy Fan on 2017/6/6.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Boss_h
#define Boss_h

#include "Sprite.h"
#include "Shot.h"
#include "Player.h"
#define timeInterval 1000
#define numOfBossShots 10

class Boss: public Sprite {
private:
    bool stay;
    int direction;
    int timee;
public:
    bool WIN;
    int HP;
    bool bossTime;
    bool bossComing;
    int aliveCondition;
    Shot shots[10];
    Boss();
    sf::Sprite Plane;
    void move(sf::Time time);
    void shoot(sf::Time time, Player player);
    void down(int k);
    void reStart();
};


#endif /* Boss_h */
