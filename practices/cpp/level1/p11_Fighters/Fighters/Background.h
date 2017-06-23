//
//  Background.h
//  Fighters
//
//  Created by Jimmy Fan on 2017/6/12.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Background_h
#define Background_h

#include "Sprite.h"

class Background: public Sprite {
private:
    int t;
public:
    sf::Sprite background[2];
    Background();
    void move(sf::Time time);
};

#endif /* Background_h */
