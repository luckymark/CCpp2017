//
//  Gun.h
//  Fighters
//
//  Created by luckymark on 13-10-26.
//  Copyright (c) 2013年 luckymark. All rights reserved.
//

#ifndef __Fighters__Gun__
#define __Fighters__Gun__

#include <iostream>

#include <SFML/Graphics.hpp>

class Plane;

class Gun{
public:
    void setOwner(Plane * owner);
    void fire();
private:
    sf::Vector2f getPosition();
    
    Plane* owner;
};

#endif /* defined(__Fighters__Gun__) */
