// skyLegend.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include "plane.h"
#include "gameMusic.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "gameWindow.h"
int main() {
	srand(time(0));
	gameProcess();

	return 0;
}