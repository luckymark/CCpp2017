
#include <iostream>
#include "employee.h"
#include "sales.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

    Employee woman("Alice", 1);
    char* name = woman.getName();
    int salary = woman.gatSalary();
    cout << name << endl;
    cout << salary << endl;

    Sales sale("Bob", 2);
    name = sale.getName();
    sale.setSaleCount(2000);
    salary = sale.calcSalary();
    cout << name << endl;
    cout << salary << endl;
    return 0;
}

