#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;
class Student
{
    private:
        int ;
        
}
int menu();
int main()
{
    menu();
}
int menu()
{
    char ch;
    cout<<"1.add new lesson"<<endl<<"2.check student lst"<<endl<<"3.add student"<<endl<<"4.delete student"<<endl<<"5.record score"<<endl<<"6.exit(enter esc)"<<endl;
    while(1)
    {
        printf("Your choose:")
        switch(ch=getch())
        {
            case '1':addlesson();continue;
            case '2':studenglist();continue;
            case '3':addstudent();continue;
            case '4':destudent();continue;
            case '5':score();continue;
            case 27:break;
            default:printf("Please enter a right number");continue;
        }
    }
}