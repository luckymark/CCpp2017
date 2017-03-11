#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cross_platform.h"

typedef struct
{
    int x;
    int y;
}POS;

//函数声明
void re_draw_map();
void read_map();
void draw();
void move_next();
bool is_win();

const int map_l = 8;
const int move_data[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -2}, {0, 2}};
char **map_data;
POS *draw_queue, now_pos, aim_pos[100];
int draw_now = 0, aim_num = 0;

int main()
{
    initialize();
    draw_queue = (POS*)malloc(sizeof(POS) * map_l * map_l * 2);
    read_map();
    re_draw_map();
    while(1)
    {
        move_next();
        if (is_win())
        {
            print_xy("You Win!", 8, map_l,0);
            getchar();
            break;
        }
    }
    exit_program(0);
    return 0;
}

void move_next()
{
    int next_move = get_move();
    if (next_move == -1)
    {
        re_draw_map();
        return;
    }
    POS next_pos = {now_pos.x + move_data[next_move][0], now_pos.y + move_data[next_move][1]};
    char next_char = map_data[next_pos.x][next_pos.y], next_next_char;

    if (next_char != '#' )
    {
        next_next_char = map_data[next_pos.x + move_data[next_move][0]][next_pos.y + move_data[next_move][1]];
        if ((next_char == 'O' || next_char == '@') && next_next_char != 'a' && next_next_char != ' ')
        {
            return;
        }
        if (map_data[now_pos.x][now_pos.y] == '&')
            map_data[now_pos.x][now_pos.y] = 'a';
        else
            map_data[now_pos.x][now_pos.y] = ' ';

        draw_queue[draw_now] = now_pos;
        ++draw_now;
        now_pos.x += move_data[next_move][0];
        now_pos.y += move_data[next_move][1];

        if (next_char == ' ')
        {
            map_data[now_pos.x][now_pos.y] = '*';
            draw_queue[draw_now] = now_pos;
            ++draw_now;

        }
        else if(next_char == 'a')
        {
            map_data[now_pos.x][now_pos.y] = '&';
            draw_queue[draw_now] = now_pos;
            ++draw_now;
        }
        else
        {
            if(next_char == 'O')
                map_data[now_pos.x][now_pos.y] = '*';
            else
                map_data[now_pos.x][now_pos.y] = '&';

            draw_queue[draw_now] = now_pos;
            ++draw_now;
            next_pos.x += move_data[next_move][0];
            next_pos.y += move_data[next_move][1];

            if(next_next_char == 'a')
                map_data[next_pos.x][next_pos.y] = '@';
            else
                map_data[next_pos.x][next_pos.y] = 'O';

            draw_queue[draw_now] = next_pos;
            ++draw_now;
        }
        draw();
    }
}

void read_map()
{
    map_data = (char**)malloc(sizeof(char*) * map_l);
    for (int i =0; i < map_l; ++i)
        map_data[i] = (char*)malloc(sizeof(char) * (map_l * 2 + 3));
    FILE *fp = fopen("map.txt", "r");
    for (int i =0; i < map_l; ++i)
    {
        fgets(map_data[i], map_l * 2 + 3, fp);//第二个参数为最多读取数目减1 即多读取2个字符 为了兼容不同系统的换行符
    }
    fclose(fp);
}

void re_draw_map()
{
    POS pos;
    aim_num = 0;
    for (int i = 0; i < map_l; ++i)
    {
        for (int j = 0; j < map_l * 2; j += 2)
        {
            pos.x = i;
            pos.y = j;
            draw_queue[draw_now] = pos;
            ++ draw_now;
            switch (map_data[i][j])
            {
                case '*':
                    now_pos = pos;
                    break;
                case '&':
                    now_pos = pos;
                    aim_pos[aim_num] = pos;
                    ++aim_num;
                    break;
                case 'a':
                    aim_pos[aim_num] = pos;
                    ++aim_num;
                    break;
            }
        }
    }
    draw();
}

void draw()
{
    POS pos;
    while(draw_now)
    {
        --draw_now;
        pos = draw_queue[draw_now];
        print_xy(map_data[pos.x] + pos.y, 2, pos.x, pos.y);
    }
}

bool is_win()
{
    for (int i = 0; i < aim_num; ++i)
    {
        if (map_data[aim_pos[i].x][aim_pos[i].y] != '@')
            return false;
    }
    return true;
}