/*
 * main.cpp
 *
 *  Created on: 2017年3月22日
 *      Author: mark
 */
#include<iostream>
#include"Nodedefination.h"
#include"All_declaretion.h"
using namespace std ;

int main()
{
	int NodeNumber ;

	cout<<"How many numbers do you want?"<<endl;

	cin>>NodeNumber;

	Node* p;

	p = CreateNode(NodeNumber);

	show ( p ) ;

	p=inverted(p,NodeNumber);

	show( p );

	cout<<"END"<<endl;
}





