#ifndef SALES_H
#define SALES_H
#include "Employee.h"
    //2. ʵ��һ������Ա�ࣺ
	//3. ��¼sales�����۶�
	//4. ���㹤��ʱ��Ҫ�ڼ����ʻ����ϣ�����������ɣ���20%���㣩
class Sales: public Employee{
private:
    int sales_num;
public:
    void set_sales(int in_sales);
    double get_salary();
};

#endif // SALES_H
