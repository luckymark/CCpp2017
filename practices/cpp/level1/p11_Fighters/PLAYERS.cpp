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

Player::Player(double _speed)
{
	speed = _speed;
	sprite.setTexture(Texture::player_texture);
	sprite.setPosition(425, 1200);
	health = 3;
}