#include <iostream>
#include "Queue.h"
using namespace std;

int main(int argc, char** argv)
{
	Queue Q;
    for(int i = 1; i <= 100; i++) Q.append(i);
    cout<<Q.isFull()<<endl;
    for(int i = 1; i <= 100; i++) Q.pop();
    cout<<Q.isEmpty()<<endl;
	return 0;
}
