//
//  Reward.cpp
//  Fighters
//
//  Created by Jimmy Fan on 2017/6/12.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include "Reward.h"
using namespace std;

Reward::Reward() {
    speed = 200;
    alive = 0;
}

void Reward::move(sf::Time time) {
    reward.move(0, speed * time.asSeconds());
    sf::Vector2f pos = reward.getPosition();
    if (pos.y >= windowHeight) {
        alive = 0;
    }
}

void Reward::setKind() {
    kind = rand() % 3;
    if (kind == 0) texture.loadFromFile("/Users/fjm/Git/Fighters/Resources/reward_damage.png");
    if (kind == 1) texture.loadFromFile("/Users/fjm/Git/Fighters/Resources/reward_life.png");
    if (kind == 2) texture.loadFromFile("/Users/fjm/Git/Fighters/Resources/reward_speed.png");
    rect = texture.getSize();
    reward.setTexture(texture);
    int x = rand() % (windowWidth - rect.x);
    reward.setPosition(x, 0);
    alive = 1;
}

int Reward::getKind() {
    return kind;
}
