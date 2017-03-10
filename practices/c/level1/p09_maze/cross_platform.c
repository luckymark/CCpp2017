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

#elif WIN32

#include<windows.h>

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

#endif