#include<stdlib.h>
#include<stdio.h> 
#include<string.h>
#include<conio.h>
 
int x = 0, y = 0, count = 0;
int map[8][10] = {0};
int map_1[8][10] = {0};
int count1();
int count2();
int move(char direction);
int draw_map();
int find();
int readmap(); 

int main()
{
    int n, m, direction;
    memcpy(map, map_1, sizeof(map_1));
    printf("Press 'wasd' to control the direction.\n"
           "Press 'r' to restart.\n");
    readmap();
    direction = getch();
    system("cls");
    n = count1();
    while(1)
    {
        system("cls");
        draw_map();
        m = count2();
        find();
        direction = getch();
        move(direction);
        if(n==m)
        {
            system("cls");
            printf("游戏胜利~\n");
            return 0;
        }
    }
}

int readmap()
{
    int level;
    FILE * fp;
    printf("Enter number to choose the game level:\n"
           "1->easy.\n"
           "2->normal.\n"
           "3->hard.\n");
    scanf("%d", &level);
    switch(level)
    {
        case 1:
        {
            fp = fopen("easy.txt", "r");
            break;
        }
        case 2:
        {
            fp = fopen("normal.txt", "r");
            break;
        }
        case 3:
        {
            fp = fopen("hard.txt", "r");
            break;
        }
    }
    if(fp == NULL)
    {
        puts("Can't open file.");
        exit(1);
    }
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 10; j++)
            fscanf(fp, "%d", &map[i][j]);
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 10; j++)
            map_1[i][j] = map[i][j];
    fclose(fp);
}
    

int move(char direction)
{
    switch(direction)
    {
        case 'w':
            {
                if(map[x][y] == 3)
                {
                    if(map[x - 1][y] == 0)
                    {
                        map[x - 1][y] = 3;
                        if(map[x][y] == 6)
                        map[x][y] = 4;
                    else
                        map[x][y] = 0;
                        count++;
                    }
                    else if(map[x - 1][y] == 4)
                    {
                        map[x - 1][y] = 6;
                        if(map[x][y] == 6)
                            map[x][y] = 4;
                        else
                            map[x][y] = 0;
                        count++;
                    }
                    else if(map[x - 1][y] == 2)
                    {
                        if (map[x - 2][y] == 0)
                        {
                            map[x - 2][y] = 2;
                            if(map[x - 1][y] == 5)
                                map[x - 1][y] = 6;
                            else
                                map[x - 1][y] = 3;
                            if(map[x][y] == 6)
                                map[x][y] = 4;
                            else
                                map[x][y] = 0;
                            count++;
                        }
                        else if (map[x - 2][y] == 4)
                        {
                            map[x - 2][y] = 5;
                            if(map[x - 1][y] == 5)
                                map[x - 1][y] = 6;
                            else
                                map[x - 1][y] = 3;
                            if(map[x][y] == 6)
                                map[x][y] = 4;
                            else
                                map[x][y] = 0;
                            count++;
                        }
                    }
                    else if(map[x - 1][y] == 5)
                    {
                        if(map[x - 2][y] == 0)
                        {
                            map[x - 2][y] = 2;
                            map[x - 1][y] = 6;
                            if(map[x][y] == 6)
                                map[x][y] = 4;
                            else
                                map[x][y] = 0;
                            count++;
                        }
                        if(map[x - 2][y] == 4)
                        {
                            map[x - 2][y] = 5;
                            map[x - 1][y] = 6;
                            if(map[x][y] == 6)
                                map[x][y] = 4;
                            else
                                map[x][y] = 0;
                            count++;
                        }
                    }
                }
                break;
            }
        case 's':
            {
                if(map[x][y] == 3)
                {
                    if(map[x + 1][y] == 0)
                    {
                        map[x + 1][y] = 3;
                        if(map[x][y] == 6)
                            map[x][y] = 4;
                        else
                            map[x][y] = 0;
                        count++;
                    }
                    else if(map[x + 1][y] == 4)
                    {
                        map[x + 1][y] = 6;
                        if(map[x][y] == 6)
                            map[x][y] = 4;
                        else
                            map[x][y] = 0;
                        count++;
                    }
                    else if(map[x + 1][y] == 2)
                    {
                        if (map[x + 2][y] == 0)
                        {
                            map[x + 2][y] = 2;
                            if(map[x + 1][y] == 5)
                                map[x + 1][y] = 6;
                            else
                                map[x + 1][y] = 3;
                            if(map[x][y] == 6)
                                map[x][y] = 4;
                            else
                                map[x][y] = 0;
                            count++;
                        }
                        else if (map[x + 2][y] == 4)
                        {
                            map[x + 2][y] = 5;
                            if(map[x + 1][y] == 5)
                                map[x + 1][y] = 6;
                            else
                                map[x + 1][y] = 3;
                            if(map[x][y] == 6)
                                map[x][y] = 4;
                            else
                                map[x][y] = 0;
                            count++;
                        }
                    }
                    else if(map[x + 1][y] == 5)
                    {
                        if(map[x + 2][y] == 0)
                        {
                            map[x + 2][y] = 2;
                            map[x + 1][y] = 6;
                            if(map[x][y] == 6)
                                map[x][y] = 4;
                            else
                                map[x][y] = 0;
                            count++;
                        }
                        if(map[x + 2][y] == 4)
                        {
                            map[x + 2][y] = 5;
                            map[x + 1][y] = 6;
                            if(map[x][y] == 6)
                                map[x][y] = 4;
                            else
                                map[x][y] = 0;
                            count++;
                        }
                    }
                }
                break;
            }
        case 'a':
            {
                if(map[x][y] == 3)
                {
                    if(map[x][y - 1] == 0)
                    {
                        map[x][y - 1] = 3;
                        if(map[x][y] == 6)
                            map[x][y] = 4;
                        else
                            map[x][y] = 0;
                        count++;
                    }
                    else if(map[x][y - 1] == 4)
                    {
                        map[x][y - 1] = 6;
                        if(map[x][y] == 6)
                            map[x][y] = 4;
                        else
                            map[x][y] = 0;
                        count++;
                    }
                    else if(map[x][y - 1] == 2)
                    {
                        if (map[x][y - 2] == 0)
                        {
                            map[x][y - 2] = 2;
                            if(map[x][y - 1] == 5)
                                map[x][y - 1] = 6;
                            else
                                map[x][y - 1] = 3;
                            if(map[x][y] == 6)
                                map[x][y] = 4;
                            else
                                map[x][y] = 0;
                            count++;
                        }
                        else if (map[x][y - 2] == 4)
                        {
                            map[x][y - 2] = 5;
                            if(map[x][y - 1] == 5)
                                map[x][y - 1] = 6;
                            else
                                map[x][y - 1] = 3;
                            if(map[x][y] == 6)
                                map[x][y] = 4;
                            else
                                map[x][y] = 0;
                            count++;
                        }
                    }
                    else if(map[x][y - 1] == 5)
                    {
                        if(map[x][y - 2] == 0)
                        {
                            map[x][y - 2] = 2;
                            map[x][y - 1] = 6;
                            if(map[x][y] == 6)
                                map[x][y] = 4;
                            else
                                map[x][y] = 0;
                            count++;
                        }
                        if(map[x][y - 2] == 4)
                        {
                            map[x][y - 2] = 5;
                            map[x][y - 1] = 6;
                            if(map[x][y] == 6)
                                map[x][y] = 4;
                            else
                                map[x][y] = 0;
                            count++;
                        }
                    }
                }
                break;
            }
        case 'd':
            {
                if(map[x][y] == 3)
                {
                    if(map[x][y + 1] == 0)
                    {
                        map[x][y + 1] = 3;
                        if(map[x][y] == 6)
                            map[x][y] = 4;
                        else
                            map[x][y] = 0;
                        count++;
                    }
                    else if(map[x][y + 1] == 4)
                    {
                        map[x][y + 1] = 6;
                        if(map[x][y] == 6)
                            map[x][y] = 4;
                        else
                            map[x][y] = 0;
                        count++;
                    }
                    else if(map[x][y + 1] == 2)
                    {
                        if (map[x][y + 2] == 0)
                        {
                            map[x][y + 2] = 2;
                            if(map[x][y + 1] == 5)
                                map[x][y + 1] = 6;
                            else
                                map[x][y + 1] = 3;
                            if(map[x][y] == 6)
                                map[x][y] = 4;
                            else
                                map[x][y] = 0;
                            count++;
                        }
                        else if (map[x][y + 2] == 4)
                        {
                            map[x][y + 2] = 5;
                            if(map[x][y + 1] == 5)
                                map[x][y + 1] = 6;
                            else
                                map[x][y + 1] = 3;
                            if(map[x][y] == 6)
                                map[x][y] = 4;
                            else
                                map[x][y] = 0;
                            count++;
                        }
                    }
                    else if(map[x][y + 1] == 5)
                    {
                        if(map[x][y + 2] == 0)
                        {
                            map[x][y + 2] = 2;
                            map[x][y + 1] = 6;
                            if(map[x][y] == 6)
                                map[x][y] = 4;
                            else
                                map[x][y] = 0;
                            count++;
                        }
                        if(map[x][y + 2] == 4)
                        {
                            map[x][y + 2] = 5;
                            map[x][y + 1] = 6;
                            if(map[x][y] == 6)
                                map[x][y] = 4;
                            else
                                map[x][y] = 0;
                            count++;
                        }
                    }
                }
                break;
            }
        case 'r':
            {
                memcpy(map, map_1, sizeof(map_1));
                count = 0;
                break;
            }
    }
}
 
int draw_map()
{
    for(x=0; x<8; x++)
    {
        for(y=0; y<10; y++)
        {
            if(map[x][y] == 1)
                printf("■"); //砖块
            if(map[x][y] == 3)
                printf("⊙"); //自己
            if(map[x][y] == 2)
                printf("□"); //箱子
            if(map[x][y] == 4)
                printf("☆"); //箱子要到的位置 
            if(map[x][y] == 0)
                printf("  "); //空地 
            if(map[x][y] == 5) 
                printf("★"); //箱子到了该到的位置 
        }
        printf("\n");
    }
    printf("\nAlready moved %d steps.", count);
    return 0;
}
//找到自己的位置
int find()
{
    for(x = 0; x < 8; x++)
        for(y = 0; y < 10; y++)
        {
            if(map[x][y] == 3)
                return 0;
        }
        return 0;
}
//箱子要到的位置的个数
int count1()
{
    int n = 0;
    for(x = 0; x < 8; x++)
        for(y = 0; y < 10; y++)
        {
            if(map[x][y] == 4)
                n++;
        }
   return n;
}
//箱子到了位置的个数
int count2()
{
    int m = 0;
    for(x = 0; x < 8; x++)
        for(y = 0; y < 10; y++)
        {
            if(map[x][y] == 5)
                m++;
        }
        return m;
}
