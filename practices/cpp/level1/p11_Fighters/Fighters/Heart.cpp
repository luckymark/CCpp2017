//
//  Heart.cpp
//  Fighters
//
//  Created by Jimmy Fan on 2017/5/25.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <cstdio>
#include "Heart.h"
using namespace std;

Heart::Heart() {
    texture.loadFromFile("/Users/fjm/Git/Fighters/Resources/heart.png");
    rect = texture.getSize();
    heart.setTexture(texture);
}

sf::Vector2u Heart::getRect() {
    return rect;
}

