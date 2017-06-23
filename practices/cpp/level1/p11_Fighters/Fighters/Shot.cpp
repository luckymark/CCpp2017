//
//  Shot.cpp
//  Fighters
//
//  Created by Jimmy Fan on 2017/5/16.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include "Shot.h"

Shot::Shot(sf::Vector2f direction) {
    this -> direction = direction;
    speed = 100;
    isAlive = 0;
}

void Shot::move(sf::Time time) {
    sf::Vector2f pos = shot.getPosition();
    if (pos.y < 0 || pos.y > windowHeight || pos.x < 0 || pos.x > windowWidth) isAlive = 0;
    else shot.move(sf::Vector2f(direction.x  * speed * time.asSeconds(), -direction.y * speed * time.asSeconds()));
}

void Shot::setDirection(sf::Vector2f direction) {
    this -> direction = direction;
}

void Shot::setSpeed(int speed) {
    this -> speed = speed;
}

void Shot::setPicture(int k) {
    if (k == 1) {
        texture.loadFromFile("/Users/fjm/Git/Fighters/Resources/bullet.png");
        rect = texture.getSize();
        shot.setTexture(texture);
    }
    if (k == -1) {
        texture.loadFromFile("/Users/fjm/Git/Fighters/Resources/bullet1.png");
        rect = texture.getSize();
        shot.setTexture(texture);
    }
}
