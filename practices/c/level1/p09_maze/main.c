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
void display();
void read_map();
void draw();

const int map_l = 10;
const int move_data[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -2}, {0, 2}};
char **map_data;
POS *draw_queue, now_pos = {1, 2};
int draw_now = 0;

int main()
{
    draw_queue = (POS*)malloc(sizeof(POS) * map_l * map_l * 2);
    cls();
    read_map();
    display();
    draw();
    int j = 100, next_move;
    while(j--)
    {
        next_move = get_move();
        if (next_move != 0 && map_data[now_pos.x + move_data[next_move][0]][now_pos.y + move_data[next_move][1]] != '#')
        {
            map_data[now_pos.x][now_pos.y] = ' ';
            draw_queue[draw_now] = now_pos;
            ++draw_now;
            now_pos.x += move_data[next_move][0];
            now_pos.y += move_data[next_move][1];
            map_data[now_pos.x][now_pos.y] = '*';
            draw_queue[draw_now] = now_pos;
            ++draw_now;
        }
        draw();
    }
    return 0;
}

void read_map()
{
    map_data = (char**)malloc(sizeof(char*) * map_l);
    for (int i =0; i < map_l; ++i)
        map_data[i] = (char*)malloc(sizeof(char) * (map_l * 2 + 1));
    FILE *fp = fopen("map.txt", "r");
    for (int i =0; i < map_l; ++i)
    {
        fgets(map_data[i], map_l * 2 + 2, fp);
        fgetc(fp);
    }
    fclose(fp);
}

void display()
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
        }
    }
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