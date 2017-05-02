#include "Circuit.h"
#include<iostream>
using std::cout;
Circuit::Circuit(){
	condition=0;
	index=0;
}
void Circuit::add(Device * item){
	if(index<10){
		device[index]=item;
		index++;
	}
	
}
void Circuit::on(){
	condition=1;
	for(int i=0;i<index;i++){
		device[i]->on();
	}
	
}
void Circuit::off(){
	condition=0;
	for(int i=0;i<index;i++){
		device[i]->off();
	}
}
void Circuit::disp(){
	if(condition){
		cout<<"The circuit is on\n";
	}
	else{
		cout<<"The circuit is off\n";
	}
	for(int i=0;i<index;i++){
		device[i]->show();
	}
}
