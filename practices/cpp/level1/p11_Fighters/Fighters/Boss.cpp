
//
//  Boss.cpp
//  Fighters
//
//  Created by Jimmy Fan on 2017/6/6.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include "Boss.h"
#include <cstring>
#include <cmath>
using namespace std;

Boss::Boss() {
    texture.loadFromFile("/Users/fjm/Git/Fighters/Resources/boss.png");
    rect = texture.getSize();
    Plane.setTexture(texture);
    Plane.setPosition((windowWidth - rect.x)/2, 0);
    speed = 150;
    HP = 30;
    aliveCondition = 1;
    stay = 0;
    bossTime = 0;
    bossComing = 0;
    WIN = 0;
    direction = 1;
    timee = 1;
    for (int i = 0; i < numOfBossShots; i++) shots[i].isAlive = 0;
}

void Boss::reStart() {
    texture.loadFromFile("/Users/fjm/Git/Fighters/Resources/boss.png");
    rect = texture.getSize();
    Plane.setTexture(texture);
    Plane.setPosition((windowWidth - rect.x)/2, 0);
    HP = 40;
    aliveCondition = 1;
    stay = 0;
    WIN = 0;
    bossTime = 0;
    bossComing = 0;
    direction = 1;
    timee = 1;
    for (int i = 0; i < numOfBossShots; i++) shots[i].isAlive = 0;
}

void Boss::move(sf::Time time) {
    for (int i = 0; i < numOfBossShots; i++) {
        if (shots[i].isAlive) {
            shots[i].move(time);
        }
    }
    if (aliveCondition && aliveCondition != 1) {
        down(aliveCondition);
        return;
    }
    if (HP < 10) {
        texture.loadFromFile("/Users/fjm/Git/Fighters/Resources/boss_hit.png");
        rect = texture.getSize();
        Plane.setTexture(texture);
    }
    sf::Vector2f pos = Plane.getPosition();
    if (!stay) {
        int yNow = pos.y + rect.y;
        int dy = speed * time.asSeconds();
        if (yNow + dy > 300) {
            dy = 300 - yNow;
            stay = 1;
        }
        Plane.move(sf::Vector2f(0, dy));
    }
    else {
        int xNow = pos.x + rect.x;
        int dx = speed * time.asSeconds() * direction;
        if (xNow + dx >= windowWidth) {
            dx = windowWidth - xNow;
            direction = -direction;
        }
        else if (pos.x + dx <= 0) {
            dx = -pos.x;
            direction = -direction;
        }
        Plane.move(sf::Vector2f(dx,0));
    }
}

void Boss::shoot(sf::Time time, Player player) {
    if (time.asMilliseconds() > timeInterval * timee) {
        timee ++;
        for (int i = 0; i < numOfBossShots; i++) {
            if (!shots[i].isAlive) {
                sf::Vector2f posBoss = Plane.getPosition();
                sf::Vector2f posPlane = player.Plane.getPosition();
                int dx = (posPlane.x + player.rect.x / 2) - (posBoss.x + rect.x / 2);
                int dy = (posPlane.y + player.rect.y / 2) - (posBoss.y + rect.y);
                int dxy = sqrt(dx*dx + dy*dy);
                shots[i].setSpeed(200);
                shots[i].setDirection(sf::Vector2f((double)dx/(double)dxy, -(double)dy/(double)dxy));
                shots[i].setPicture(-1);
                shots[i].isAlive = 1;
                shots[i].shot.setPosition(posBoss.x + rect.x / 2, posBoss.y + rect.y);
                break;
            }
        }
    }
}


void Boss::down(int k) {
    int t = 7;
    if (k == 6*t + 15) {
        bossTime = 0;
        bossComing = 0;
        WIN = 1;
        return;
    }
    if (k % t == 1 && k/t < 6) {
        texture.loadFromFile("/Users/fjm/Git/Fighters/Resources/boss_down" + to_string(k/t+1) + ".png");
        Plane.setTexture(texture);
        rect = texture.getSize();
    }
    aliveCondition = k + 1;
}
