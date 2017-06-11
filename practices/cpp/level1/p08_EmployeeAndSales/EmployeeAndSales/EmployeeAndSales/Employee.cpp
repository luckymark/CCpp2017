#include "Employee.h"
//#include <cstdio>


    int Employee::get_salary(){
        return level*1000;
    }

    void Employee::set_age(int in_age){
        age=in_age;
    }

    void Employee::set_level(int in_level){
        level=in_level;
    }

    void Employee::set_name(char* in_name){
        int len=0;
        for (;;)
        {
            char ch=*in_name;
            name[len++]=ch;
            if  (ch=='\0')
                break;
            in_name++;
        }
    }


    void Employee::set_phone(char* in_phone){
        int len=0;
        for (;;)
        {
            char ch=*in_phone;
            phone[len++]=ch;
            if  (ch=='\0')
                break;
            in_phone++;
        }
    }

    void Employee::set_adress(char* in_adress){
        int len=0;
        for (;;)
        {
            char ch=*in_adress;
            adress[len++]=ch;
            if  (ch=='\0')
                break;
            in_adress++;
        }
    }

    int Employee::get_age(){
        return age;
    }

    int Employee::get_level(){
        return level;
    }

    char* Employee::get_name(){
        return name;
    }

    char* Employee::get_phone(){
        return phone;
    }

    char* Employee::get_adress(){
        return adress;
    }
