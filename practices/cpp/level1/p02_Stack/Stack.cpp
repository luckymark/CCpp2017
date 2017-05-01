#include <cstdio>
#include <vector>
using namespace std;
template <class Type>
struct MY_Stack {
private:
    int top;
    int Maxtop;
    vector<Type> num;
public:
    MY_Stack(int x) {
        Maxtop = x;
        top = 0;
    }

    bool empty() {
        return top == 0;
    }

    bool full() {
        return top == Maxtop;
    }

    bool push(Type x) {
        if (!full()) {
            num[++top] = x;
            return 0;
        }
        printf("The stack is full!\n");
        return 1;
    }

    bool pop() {
        if (!empty())
        {
            top--;
            return 0;
        }
        printf("The stack is empty!\n");
        return 1;
    }
};

int main() {
    return 0;
}