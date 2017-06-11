#include "Device.h"
#include <vector>
#include <cstdio>


Device::Device()
    {
        On=0;
        sum_next=0;
        sum_pre=0;
    }
fan::fan():Device()
    {
        set_name("fan");
    }
light::light()
    {
        set_name("light");
    }
Switch::Switch()
    {
        set_name("switch");
    }

    char* Device::get_name(){
    return name;
    }
    void Device::set_name(char* in_name){
    int len=0;
    for (;;){
            char ch=*in_name;
            name[len++]=ch;
            if (*in_name=='\0')
                break;
            *in_name++;
        }
    }

std::vector<Device *>::iterator Device::get_next_st(){
return next.begin();
}

std::vector<Device *>::iterator Device::get_next_end(){
return next.end();
}

bool Device::get_state(){
return On;
}

int  Device::get_num(){
return number;
}

void Device::set_num(int num){
number=num;
}


void Device::shift(bool On_off){
On=On_off;
//printf("%d  %d\n",number,On);
int tmp;
if (On)
    tmp=1;
else
    tmp=-1;
    for (std::vector<Device *>::iterator I=next.begin();I!=next.end();I++)
    {
        (**I).sum_pre+=tmp;
        //printf("%d  next %d\n",number,(**I).number);
        if ((**I).sum_pre==0)
            if ((**I).On==1)
            {
                (**I).shift(0);
            }
        if (((**I).sum_pre==1)&&(((**I).sum_next>0)))
            if ((**I).On==0)
                (**I).shift(1);
    }
    for (std::vector<Device *>::iterator I=pre.begin();I!=pre.end();I++)
    {

        (**I).sum_next+=tmp;
        if ((**I).sum_next==0)
            if ((**I).On==1)
                (**I).shift(0);
        if (((**I).sum_next==1)&&(((**I).sum_pre>0)))
            if ((**I).On==0)
                (**I).shift(1);
    }
}


void Device::build_next(Device* Next_in){
next.push_back(Next_in);
};


void Device::build_pre(Device* Pre_in){
pre.push_back(Pre_in);
};

