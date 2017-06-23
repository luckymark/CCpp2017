//
//  Salesman.cpp
//  p08_EmployeeAndSales
//
//  Created by Jimmy Fan on 2017/6/23.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <cstdio>
#include "Salesman.h"
using namespace std;

Salesman::Salesman(char *name, int age, int level, int sales): Employee(name, age, level) {
    this -> sales = sales;
}

int Salesman::getSalary() {
    int salary = Employee::getSalary();
    salary += sales * 2 / 10;
    return salary;
}
