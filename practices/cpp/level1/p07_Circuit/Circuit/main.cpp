/*
 * main.cpp
 *
 *  Created on: 2017年5月2日
 *      Author: mark
 */
#include<iostream>
#include"device.h"
#include"circuit.h"
using namespace std ;

int main()
{
	Light light1 ;
	Fan fan1 ;
	circuit.add(light1);
	circuit.add(fan1);
	circuit.status();
	circuit.on();
	circuit.status();
	circuit.off();
	circuit.status();
}



