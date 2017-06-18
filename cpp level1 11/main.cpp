// 飞机.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "game.h"
#include "StartMenu.h"




int main()
{
	Game game;	
	game.start();
	game.help();
	while (StartMenu::number != 2)
	{
		game.play();
		game.again();
	}
	return 0;
}

