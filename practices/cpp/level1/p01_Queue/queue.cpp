#include<iostream>
#include<cstdio>
using namespace std;
class queue
{
    private:
        int p[100];
        int temp;
        static int number;
    public:
        void append()
        {
            if(check())
            {
                int q;
                cout<<"What's you want to add\n"<<endl;
                cin>>q;
                this->p[number]=q;
                number++;
            }
       }
        void pop()
        {
            for(int i=0;i<number-1;i++)
            {
                this->p[i]=0;
                this->p[i]=p[i+1];
            }
            p[number-1]=0;
            if(number>=1)number--;
        }
        int check()
        {
            if(number==0)return printf("This queue is empty");
            else if(number==100)
            {
                return 0;
                printf("This queue is full");
            }
            else cout<<"This queue has "<<number<<" elements";
        }
};
int queue::number=0;

int main()
{
    int p;
    queue q;
    cout<<"What's you want to do"<<endl<<"1.append"<<endl<<"2,pop"<<endl<<"3.check queue"<<endl;
    while(scanf("%d",&p)!=0)
    {
        switch(p)
        {
            case 1:q.append();break;
            case 2:q.pop();break;
            case 3:q.check();break;
            default : cout<<"please enter a useful intergrate";continue;
        }
        cout<<"\nWhat's you want to do"<<endl<<"1.append"<<endl<<"2,pop"<<endl<<"3.check queue"<<endl;
    }
}