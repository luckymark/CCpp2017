//
//  Enemys.h
//  Fighters
//
//  Created by Jimmy Fan on 2017/5/17.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Enemys_h
#define Enemys_h

#include "Enemy.h"
#define N 20

class Enemys {
private:
    int timeInterval;
    int timee;
public:
    Enemy enemys[N];
    int numOfEnemys;
    Enemys(int = 10,int = 1000);
    void creatEnemy(sf::Time totTime);
    void move(sf::Time time);
    void shoot(sf::Time totTime);
    void reStart();
};

#endif /* Enemys_h */
