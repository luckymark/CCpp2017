#include <windows.h>
#include <stdio.h>
HANDLE   hStdout;   //������
COORD   cursorPos;   //���λ��

void prepare() {
    hStdout   =   GetStdHandle(STD_OUTPUT_HANDLE);   //�����׼�����������Ļ����ΪĿ����
}
int   main()
{
    prepare();
    cursorPos.X = 0;  cursorPos.Y = 0;
    SetConsoleCursorPosition(   hStdout,   cursorPos   );   // (���������)  ���ù��λ��
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
    CloseHandle(hStdout);   //   �ͷž��
    return   0;
}