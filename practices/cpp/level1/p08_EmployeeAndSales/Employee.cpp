//
//  Employee.cpp
//  p08_EmployeeAndSales
//
//  Created by Jimmy Fan on 2017/6/23.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <cstdio>
#include "Employee.h"
using namespace std;

Employee::Employee(char *name, int age, int level) {
    this -> name = name;
    this -> age = age;
    this -> level = level;
}

int Employee::getSalary() {
    return 1000 * level;
}
