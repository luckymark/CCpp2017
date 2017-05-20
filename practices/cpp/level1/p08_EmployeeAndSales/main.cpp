/*to do list
1.Class Employee
	name,age,rank
	salary
	show
2.Class Sale(is-a-Employee)
	set sales
	salary
	show
*/
#include<iostream>
#include "Employee.h"
int main(){
	Employee person1("WXZ",19,1);
	Sale person2("God Du",18,10);
	person2.setSales(10000);
	person2.change("Du",18,20);
	
	person1.show();
	person2.show();
	
	return 0;
}
