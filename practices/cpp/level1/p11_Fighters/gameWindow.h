#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "plane.h"

void gameProcess();
void playerAction(plane & p);
void enemysAction(plane * p, bool & flag1,int max);
bool gameloop(sf::RenderWindow &window,int max_enemy, int &time_count,int &time);
#endif
