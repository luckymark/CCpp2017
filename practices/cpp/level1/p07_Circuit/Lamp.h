//
//  Lamp.h
//  p07_Circuit
//
//  Created by Jimmy Fan on 2017/5/2.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Lamp_h
#define Lamp_h

#include "Device.h"

class Lamp:public Device {
private:
    int k;
public:
    Lamp(int k);
    void on();
    void off();
};

#endif /* Lamp_h */
