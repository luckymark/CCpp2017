#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
bool is_prime(int num)
{
    if(num < 2)
        return false;
    int tmp = sqrt(num);
    for(int i = 2;i <= tmp; ++i)
    {
        if(num % i == 0)
            return false;
    }return true;
}
int main()
{
    int num;
    cin>>num;
    if(is_prime(num))
        cout<<"这是个质数";
    else
        cout<<"这不是质数";
    cout<<endl;
    return 0;
}