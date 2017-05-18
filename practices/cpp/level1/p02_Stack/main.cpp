#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack stack;



    while(1){
    cout<<"what do you want to do?\n" <<"1.append stack\n"<<"2.pop stack\n"<<"3.judge full\n"<<"4.exit"<<endl;
    cout<<"please input your choice:"<<endl;
    int choice;
    cin>>choice;
    if(choice == 1)
    {
        for(int i=0;i<=9;i++){
        int number;
        cin>>number;
        stack.append(number);
        }
    }

    else if(choice == 2)
    {
        stack.pop();
    }

    else if(choice == 3)
    {
        stack.IsFull();
        stack.IsEmpty();
    }

    else if(choice == 4)
    {
        break;
    }

}
    return 0;
}
