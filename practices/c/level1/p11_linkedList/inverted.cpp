/*
 * inverted.cpp
 *
 *  Created on: 2017年3月23日
 *      Author: mark
 */
#include<iostream>   //quetion? when compile, this document cost memeory?
#include"Nodedefination.h"

using namespace std;

Node* inverted(Node* start,int n)
{

    Node* p = start ;
    Node* address[n];
    int i=0;

    while (p != NULL) {
        address[i] = p ;
        if(p->Next == NULL )break;
        p = p->Next ;
        i++;
    }

    Node* ret = p;
    p = start ;
    Node* temp = NULL;
    int count = 0;

    while(p != NULL){
        temp = p->Next;

        if(address[count] == p ){
            p->Next = NULL ;
        } else {
            p->Next = address[count] ;
            count++;
        }

        p=temp;

    }

    return ret ;
}

