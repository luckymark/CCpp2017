#include "Employee.h"
#include<iostream>
using std::cout;
using std::endl;
Employee::Employee(string name,int age,int rank){
	this->name=name;
	this->age=age;
	this->rank=rank;
	salary=this->rank*1000;
}
void Employee::change(string name,int age,int rank){
	this->name=name;
	this->age=age;
	this->rank=rank;
}
void Employee::show(){
	cout<<"Name:"<<name<<endl;
	cout<<"Age:"<<age<<endl;
	cout<<"Rank:"<<rank<<endl;
	cout<<"Salary:"<<salary<<endl;
}
Sale::Sale(string name,int age,int rank,int sales):Employee(name,age,rank){
	this->sales=sales;
	salary=salary+0.2*sales;
}
void Sale::change(string name,int age,int rank){
	this->name=name;
	this->age=age;
	this->rank=rank;
}
void Sale::setSales(int sales){
	this->sales=sales;
	salary=rank*1000+this->sales*0.2;
}
void Sale::show(){
	cout<<"Name:"<<name<<endl;
	cout<<"Age:"<<age<<endl;
	cout<<"Rank:"<<rank<<endl;
	cout<<"Sales:"<<sales<<endl;
	cout<<"Salary:"<<salary<<endl;
}
