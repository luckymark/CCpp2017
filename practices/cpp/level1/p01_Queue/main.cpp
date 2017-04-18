#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue queue;
    int choice;

    while(1){
    cout<<"what do you want to do?\n" <<"1.append queue\n"<<"2.pop queue\n"<<"3.judge full\n"<<"4.exit"<<endl;
    cout<<"please input your choice:"<<endl;
    cin>>choice;
    if(choice == 1)
    {
        for(int i=0;i<=9;i++){
        int number;
        cin>>number;
        queue.append(number);
        }
    }

    else if(choice == 2)
    {
        queue.pop();
    }

    else if(choice == 3)
    {
        queue.IsFull();
        queue.IsEmpty();
    }

    else if(choice == 4)
    {
        break;
    }

}
    return 0;
}
