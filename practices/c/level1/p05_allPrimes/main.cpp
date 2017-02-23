#include <iostream>
#include <cmath>
#include <ctime>


using std::cout;
using std::endl;

const int max_num = 1000;

int main()
{
    int start, end;
    start = clock();
    bool *data = new bool[max_num + 1];
    for(int i = 0;i <= max_num; ++i)
        data[i] = true;
    for(int i = 2;i <= max_num; ++i)
    {
        if(data[i])
        {
            for(int j = i * i; j <= max_num; j += i)
                data[j] = false;
            cout<<i<<" ";
        }
    }
    end = clock();
    cout<<"\n使用了"<<end - start<<"ms"<<endl;
    return 0;
}