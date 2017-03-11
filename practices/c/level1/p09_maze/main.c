#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

const int map_l = 10;
const int move_data[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -2}, {0, 2}};
char **map_data;
POS *draw_queue, now_pos, exit_pos;
int draw_now = 0;

int main()
{
    initialize();
    draw_queue = (POS*)malloc(sizeof(POS) * map_l * map_l * 2);
    read_map();
    re_draw_map();
    while(1)
    {
        move_next();
        if (now_pos.x == exit_pos.x && now_pos.y == exit_pos.y)
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
        re_draw_map();
    else if (map_data[now_pos.x + move_data[next_move][0]][now_pos.y + move_data[next_move][1]] != '#')
    {
        map_data[now_pos.x][now_pos.y] = ' ';
        draw_queue[draw_now] = now_pos;
        ++draw_now;
        now_pos.x += move_data[next_move][0];
        now_pos.y += move_data[next_move][1];
        map_data[now_pos.x][now_pos.y] = '*';
        draw_queue[draw_now] = now_pos;
        ++draw_now;
        draw();
    }
}

void read_map()
{
    map_data = (char**)malloc(sizeof(char*) * map_l);
    for (int i =0; i < map_l; ++i)
        map_data[i] = (char*)malloc(sizeof(char) * (map_l * 2 + 1));
    FILE *fp = fopen("map.txt", "r");
    for (int i =0; i < map_l; ++i)
    {
        fgets(map_data[i], map_l * 2 + 1, fp);
        fgetc(fp);
    }
    fclose(fp);
}

void re_draw_map()
{
    POS pos;
    for (int i = 0; i < map_l; ++i)
    {
        for (int j = 0; j < map_l * 2; j += 2)
        {
            pos.x = i;
            pos.y = j;
            draw_queue[draw_now] = pos;
            ++ draw_now;
            if (map_data[i][j] == '*')
                now_pos = pos;
            else if (map_data[i][j] == '&')
                exit_pos = pos;
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