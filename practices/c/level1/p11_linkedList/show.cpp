/*
 * show.cpp

 *
 *  Created on: 2017年3月23日
 *      Author: mark
 */

#include<iostream>
#include"Nodedefination.h"
using namespace std;

void show( Node* start )
{
    while(start  != NULL){
        cout<<"the value is "<<start->Data<<endl;

        start=start->Next;
    }
}



