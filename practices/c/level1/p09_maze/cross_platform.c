//
// Created by plusl on 2017/3/11.
//

#include "cross_platform.h"

//跨平台宏定义
#ifdef linux
#include <termio.h>
#include <zconf.h>

void set_key();
void reset_key();
int getch();

struct termios old_set, new_set;

void set_key()
{
    printf("\033[?25l");
    if (tcgetattr(STDIN_FILENO, &old_set) != 0)
    {
        printf("读取终端配置失败\n");
        exit(-1);
    }
    new_set = old_set;
    new_set.c_lflag &= ~(ICANON | ECHO | ISIG);//ICANON：标准模式 ECHO：显示 ISIG：中断信号
    if (tcsetattr(STDIN_FILENO, TCSANOW, &new_set) != 0)
    {
        printf("更新终端设置失败\n");
        exit(-2);
    }
}

void reset_key()
{
    printf("\033[?25h");
    if(tcsetattr(STDIN_FILENO, TCSANOW, &old_set) != 0)
    {
        printf("重置终端设置失败\n");
        exit(-3);
    }
}

void cls()
{
    printf("\ec");
}

void print_xy(const char * str, int len,int x, int y)
{
    char *tmp = (char*)malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; ++i)
        tmp[i] = str[i];
    tmp[len] = 0;
    printf("\033[%d;%dH%s", x + 1, y + 1, tmp); //linux奇怪的要求
}

int getch()
{
    set_key();
    int ret = getchar();
    reset_key();
    if (ret == 3)
        exit(1);
    return ret;
}

int get_move()
{
    if (getch() == 27 && getch() == 91)
    {
        switch (getch())
        {
            case 65:
                return 1;
            case 66:
                return 2;
            case 68:
                return 3;
            case 67:
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