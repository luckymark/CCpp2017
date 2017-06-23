//
//  Background.cpp
//  Fighters
//
//  Created by Jimmy Fan on 2017/6/12.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <cstdio>
#include <cmath>
#include "Background.h"
using namespace std;
#define EPS 1e-5

Background::Background() {
    texture.loadFromFile("/Users/fjm/Git/Fighters/Resources/background.png");
    rect = texture.getSize();
    background[0].setTexture(texture);
    background[1].setTexture(texture);
    background[0].setPosition(0, 0);
    background[1].setPosition(0, rect.y);
    t = 1;
    speed = -40;
}

void Background::move(sf::Time time) {
    background[0].move(0, speed * time.asSeconds());
    background[1].move(0, speed * time.asSeconds());
    sf::Vector2f pos = background[t].getPosition();
    if (pos.y <= 0) {
        t = (t+1) & 1;
        background[t].setPosition(0, rect.y + pos.y);
    }
}
