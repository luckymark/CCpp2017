//
//  Circuit.h
//  p07_Circuit
//
//  Created by Jimmy Fan on 2017/5/2.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Circuit_h
#define Circuit_h

#include "Device.h"
#define N 100

class Circuit {
private:
    Device* devices[N];
    int k;
public:
    Circuit();
    void addDevice(Device* device);
    void on();
    void off();
    int getNum();
};


#endif /* Circuit_h */
