
/*
 * CreateNode.cpp

 *
 *  Created on: 2017年3月22日
 *      Author: mark
 */
#include<iostream>
#include "Nodedefination.h"

using namespace std;



Node* CreateNode(int a )
{
            Node *p = new Node ;
            Node *retpoint=p;

            cout<<"please input the value."<<endl;

            int temp ;
            cin>>temp;

            p->Data = temp ;

            if( a == 1 )return p;

            int j = a - 1 ;

            for( int i = 0 ; i < j ; i++  ){
                Node *q = new Node ;

                cout<<"please input the value."<<endl;

                int temp ;
                cin>>temp;

                q->Data = temp ;
                p->Next=q;

                p = q ;
            }

            p->Next = NULL ;

            return retpoint ;
}





