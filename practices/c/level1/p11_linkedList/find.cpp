/*
 * find.cpp
 *
 *  Created on: 2017年3月24日
 *      Author: mark
 */
#include<iostream>
#include"Nodedefination.h"
using namespace std;

int find(Node* p , int n)
{
    int  count = 1 ;
    int flag = 0 ;

    while(p != NULL ){
        if(p->Data==5){
            cout<<count<<endl;
            flag = 1 ;
        }
        p = p->Next;
        count++ ;
    }

    if(flag == 0) return -1 ;

    return 0;

}



