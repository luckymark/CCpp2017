//
//  Reward.h
//  Fighters
//
//  Created by Jimmy Fan on 2017/6/12.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Reward_h
#define Reward_h

#include "Sprite.h"

class Reward: public Sprite {
private:
    int kind;
public:
    Reward();
    bool alive;
    void move(sf::Time time);
    void setKind();
    int getKind();
    sf::Sprite reward;
};


#endif /* Reward_h */
