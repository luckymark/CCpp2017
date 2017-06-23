//
//  Enemy.h
//  Fighters
//
//  Created by Jimmy Fan on 2017/5/15.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Enemy_h
#define Enemy_h

#include "Sprite.h"
#include "Shot.h"
#include <SFML/Audio.hpp>

class Enemy: public Sprite {
private:
    bool isShoot;
    int key;
public:
    int HP;
    sf::Sprite enemyPlane;
    Enemy();
    void move(sf::Time time);
    int aliveCondition;
    void down(int k);
    void shoot(sf::Time totTime);
    Shot shot;
};

#endif /* Enemy_h */
