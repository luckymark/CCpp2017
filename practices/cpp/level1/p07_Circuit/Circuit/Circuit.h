#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "Device.h"
#include <cstdio>

void T(Device A);


class Circuit{
private:
    Device st,ed;
    int total;
    Device device[1000];
public:
    Circuit();
    Device get_st();
    void build(Device *A,Device *B);
    void creat(Device A,int op);
    void creat(int pre,int op);
    void Shift(int x,bool On_off);
    Device get_device(int number);
    int get_total();
    void show();
};


#endif // CIRCUIT_H
