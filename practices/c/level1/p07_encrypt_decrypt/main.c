#include <stdio.h>
#include "encrypt&decrypt.h"

char *get_command(int n);
void display_memu();
char *get_str(int num);
#define get_str() get_str()
int main()
{
    char *c, *str;
    int exit = 0;
    while (!exit)
    {
        display_memu();
        c = get_command(1);
        switch (*c)
        {
        case '1':
            str = "fuck";
            str = encrypt((const unsigned char *)str, strlen(str));
            printf("%s\n", str);
            break;
        case '2':
            str = "6676656e";
            str = (char*)decrypt(str);
            printf("%s\n", str);
            break;
        case '3':
            exit = 1;
            break;
        default:
            printf("请输入正确的选项\n");
        }
        free(c);
        free_memory();
    }
    return 0;
}
void display_memu()
{
    printf("欢迎使用加密解密系统\n");
    printf("1.加密\n");
    printf("2.解密\n");
    printf("3.退出\n");
    printf("请输入你的选择：");
}
char *get_command(int n)
{
    char *command, c;
    command = (char *)malloc(sizeof(char) * n);
    for (int i = 0; i < n; ++i)
        command[i] = getchar();
    putchar(command[0]);
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
    return command;
}
/*char *get_str(int num)
{
    if (num == 0)
        num = 128;
    char *str = (char*)malloc(sizeof(char) * num);
}*/
=======
#include <stdio.h>
#include "encrypt&decrypt.h"

/*char* get_str(int num = 0)
{
    int l =
    char *str = (char*)malloc(sizeof(char) * 128);
    for()
}*/
char *get_command(int n);
void display_memu();
int main()
{
    char *c, *str;
    int exit = 0;
    while (!exit)
    {
        display_memu();
        c = get_command(1);
        switch (*c)
        {
            case '1':
                str = "fuck";
                str = encrypt((const unsigned char *)str, strlen(str));
                printf("%s\n", str);
                break;
            case '2':
                str = "6676656e";
                str = (char*)decrypt(str);
                printf("%s\n", str);
                break;
            case '3':
                exit = 1;
                break;
            default:
                printf("请输入正确的选项\n");
        }
        free(c);
        free_memory();
    }
    return 0;
}
void display_memu()
{
    printf("欢迎使用加密解密系统\n");
    printf("1.加密\n");
    printf("2.解密\n");
    printf("3.退出\n");
    printf("请输入你的选择：");
}
char *get_command(int n)
{
    char *command, c;
    command = (char *)malloc(sizeof(char) * n);
    for (int i = 0; i < n; ++i)
        command[i] = getchar();
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
    return command;
}
>>>>>>> 8700e2ff565b2ba32d5190239b766a99eb23312f
