//
//  Salesman.h
//  p08_EmployeeAndSales
//
//  Created by Jimmy Fan on 2017/6/23.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Salesman_h
#define Salesman_h

#include "Employee.h"

class Salesman: public Employee {
private:
    int sales;
public:
    Salesman(char *name, int age, int level, int sales);
    int getSalary();
};

#endif /* Salesman_h */
