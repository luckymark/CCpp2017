#define MONERYPERGRADE 1000
#define COMISSION 0.2
#include<iostream>
#include<string>
using namespace std ; 
class employer
{
private:    
    string name ;
    int age ;
    int grade ;
    int slary;
public:
    employer(string name , int age , int grade ):name(name),age(age),grade(grade){          
        slary = 0;
    }
    
    employer(char* name , int age , int grade):name(name),age(age),grade(grade){
        slary = 0;
    }
        

    virtual int evalueslary(){
        slary = grade * MONERYPERGRADE ;
        return slary ;
    }

    void setage(int m)
    {
        age = m ;
    }

    int getage(){
        return age;
    }

    void setgrade(int m){
        grade = m ;
    }

    int getgrade()
    {
        return grade ;
    }


    void setslary(int m){
        slary = m ;
    }

    int getslary()
    {
        return slary ;
    }
    virtual ~employer(){
    }
};


class Saleman : public employer
{
private:
    int Samleamout ;
public:
    Saleman(string name , int age , int grade, int Samleamout=0):employer(name,age,grade),Samleamout(Samleamout){}
    Saleman(char * name , int age , int grade , int Samleamout=0):employer(name,age,grade),Samleamout(Samleamout){}

    void set(int m )
    {
        Samleamout = m ;
    }

    virtual int evalueslary(){
        int tem = getgrade() * MONERYPERGRADE + Samleamout * COMISSION ;
        setslary(tem);
        return tem ;
    }

    virtual ~Saleman(){
    }


};
