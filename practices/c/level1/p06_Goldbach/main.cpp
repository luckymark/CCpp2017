#include <iostream>
#include <cmath>
#include <ctime>


using std::cout;
using std::endl;
const int num = 100;
bool* produce_prime(int max_num) //生成小于等于max_num的素数并返回指针
{
    if(max_num <=1)
        return NULL;
    bool *ret = new bool[max_num+1];
    for(int i = 0;i <= max_num; ++i)
        ret[i] = true;
    for(int i = 2;i <= max_num; ++i)
    {
        if(ret[i])
        {
            for(int j = i * i; j <= max_num; j += i)
                ret[j] = false;
        }
    }
    ret[0] = false;
    ret[1] = false;
    return ret;
}
int main()
{
    bool *data = produce_prime(num), result = true;
    int prime[num+1], count = 0;
    for(int i = 0; i <= num; i++)
    {
        if(data[i])
            prime[count++] = i;
    }
    for(int i = 4;result && i <= num; i += 2)
    {
        for(int j = 0; j < count; ++j)
        {
            if(data[i - prime[j]])
            {
                cout<<i<<"="<<prime[j]<<"+"<<i - prime[j]<<endl;
                break;
            }
            else if(j == count - 1)
            {
                cout << i << "can't be solve" << endl;
                result = false;
            }
        }
    }
    if(result)
        cout<<"Goldbach Conjecture in 100 is right"<<endl;
    else
        cout<<"Goldbach Conjecture in 100 is wrong"<<endl;
    return 0;
}