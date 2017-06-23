//
//  Player.cpp
//  Fighters
//
//  Created by Jimmy Fan on 2017/5/15.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <cstdio>
#include "Player.h"
using namespace std;

Player::Player() {
    texture.loadFromFile("/Users/fjm/Git/Fighters/Resources/plane.png");
    rect = texture.getSize();
    Plane.setTexture(texture);
    Plane.setPosition((windowWidth - rect.x)/2, windowHeight - rect.y - 10);
    speed = 200;
    damage = 1;
    aliveCondition = 1;
    moveUp = 0;
    moveRight = 0;
    moveLeft = 0;
    moveDown = 0;
    life = 3;
    GameOver = 0;
    shotBuffer.loadFromFile("/Users/fjm/Git/Fighters/Resources/bullet.wav");
    shotSound.setBuffer(shotBuffer);
    for (int i = 0; i < numOfShots; i++) shots[i].setSpeed(150);
    inviolable = 0;
}

void Player::reStart() {
    Plane.setPosition((windowWidth - rect.x)/2, windowHeight - rect.y - 10);
    aliveCondition = 1;
    moveUp = 0;
    moveRight = 0;
    moveLeft = 0;
    moveDown = 0;
    life = 3;
    speed = 200;
    damage = 1;
    GameOver = 0;
    for (int i = 0; i < numOfShots; i++) shots[i].isAlive = 0;
    inviolable = 0;
}

void Player::setMove(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::Up) {
        moveUp = isPressed;
    }
    if (key == sf::Keyboard::Down) {
        moveDown = isPressed;
    }
    if (key == sf::Keyboard::Left) {
        moveLeft = isPressed;
    }
    if (key == sf::Keyboard::Right) {
        moveRight = isPressed;
    }
}

void Player::move(sf::Time time) {
    for (int i = 0; i < numOfShots; i++) {
        if (shots[i].isAlive) {
            shots[i].move(time);
        }
    }
    if (!aliveCondition) {
        life --;
        if (life) {
            Plane.setPosition((windowWidth - rect.x)/2, windowHeight - rect.y - 10);
            aliveCondition = 1;
            inviolable = 120;
            return;
        }
        else {
            GameOver = 1;
            return;
        }
    }
    if (aliveCondition != 1) {
        down(aliveCondition);
        return;
    }
    sf::Vector2f movement(0,0);
    sf::Vector2f pos = Plane.getPosition();
    if (!(moveUp && moveDown)) {
        if (moveUp && pos.y >= 0) {
            movement.y -= speed;
        }
        if (moveDown && pos.y <= windowHeight - rect.y) {
            movement.y += speed;
        }
    }
    if (!(moveLeft && moveRight)) {
        if (moveLeft && pos.x >= 0) {
            movement.x -= speed;
        }
        if (moveRight && pos.x <= windowWidth - rect.x) {
            movement.x += speed;
        }
    }
    Plane.move(movement * time.asSeconds());
}

void Player::shoot(bool isPressed) {
    if (!isPressed) return;
    shotSound.play();
    if (aliveCondition != 1) return;
    sf::Vector2f pos = Plane.getPosition();
    for (int i = 0; i < numOfShots; i++) {
        if (!shots[i].isAlive) {
            shots[i].isAlive = 1;
            shots[i].setPicture(1);
            shots[i].shot.setPosition(pos.x + rect.x / 2 - shots[i].rect.x / 2, pos.y - 50);
            break;
        }
    }
}


void Player::down(int k) {
    int t = 3;
    if (k == 4*t + 1) {
        texture.loadFromFile("/Users/fjm/Git/Fighters/Resources/plane.png");
        Plane.setTexture(texture);
        rect = texture.getSize();
        aliveCondition = 0;
        return;
    }
    if (k % t == 1) {
        texture.loadFromFile("/Users/fjm/Git/Fighters/Resources/plane_down" + to_string(k/t+1) + ".png");
        Plane.setTexture(texture);
        rect = texture.getSize();
    }
    aliveCondition = k + 1;
}


