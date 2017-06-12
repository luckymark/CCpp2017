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


Game::Game() : my_window(sf::VideoMode(850, 1300), "Hit Plane"), player(2), bullet(), enemy()
{
	background_sp.setTexture(Texture::background_texture);
	gameover_sp.setTexture(Texture::gameover_texture);
	gameover_sp.setScale(2, 2);
	my_window.setFramerateLimit(60);
	font.loadFromFile(resourcePath() + "华文仿宋.ttf");
	lovely_font.loadFromFile(resourcePath() + "lovely.ttf");

	enemy.sprite.setTexture(Texture::enemy_texture);
	enemy_boss.setTexture(Texture::enemy_boss_texture);
	score_text.setFont(font);
	escape_enemy.setFont(font);
	health_text.setFont(font);
	begin_text.setFont(lovely_font);
	gameover_text.setFont(lovely_font);

	score_text.setPosition(0, 1250);
	escape_enemy.setPosition(0, 1225);
	health_text.setPosition(0, 1205);

	score_text.setColor(sf::Color::Black);
	escape_enemy.setColor(sf::Color::Black);
	health_text.setColor(sf::Color::Black);
	gameover_text.setColor(sf::Color::Black);

	destroy.setTexture(Texture::player_destory);
}
void Game::again_game()
{
	bullet.player_bullet.clear();
	bullet.enemy_bullet.clear();
	enemy.all_enemy.clear();
	enemy.escape_enemy = 0;
	player.health = 4;
	score = 0;
	enemy.tot_enemy = 0;
}
void Game::run()
{
	while (my_window.isOpen())
	{
		if (new_game && !is_game) { new_game = false; is_game = true; again_game(); }
		processEvents();
		if (esc) continue;
		if (game_begin && is_game) update();
		if (is_game) render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (my_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			my_window.close();
			break;
		}
	}
}
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		player.up = isPressed;
	else if (key == sf::Keyboard::S)
		player.down = isPressed;
	else if (key == sf::Keyboard::A)
		player.left = isPressed;
	else if (key == sf::Keyboard::D)
		player.right = isPressed;
	else if (key == sf::Keyboard::Space)
		bullet.is_fire = isPressed;
	else if (key == sf::Keyboard::Escape)
		esc = isPressed;
	else if (key == sf::Keyboard::J)
		new_game = isPressed;
	else if (key == sf::Keyboard::E)
		game_begin = true;

}
void Game::add_enemy_bullet()
{
	int tot = enemy.all_enemy.size();
	for (int i = 0; i < tot; i++)
	{
		if (enemy.all_enemy[i].health >= 2)
		{
			sf::Vector2f player_pos = player.sprite.getPosition();
			sf::Vector2f enemy_pos = enemy.all_enemy[i].sprite.getPosition();
			sf::Vector2f speed = (player_pos - enemy_pos) / 150.0f;
			bullet.add_bullet(enemy_pos, speed, false, true);
		}
	}
	if (tot)
	{
		int a = random() % tot;
		if (enemy.all_enemy[a].health >= 2) return;
		sf::Vector2f speed(0.0f, enemy.all_enemy[a].speed + 2.0);
		bullet.add_bullet(enemy.all_enemy[a].sprite.getPosition(), speed, false, false);
	}
}
void Game::update()
{
	player.move(10);
	sf::Vector2f speed(0, -13.0);
	if (bullet.is_fire) bullet.add_bullet(player.sprite.getPosition(), speed, true, false);
	bullet.move_bullet();
	check_bound();  //判断碰撞
	enemy.add_enemy();
	add_enemy_bullet();
	enemy.move();
}
void Game::check_bound()
{
	int tot_bullet = bullet.player_bullet.size();
	int tot_enemy = enemy.all_enemy.size();
	for (int i = tot_bullet - 1; i >= 0; i--)
	{
		for (int j = enemy.all_enemy.size() - 1; j >= 0; j--)
		{
			if (bullet.player_bullet[i].sprite.getGlobalBounds().intersects(enemy.all_enemy[j].sprite.getGlobalBounds()))

			{
				bullet.player_bullet.erase(bullet.player_bullet.begin() + i);
				enemy.all_enemy[j].health--;
				if (enemy.all_enemy[j].health == 0)
				{
					score += enemy.all_enemy[j].score;
					destroy.setPosition(enemy.all_enemy[j].sprite.getPosition());
					is_destroy = true;
					enemy.all_enemy.erase(enemy.all_enemy.begin() + j);
					break;
				}
			}
		}
	}
	for (int i = bullet.enemy_bullet.size() - 1; i >= 0; i--)
		if (bullet.enemy_bullet[i].sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()) && player.hit == false)
		{
			bullet.enemy_bullet.erase(bullet.enemy_bullet.begin() + i);
			player.health--;
			player.hit = true;
			if (player.health <= 0)
				player.sprite.setPosition(425, 1200);
		}

}
void Game::play_hit()
{
	if (player.hit)
	{
		if (player.health_time % 20 >= 10)
			player.sprite.setColor(sf::Color(255, 255, 255, 100));
		else player.sprite.setColor(sf::Color(255, 255, 255, 255));
		player.health_time--;
		if (player.health_time == 0)
		{
			player.health_time = 150;
			player.hit = false;
		}
	}
}
void Game::load_text()
{
	sf::String s = "score: ";
	char str[10];
	sprintf(str, "%d", score);
	s += str;
	score_text.setString(s);

	s = "escape enemy: ";
	sprintf(str, "%d", enemy.escape_enemy);
	s += str;
	escape_enemy.setString(s);

	s = "health: ";
	sprintf(str, "%d", player.health);
	s += str;
	health_text.setString(s);
}

void Game::begin_game()
{
	sf::String s = L"4条命\n                           = 5分\n\n\n                           = 50分\n\n\n                  按 E 可赛艇\n\n\n\n\n\n";
	begin_text.setString(s);
	begin_text.setColor(sf::Color::Black);
	begin_text.setScale(1.7, 1.7);
	begin_text.setPosition(0, 100);
	enemy_boss.setPosition(200, 400);
	enemy.sprite.setPosition(250, 300);
}

void Game::render()
{
	my_window.clear();
	if (!game_begin)
	{
		my_window.draw(background_sp);
		begin_game();
		my_window.draw(begin_text);
		my_window.draw(enemy.sprite);
		my_window.draw(enemy_boss);

	}
	else
		if (enemy.escape_enemy >= 10 || player.health <= 0)
		{
			my_window.draw(gameover_sp);
			sf::String s = L"最终得分: ";
			char str[10];

			sprintf(str, "%d", score);
			s += str;
			s += L"\n\n\n\n\n\n\n\n\n\n\n按J重新开始";
			gameover_text.setString(s);
			gameover_text.setScale(2, 2);
			gameover_text.setPosition(200, 70);
			is_game = false;
			int p = score>300 ? score : 300;
			p = score>700 ? 700 : p;
			final_score.setTexture(Texture::score_texture[p / 100]);
			final_score.setPosition(200, 210);
			final_score.setScale(2, 2);
			my_window.draw(gameover_text);
			my_window.draw(final_score);
		}
		else
		{
			my_window.draw(background_sp);
			load_text();
			my_window.draw(score_text);
			my_window.draw(escape_enemy);
			my_window.draw(health_text);
			play_hit();
			my_window.draw(player.sprite);
			for (int i = 0; i < bullet.player_bullet.size(); i++)
			{
				my_window.draw(bullet.player_bullet[i].sprite);
			}
			if (is_destroy && destroy_time)
			{
				my_window.draw(destroy);
				destroy_time--;
				if (destroy_time == 0)
				{
					destroy_time = 5;
					is_destroy = false;
				}
			}

			for (int i = 0; i < enemy.all_enemy.size(); i++)
			{
				my_window.draw(enemy.all_enemy[i].sprite);
			}
			for (int i = 0; i < bullet.enemy_bullet.size(); i++)
			{
				my_window.draw(bullet.enemy_bullet[i].sprite);
			}

		}
	my_window.display();
}