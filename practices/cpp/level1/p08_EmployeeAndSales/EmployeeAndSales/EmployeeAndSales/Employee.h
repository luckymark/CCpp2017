#ifndef EMPLOYEE_H
#define EMPLOYEE_H


//1. ʵ��һ����Ա�ࣺ
//	2. ��¼Ա�������������䡢���������
//	3. �ɼ���Ա���Ĺ��ʣ���ÿ������1000Ԫ���㣩
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
