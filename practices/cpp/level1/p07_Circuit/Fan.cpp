//
//  Fan.cpp
//  p07_Circuit
//
//  Created by Jimmy Fan on 2017/5/2.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <stdio.h>
#include "Fan.h"

Fan::Fan(int k) {
    this -> k = k;
}

void Fan::on() {
    printf("风扇%d在转\n",k);
}

void Fan::off() {
    printf("风扇%d停了\n",k);
}
