#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
bool is_narcissus(int num)
{
    int tmp = num, result = 0;
    for(int i = 2;i >=0; --i)
    {
        result += pow(tmp % 10, 3);
        tmp /= 10;
    }
    if (num == result)
        return true;
    else
        return false;
}
int main()
{
    for(int i = 100; i < 1000;i ++)
    {
        if(is_narcissus(i))
            cout<<i<<endl;
    }
    return 0;
}