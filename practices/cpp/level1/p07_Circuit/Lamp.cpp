//
//  Lamp.cpp
//  p07_Circuit
//
//  Created by Jimmy Fan on 2017/5/2.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <cstdio>
#include "Lamp.h"

Lamp::Lamp(int k) {
    this -> k = k;
}

void Lamp::on() {
    printf("灯泡%d亮了\n",k);
}

void Lamp::off() {
    printf("灯泡%d灭了\n",k);
}
