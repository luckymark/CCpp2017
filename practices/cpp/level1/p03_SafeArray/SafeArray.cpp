#include <cstdio>
#include <iostream>
using namespace std;

template <class Type>
struct SafeArray{
private:
    int length;
    Type* buffer;
public:
    SafeArray(int len)
    {
        length = len;
        buffer = new Type[length];
    }
    Type& operator[](int i) {
        if (i >= 0 && i < length)
            return buffer[i];
        else
            puts("Error!");
    }
};


int main() {
    return 0;
}
