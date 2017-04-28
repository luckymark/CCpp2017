#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    char m;
    canvas p;
    scanf("%c",&m)
    while(m!='q')
    {
        switch(m)
        {
            case '1':canvas.circle();break;
            case '2':canvas.rect();break;
            default : scanf("%c",&m);continue;
        }
    }
}