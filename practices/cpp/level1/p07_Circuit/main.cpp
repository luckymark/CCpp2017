//
//  main.cpp
//  p07_Circuit
//
//  Created by Jimmy Fan on 2017/5/2.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <iostream>
#include "Circuit.h"
#include "Lamp.h"
#include "Fan.h"

int main(int argc, const char * argv[]) {
    Circuit myCircuit;
    bool flag = 1;
    while (flag) {
        printf("请输入所需操作编号:\n 1:添加灯泡\n 2:添加风扇\n 3:开关开\n 4:开关关\n 0:退出程序\n");
        int k;
        scanf("%d",&k);
        switch (k) {
            case 0:
                flag = 0;
                break;
            case 1: {
                Lamp lamp(myCircuit.getNum());
                myCircuit.addDevice(&lamp);
                break;
            }
            case 2: {
                Fan fan(myCircuit.getNum());
                myCircuit.addDevice(&fan);
                break;
            }
            case 3:
                myCircuit.on();
                break;
            case 4:
                myCircuit.off();
                break;
        }
    }
    return 0;
}
