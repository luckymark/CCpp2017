#include <iostream>
#include <cstring>
#include "Classes.h"
using namespace std;

int main()
{
	int a;
	scanf("%d",a);
	while(1)
	{
		
		cout<<"1:showlist\n2:add student\n3:delete student\n4:entering"<<endl;
		if(a==1){
			showList();
		}
		if(a==2){
			addStudent()
		}
		if(a==3){
			deleteStudent();
		};
		if(a==4){
			enteringGrade();
		}
		if(a==5){
			break;
		}
	}
	return 0;
}
