/*
//此程序不太知道怎么编，参考了别人的自己敲了一遍。。。（所有类似的不会编的都会注明） 
#include<stdio.h>

int main(void)
{
	int i;
	for(i=10;i<=120;i++){
		if(i%6==0&&i%12==0&&i%7==0){
			printf("%d",i);
		}
	}
}
*/

//以下为自己写的，好冗杂。 
#include <iostream>
using namespace std;
int main(int argc, char** argv) {

int is_diu_age(int diu_age);
	for(int i=50;i<101;i+=1)
		{
			if( is_diu_age(i) ) {
				cout<<i<<endl;
			}
		}
	return 0;
}

int is_diu_age( int diu_age) 
{	
	int son_age,diu_marry_age,diu_umarry_age,temp;
	son_age=diu_age/2;
	diu_umarry_age=diu_age/7;
	temp = diu_age/6+diu_age/12+son_age+4+5+diu_umarry_age; //Use temp for confirming same volume.
	bool is_divide_exactly = !(diu_age%6 || diu_age%12 || diu_age%2 || diu_age%7);
	if(is_divide_exactly && diu_age== temp ) return 1;  //put is_divide_exactly ahead can accelerate this step.
	else return 0;
}
