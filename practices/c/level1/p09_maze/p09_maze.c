#include<stdio.h>
#include<windows.h>
#define row 8
#define culomn 8

char maze[row][culomn] = 
{
    {'*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '8', '*', '*', '*', '*', '*', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', '*', ' ', '*', '*', '*', ' ', '*'},
    {'*', ' ', ' ', '*', ' ', ' ', ' ', '*'},
    {'*', ' ', '*', '*', ' ', '*', '*', '*'},
    {'*', ' ', '*', ' ', ' ', ' ', ' ', ' '},
    {'*', '*', '*', '*', '*', '*', '*', '*'},
};

int x = 1, y = 1;
int nextx, nexty;
char street = ' ';

void print_maze();
void move_to_next_point();
void calculate_next_point(char direction);

void print_maze()
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < culomn; j++)
        {
            printf("%c", maze[i][j]);
        }
    printf("\n");
    }
}

void calculate_next_point(char direction)
{
    switch(direction)
    {
        case 'w':
            {
                nextx = x - 1;
                break;
            }
        case 's':
            {
                nextx = x + 1;
                break;
            }
        case 'a':
            {
                nexty = y - 1;
                break;
            }
        case 'd':
            {
                nexty = y + 1;
                break;
            }
        default:
            break;
    }
}

void move_to_next_point()
{
    if(maze[nextx][nexty] == street)
    {
        char temp = maze[nextx][nexty];
        maze[nextx][nexty] = maze[x][y];
        maze[x][y] = temp;
        x = nextx;
        y = nexty;
    }
    else
    {
        nextx = x;
        nexty = y;
    }
}

int main()
{
    nextx = x;
    nexty = y;
    print_maze();
    char direction;
    while(1)
    {
        scanf("%c", &direction);
        system("cls") ;
        calculate_next_point(direction);
        move_to_next_point();
        print_maze();
        if(x == row - 2 && y == culomn - 1)
        {
            printf("You win\n");
            break;
        }
    }
    return 0;
}
