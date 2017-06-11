#include "Device.h"
#include "Circuit.h"
#include <cstdio>


void T(Device A){
Device B;
}

    Circuit::Circuit(){
        //st.set_num(1);
        //ed.set_num(2);
        total=0;
        build(&st,&ed);
        st.shift(1);
        //puts("=================");
        ed.shift(1);
    }

    Device Circuit::get_st()
    {
        return st;
    };
    void Circuit::build(Device *A,Device *B){
        (*A).build_next(B);
        (*B).build_pre(A);
    }
    void Circuit::creat(Device A,int op)//op=1 fan op=2 light  op=3 switch
    {
        build(&A,&device[++total]);
        if (op==1)
        {
            //puts("aaaaaaaaa");
            device[total].set_name("fan");
        }
        if (op==2)
            device[total].set_name("light");
        if (op==3)
            device[total].set_name("switch");
    }
    void Circuit::creat(int pre,int op){
        if (pre==0)
            creat(st,op);
        else
            creat(device[pre],op);
    }
    void Circuit::Shift(int x,bool On_off){
        device[x].shift(On_off);
    }

    Device Circuit::get_device(int num){
        return device[num];
    }

    int Circuit::get_total(){
        return total;
    }
    void Circuit::show(){
        printf("total=%d\n",total);
        for (int i=1;i<=total;i++)
            {
                printf("NO.%d %s ",i,device[i].get_name());
                if (device[i].get_state())
                    printf("is running\n");
                else
                    printf("is off\n");
                for (std::vector<Device*>::iterator I=device[i].get_next_st();I!=device[i].get_next_end();I++)
                    printf("%d---->%d\n",i,(**I).get_num());
            }
    }


