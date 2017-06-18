//
//  Enemys.cpp
//  Fighters
//
//  Created by Jimmy Fan on 2017/5/17.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "Enemys.h"
using namespace std;

Enemys::Enemys(int numOfEnemys, int timeInterval) {
    this -> numOfEnemys = numOfEnemys;
    this -> timeInterval = timeInterval;
    srand((unsigned)time(NULL));
    timee = 0;
}

void Enemys::reStart() {
    for (int i = 0; i < numOfEnemys; i++) {
        enemys[i].aliveCondition = 0;
        enemys[i].shot.isAlive = 0;
    }
    timee = 0;
}

void Enemys::creatEnemy(sf::Time totTime) {
    if (totTime.asMilliseconds() > timeInterval * timee) {
        timee ++;
        for (int i = 0; i < numOfEnemys; i++) {
            if (!enemys[i].aliveCondition) {
                enemys[i].aliveCondition = 1;
                enemys[i].HP = 2;
                int x = rand() % (windowWidth - enemys[i].rect.x);
                enemys[i].enemyPlane.setPosition(x, 0);
                break;
            }
        }
    }
}

void Enemys::move(sf::Time time) {
    for (int i = 0; i < numOfEnemys; i++) {
        if (enemys[i].aliveCondition == 1) {
            enemys[i].move(time);
        }
        if (enemys[i].aliveCondition && enemys[i].aliveCondition != 1) {
            enemys[i].down(enemys[i].aliveCondition);
        }
    }
    for (int i = 0; i < numOfEnemys; i++) {
        if (enemys[i].shot.isAlive) {
            enemys[i].shot.move(time);
        }
    }
}

void Enemys::shoot(sf::Time totTime) {
    for (int i = 0; i < numOfEnemys; i++) {
        if (enemys[i].aliveCondition == 1) {
            enemys[i].shoot(totTime);
        }
    }
}
