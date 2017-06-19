/*
 * main.cpp
 *
 *  Created on: 2017年6月19日
 *      Author: mark
 */
#include<iostream>
#include"node.h"
#include<vector>
using namespace std ;

vector<node*> node::Tree;
int node::number = 0 ;
int node::sum = 0 ;

int main()
{
	node A(10);
	A.append(20);
	A.append(30);
	A.append(40);
	A.append(50);
	A.append(60);
	A.append(70);
	A.append(80);
	node::append(3,100);
	node::append(9,100);
	cout<<A.Getdata(1)<<endl;
	cout<<node::howmany(3);




	return 0 ;
}



