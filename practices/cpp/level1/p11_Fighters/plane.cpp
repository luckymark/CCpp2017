// plane.cpp : 定义控制台应用程序的入口点。
//


#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GAME.h"
#include "PLAYERS.h"
#include <vector>
#include "bullet.h"
#include "enemys.h"
#include <cmath>
#include "RESOURCE.h"
#include <time.h>
#include "TEXTURE.h"

using namespace std;
int main()
{
	sf::Music music;
	music.openFromFile(resourcePath() + "BGM3.ogg");
	music.setLoop(true);
	music.play();
	Texture texture;
	texture.load();
	srand(time(NULL));
	Game game;
	game.run();
	return 0;
}
