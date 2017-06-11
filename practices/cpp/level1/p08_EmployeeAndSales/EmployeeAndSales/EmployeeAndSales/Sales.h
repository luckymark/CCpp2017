#ifndef SALES_H
#define SALES_H
#include "Employee.h"
    //2. 实现一个销售员类：
	//3. 记录sales的销售额
	//4. 计算工资时需要在级别工资基础上，加上销售提成（按20%核算）
class Sales: public Employee{
private:
    int sales_num;
public:
    void set_sales(int in_sales);
    double get_salary();
};

#endif // SALES_H
