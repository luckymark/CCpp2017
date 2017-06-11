#ifndef EMPLOYEE_H
#define EMPLOYEE_H


//1. 实现一个雇员类：
//	2. 记录员工的姓名、年龄、级别等属性
//	3. 可计算员工的工资（按每个级别1000元计算）
class Employee{
private:
    int age;
    int level;
    char name[20];
    char phone[14];
    char adress[30];
public:
    int get_salary();

    void set_age(int in_age);

    void set_level(int in_level);

    void set_name(char* in_name);

    void set_phone(char* in_phone);

    void set_adress(char* in_adress);

    int get_age();

    int get_level();

    char* get_name();

    char* get_phone();

    char* get_adress();
};



#endif // EMPLOYEE_H
