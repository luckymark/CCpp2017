//
// Created by plusl on 2017/3/11.
//

#include "cross_platform.h"

//跨平台宏定义
#ifdef linux

void cls()
{
    printf("\ec");
}

void print_xy(const char * str, int len,int x, int y)
{
    printf("\033[%d;%dH%s", x, y, str);
}

int get_move()
{
    if (getch() == 224)
    {
        switch (getch())
        {
            case 72:
                return 1;
            case 80:
                return 2;
            case 75:
                return 3;
            case 77:
                return 4;
        }
    }
    else
        return 0;
}
#elif WIN32

#include<windows.h>
#include<conio.h>

void cls()
{
    system("cls");
}

void print_xy(const char * str, int len, int x, int y)
{
    int NumberOfCharsWritten;
    HANDLE hnd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {y, x};
    WriteConsoleOutputCharacter(hnd, str, len, coord, &NumberOfCharsWritten);
}

int get_move()
{
    if (getch() == 224)
    {
        switch (getch())
        {
            case 72:
                return 1;
            case 80:
                return 2;
            case 75:
                return 3;
            case 77:
                return 4;
        }
    }
    else
        return 0;
}
#endif