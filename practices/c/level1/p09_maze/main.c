#include <stdio.h>
#include <stdlib.h>
#include "cross_platform.h"
//函数声明
void display(char **data, int x, int y);


int main()
{
    cls();
    printf("hahahahah\n");
    print_xy("haihai\n", 7,31, 5);
    return 0;
}

void display(char **data, int x, int y)
{
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
            putchar(data[x][y]);
    }
}