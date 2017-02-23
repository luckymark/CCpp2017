#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
bool calc_int(int age)
{
    int son = age - ((1 / 6.0 + 1 / 12.0 + 1 / 7.0) * age + 5) - 4;
    if(son * 2 == age)
        return true;
    else
        return false;
}
bool calc_float(double age)
{
    double son = age - ((1 / 6.0 + 1 / 12.0 + 1 / 7.0) * age + 5) - 4;
    //cout<< son <<endl;
    if(fabs(son * 2 - age) < 1e-8)
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
            cout<<"int:when his son died,his age is "<<i - 4<<endl;
            break;
        }
    }
    for(int i = 0;i < 100; ++i)
    {
        if(calc_float(i))
        {
            cout<<"float:when his son died,his age is "<<i - 4<<endl;
            break;
        }
    }
    //calc_float(84);
    return 0;
}