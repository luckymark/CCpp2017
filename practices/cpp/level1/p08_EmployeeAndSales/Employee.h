//
//  Employee.h
//  p08_EmployeeAndSales
//
//  Created by Jimmy Fan on 2017/6/23.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Employee_h
#define Employee_h

class Employee {
private:
    char *name;
    int age;
    int level;
public:
    Employee(char *name, int age, int level);
    int getSalary();
};


#endif /* Employee_h */
