//
//  Circuit.cpp
//  p07_Circuit
//
//  Created by Jimmy Fan on 2017/6/23.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <cstdio>
#include "Circuit.h"

Circuit::Circuit() {
    k = 0;
}

void Circuit::addDevice(Device *device) {
    devices[k++] = device;
}

void Circuit::on() {
    for (int i = 0; i < k; i++) {
        devices[i] -> on();
    }
}

void Circuit::off() {
    for (int i = 0; i < k; i++) {
        devices[i] -> off();
    }
}

int Circuit::getNum() {
    return k;
}
