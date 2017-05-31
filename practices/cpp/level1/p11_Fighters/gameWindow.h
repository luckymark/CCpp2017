#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "plane.h"

void gameProcess();
void playerAction(plane & p, bool & flag);
void enemysAction(plane * p, bool & flag);
#endif
