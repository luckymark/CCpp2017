#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void display_memu()
{
    printf("欢迎使用加密解密系统\n");
    printf("1.加密\n");
    printf("2.解密\n");
    printf("3.退出\n");
    printf("请输入你的选择：");
}
char* get_command(int n)
{
    char *command,c;
    command = (char*)malloc(sizeof(char) * n);
    for(int i = 0; i < n; ++i)
        command[i] = getchar();
    putchar(command[0]);
    do
    {
        c = getchar();
    }while(c != '\n' && c != EOF);
    return command;
}
char* encrypt(const unsigned char* str)
{
    int l = strlen((char*)str);
    char *ret = (char*)malloc(sizeof(char) * (l * 2 + 1)), *tmp;
    tmp = ret;
    ret[l * 2] = '\0';
    for(int i = 0; i < l;i++)
    {
        sprintf(tmp, "%02x", (unsigned char)(str[i] + i));
        tmp += 2;
    }
    return ret;
}
char* decrypt(const unsigned char* str)
{
    int l = strlen((char*)str);
    char *ret = (char*)malloc(sizeof(char) * (l * 2 + 1)), *tmp;
    tmp = ret;
    ret[l * 2] = '\0';
    for(int i = 0; i < l;i++)
    {
        sprintf(tmp, "%02x", (unsigned char)(str[i] + i));
        tmp += 2;
    }
    return ret;
}
/*char* get_str(int num = 0)
{
    int l =
    char *str = (char*)malloc(sizeof(char) * 128);
    for()
}*/
int main()
{
    char *c, *str, *str1;
    int exit = 0;
    while(!exit)
    {
        display_memu();
        c = get_command(1);
        switch(*c)
        {
            case '1':
                str = "fuck";
                str1 = encrypt((const unsigned char*)str);
                //free(str);
                printf("%s\n", str1);
                free(str1);
                break;
            case '2':
                str = "16676656e";
                str1 = decrypt(str);
                //free(str);
                printf(str1);
                free(str1);
                break;
            case '3':
                exit = 1;
                break;
            default:
                printf("请输入正确的选项\n");
        }
        free(c);
    }
    return 0;
}