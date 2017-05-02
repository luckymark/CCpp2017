#ifndef CL_CURCUIT_H
#define CL_CURCUIT_H

using namespace std;


class Device
{
public:
    virtual void turn_on();
    virtual void turn_off();
    virtual void power_on();
    virtual void power_off();
    virtual void check();
};


class Lamp: public Device
{
private:
    bool on;
    bool power;
protected:
    void power_on()
    {
        power=1;
    }
    void power_off()
    {
        power=0;
    }
public:
    Lamp()
    {
        on=0;
        power=0;
    }
    void turn_on()
    {
        on=1;
    }
    void turn_off()
    {
        on=0;
    }
    void check()
    {
        cout<<"a lamp: ";
        if(on==1 and power==1) cout<<"on";
        else cout<<"off";
        cout<<endl;
    }
};


class Fan: public Device
{
private:
    bool on;
    bool power;
protected:
    void power_on()
    {
        power=1;
    }
    void power_off()
    {
        power=0;
    }
public:
    Fan()
    {
        on=0;
        power=0;
    }
    void turn_on()
    {
        on=1;
    }
    void turn_off()
    {
        on=0;
    }
    void check()
    {
        cout<<"a fan: ";
        if(on==1 and power==1) cout<<"on";
        else cout<<"off";
        cout<<endl;
    }
};


class Circuit
{
private:
    int count;
    Device* devices[5];
public:
    Circuit()
    {
        count=0;
    }
    void power_on()
    {
        for(int i=0;i<count;i++)
        {
            devices[i]->power_on();
        }
    }
    void power_off()
    {
        for(int i=0;i<count;i++)
        {
            devices[i]->power_off();
        }
    }
    void add(Device* new_device)
    {
        if(count>=4)
        {
            cout<<"full"<<endl;
            return;
        }
        devices[count++]=new_device;
    }
    void state()
    {
        for(int i=0;i<count;i++)
            devices[i]->check();
    }
};



#endif //CL_CURCUIT_H
