#ifndef DEVICE_H
#define DEVICE_H
#include <vector>

class Device{
private:
    bool On;
    int sum_next;
    int sum_pre;
    int number;
    char name[10];
    std::vector<Device*> next;
    std::vector<Device*> pre;
public:
    Device();

    char* get_name();

    void set_name(char* in_name);

    std::vector<Device *>::iterator get_next_st();

    std::vector<Device *>::iterator get_next_end();

    bool get_state();

    int  get_num();

    void set_num(int num);

    void shift(bool On_off);

    void build_next(Device* Next_in);

    void build_pre(Device* Pre_in);

};

class fan:Device{
public:

    fan();

};

class light:Device{
public:
    light();
};

class Switch:Device{
public:
    Switch();
};


#endif // CIRCUIT_H
