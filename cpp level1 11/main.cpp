// �ɻ�.cpp : �������̨Ӧ�ó������ڵ㡣
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

