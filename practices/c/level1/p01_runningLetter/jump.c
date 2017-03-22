#include <windows.h>
#include <stdio.h>
HANDLE   hStdout;   //定义句柄
COORD   cursorPos;   //光标位置

void prepare() {
    hStdout   =   GetStdHandle(STD_OUTPUT_HANDLE);   //定义标准输入输出（屏幕）作为目标句柄
}
int   main()
{
    prepare();
    cursorPos.X = 0;  cursorPos.Y = 0;
    SetConsoleCursorPosition(   hStdout,   cursorPos   );   // (句柄，坐标)  设置光标位置
    int op = 1;
    int now = 0;
    while (1)
    {
        for (; (now >= 0) && (now <= 9); now += op)
        {
            cursorPos.X = now;
            SetConsoleCursorPosition(   hStdout,   cursorPos   );
            putchar('A');
            Sleep(100);
            SetConsoleCursorPosition(   hStdout,   cursorPos   );
            putchar(' ');
            Sleep(100);
        }
        op = -op;
        now += op;
    }
    CloseHandle(hStdout);   //   释放句柄
    return   0;
}