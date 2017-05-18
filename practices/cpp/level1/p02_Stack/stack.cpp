#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;
template<typename T>
class InStack
{
    private:
        void *p;
        int number;
        int max;
    public:
        
        InStack(int q=100)
        {
            p=new int[q];
            max=q;
            number=0;
        }
        void push()
        {
            int q;
            cout<<"Enter a integer"<<endl;
            cin>>q;
            if(number<100)
            {
                for(int i=number;i>0;i--)p[number]=p[number-1];
                p[0]=q;
                number++;
            }
            
        }
        void pop()
        {
            if(number>=1)
            {
                for(int i=0;i<number-1;i++)p[i]=p[i+1];
                p[number-1]=0;
                number--;
            }
        }
        int check()
        {
            if(number==max)
            {
                cout<<"This stack is full"<<endl;
                return 0;    
            }
            else if(number==0)
            {
                cout<<"This stack is empty"<<endl;
                return 1;
            }
            else 
            {
                cout<<"This stack has "<<number<<" integers"<<endl;
                return 1;
            }
        }
};

int main()
{
    int n,p,d=1;
    cout<<"How much do you want?"<<endl;
    while(scanf("%d",&n)!=1)continue;
    InStack example(n);

    while(d)
    {
        cout<<"What's you want to do"<<endl
        <<"1.push"<<endl
        <<"2.pop"<<endl
        <<"3.check"<<endl
        <<"4.quit"<<endl;
        cin>>p;
        switch(p)
        {
            case 1:example.push();break;
            case 2:example.pop();break;
            case 3:example.check();break;
            case 4:d=0;break;
        }
    }

}