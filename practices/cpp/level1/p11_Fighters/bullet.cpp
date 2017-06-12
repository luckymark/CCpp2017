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

Bullet::Bullet(sf::Vector2f speed, double x, double y)
{
	bullet_speed = speed;
	pos.x = x;
	pos.y = y;
	if (speed.y< 0)sprite.setTexture(Texture::player_bullet_texture);
	else
		sprite.setTexture(Texture::enemy_bullet_texture);
	sprite.setPosition(pos.x, pos.y);
}
void Bullet::add_bullet(sf::Vector2f pos, sf::Vector2f speed, bool direction, bool is_boss)
{
	if (!is_boss && direction && player_bullet_time>player_bullet_limit)
	{
		player_bullet.push_back(Bullet(speed, pos.x + 55, pos.y - 20));
		player_bullet_time = 0;
	}
	if (!is_boss && !direction && enemy_bullet_time > enemy_bullet_limit)
	{
		enemy_bullet.push_back(Bullet(speed, pos.x + 35, pos.y + 100));
		enemy_bullet_time = 0;
	}
	if (is_boss && boss_bullet_time > enemy_bullet_limit)
	{
		enemy_bullet.push_back(Bullet(speed, pos.x + 100, pos.y + 200));
		boss_bullet_time = 0;
	}
}

void Bullet::move_bullet()
{
	enemy_bullet_time = fmin(enemy_bullet_time + 1, 1000);
	player_bullet_time = fmin(player_bullet_time + 1, 1000);
	boss_bullet_time = fmin(boss_bullet_time + 1, 1000);
	int tot = player_bullet.size();
	for (int i = 0; i < tot; i++)
	{
		player_bullet[i].sprite.move(player_bullet[i].bullet_speed);
	}
	for (int i = tot - 1; i >= 0; i--)
		if (player_bullet[i].pos.y<0)
			player_bullet.erase(player_bullet.begin() + i);

	tot = enemy_bullet.size();
	for (int i = 0; i < tot; i++)
	{
		enemy_bullet[i].sprite.move(enemy_bullet[i].bullet_speed);
	}
	for (int i = tot - 1; i >= 0; i--)
		if (enemy_bullet[i].pos.y>1200 && enemy_bullet[i].pos.x<0 && enemy_bullet[i].pos.y>850)
			enemy_bullet.erase(enemy_bullet.begin() + i);

}