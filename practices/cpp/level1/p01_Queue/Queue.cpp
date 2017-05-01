#include <cstdio>
#include <cstring>
struct  queue {
private:
    int head, tail;
    int num[100];
public:
    queue () {
        head = 0; tail = -1;
        memset(num, -1, sizeof(num));
    }

    bool empty() {
        return tail < head;
    }

    bool full() {
        return tail == 99;
    }

    bool append(int x) {
        if (!full())
        {
            num[++tail] = x;
            return 0;
        }
        return 1;
    }

    bool pop(int x) {
        if (!empty())
        {
            head++;
            return 0;
        }
        return 1;
    }

} Queue;

int main() {
    return 0;
}