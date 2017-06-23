//
//  Enemy.cpp
//  Fighters
//
//  Created by Jimmy Fan on 2017/5/15.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include "Enemy.h"
using namespace std;
#define PI 3.1415926

Enemy::Enemy() {
    texture.loadFromFile("/Users/fjm/Git/Fighters/Resources/enemy0.png");
    rect = texture.getSize();
    enemyPlane.setTexture(texture);
    speed = 100;
    aliveCondition = 0;
    isShoot = 0;
    key = rand() % 10;
}

void Enemy::move(sf::Time time) {
    enemyPlane.move(sf::Vector2f(0,speed * time.asSeconds()));
    sf::Vector2f pos = enemyPlane.getPosition();
    if (pos.y >= windowHeight) {
        aliveCondition = 0;
        isShoot = 0;
    }
}

void Enemy::down(int k) {
    int t = 3;
    if (k == 4*t + 1) {
        texture.loadFromFile("/Users/fjm/Git/Fighters/Resources/enemy0.png");
        enemyPlane.setTexture(texture);
        rect = texture.getSize();
        aliveCondition = 0;
        isShoot = 0;
        return;
    }
    if (k % t == 1) {
        texture.loadFromFile("/Users/fjm/Git/Fighters/Resources/enemy0_down" + to_string(k/t+1) + ".png");
        enemyPlane.setTexture(texture);
        rect = texture.getSize();
    }
    aliveCondition = k + 1;
}

void Enemy::shoot(sf::Time totTime) {
    if (((totTime.asMilliseconds()) % 5000) / 500 == key && !isShoot) {
        isShoot = 1;
        int alpha = rand() % 60 + 60;
        shot.setDirection(sf::Vector2f(cos((double)alpha*PI / 180.0),-sin((double)alpha*PI /180.0)));
        shot.setSpeed(200);
        shot.setPicture(-1);
        shot.isAlive = 1;
        sf::Vector2f pos = enemyPlane.getPosition();
        shot.shot.setPosition(pos.x + rect.x / 2, pos.y + rect.y / 2);
    }
}
