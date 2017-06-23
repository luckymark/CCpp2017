//
//  Fan.h
//  p07_Circuit
//
//  Created by Jimmy Fan on 2017/5/2.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Fan_h
#define Fan_h

#include "Device.h"

class Fan:public Device {
private:
    int k;
public:
    Fan(int k);
    void on();
    void off();
};

#endif /* Fan_h */
