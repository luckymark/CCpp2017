#include "Array.h"
#include<iostream>
using std::cout;
Array::Array(int item){
	int *p=new int[item];
	
	max=item;
	data=p;
	for(int i=0;i<max;i++){
		data[i]=0;
	}
}
int & Array::operator[](int n){
	if(n>=max||n<=0){
		cout<<"Error,we will use No."<<n%max<<"\n";
		
		return data[n%max];
	}
	
	return data[n];
}
void Array::disp(){
	for(int i=0;i<max;i++){
		cout<<data[i]<<'\t';
	} 
	cout<<'\n';
} 
