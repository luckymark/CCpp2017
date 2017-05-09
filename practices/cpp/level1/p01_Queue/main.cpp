#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

template <typename T, typename U>
const T& GetMin(T &a, U &b) { return (a<b?a:b); }

int main()
{
    string str;
    //cin>>str;
    while(getline(cin, str))
    {
        cout<<str<<endl;
    }
    cout<<(int)getchar()<<endl;
    return 0;
}