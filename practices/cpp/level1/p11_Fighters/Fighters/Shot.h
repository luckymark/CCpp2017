//
//  Shot.h
//  Fighters
//
//  Created by Jimmy Fan on 2017/5/16.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Shot_h
#define Shot_h

#include "Sprite.h"

class Shot: public Sprite {
private:
    sf::Vector2f direction;
public:
    sf::Sprite shot;
    Shot(sf::Vector2f = sf::Vector2f(0.0,1.0));
    void move(sf::Time time);
    bool isAlive;
    void setDirection(sf::Vector2f direction);
    void setSpeed(int speed);
    void setPicture(int k);
};

#endif /* Shot_h */
