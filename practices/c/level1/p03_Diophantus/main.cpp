#include <iostream>
using std::cout;
using std::cin;
using std::endl;
bool calc_int(int age)
{
    int son = age - ((1 / 6.0 + 1 / 12.0 + 1 / 7.0) * age + 5);
    if(son * 2 == age)
        return true;
    else
        return false;
}
bool calc_float(double age)
{
    double son = age - ((1 / 6.0 + 1 / 12.0 + 1 / 7.0) * age + 5);
    if(int(son) * 2 == int(age))
        return true;
    else
        return false;
}
int main()
{
    for(int i = 0;i < 100; ++i)
    {
        if(calc_int(i))
        {
            cout<<"int:his age is "<<i<<endl;
            break;
        }
    }
    for(int i = 0;i < 100; ++i)
    {
        if(calc_float(i))
        {
            cout<<"float:his age is "<<i<<endl;
            break;
        }
    }
    return 0;
}