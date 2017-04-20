#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include "main.h"

using namespace std;

vector<Student> student;

int main()
{
    int a;
    bool quit = false;
    do
    {
        display_menu();
        switch(get_choose())
        {
            case 1:
                break;
            case 5:
                quit = true;
                break;
        }
    }while(quit == false);
    return 0;
}

void display_menu()
{
    clear_screen();
    printf("1.显示学生名单\n");
    printf("2.录入成绩\n");
    printf("3.选课\n");
    printf("4.退课\n");
    printf("5.退出\n");
    printf("输入你的选择：");
}

int get_choose()
{
    char c = 0;
    int ret, count;
    do
    {
        count = 0;
        if(c != 0)
        {
            printf("请输入正确的选项\n");
        }
        c = getchar();
        ret = c - '0';
        while((c = getchar()) != EOF && c != '\n')
        {
            ++count;
        }
    }while(ret > 5 || ret < 1 || count > 0);
    return ret;
}

void clear_screen()
{
    printf("\ec");
}

void read_data()
{
    Student stu;
    FILE *fp = fopen("student.data","rb");
    while(fread(&stu, sizeof(Student), 1, fp) != 1);
}

void write_data()
{
    Student stu;
    FILE *fp = fopen("student.data","rb");
    while(fwrite(&stu, sizeof(Student), 1, fp) != 1);
}

void display_data()
{
    for(int i = 0; i < student.size(); ++i)
    {
        printf("学号 ");
    }
}