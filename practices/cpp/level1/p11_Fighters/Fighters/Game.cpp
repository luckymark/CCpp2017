//
//  Game.cpp
//  Fighters
//
//  Created by Jimmy Fan on 2017/5/15.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include "Game.h"
using namespace std;

Game::Game() {
    mWindow.create(sf::VideoMode(windowWidth,windowHeight), "Fighters");
    mWindow.setFramerateLimit(60);
    gameTime = sf::Time::Zero;
    bossTime = sf::Time::Zero;
    font.loadFromFile("/Users/fjm/Git/Fighters/Resources/Arial Black.ttf");
    gameMusic.openFromFile("/Users/fjm/Git/Fighters/Resources/game_music.wav");
    gameOverMusic.openFromFile("/Users/fjm/Git/Fighters/Resources/game_over.wav");
    enemyDownBuffer.loadFromFile("/Users/fjm/Git/Fighters/Resources/enemy0_down.wav");
    enemyDownSound.setBuffer(enemyDownBuffer);
    playerDownBuffer.loadFromFile("/Users/fjm/Git/Fighters/Resources/player_down.wav");
    playerDownSound.setBuffer(playerDownBuffer);
    pause = 0;
    timee = 1;
    gameMenu.inMenu = 1;
}

void Game::run() {
    sf::Clock clock;
    sf::Time time = sf::Time::Zero;
    sf::Time Time = sf::seconds(1.f/60.f);
    sf::Time dTime;
    gameMusic.play();
//    boss.bossComing = 1;
    while (mWindow.isOpen()) {
        processEvents();
        dTime = clock.getElapsedTime();
        if (!pause && !boss.WIN && !player.GameOver && !gameMenu.inMenu) gameTime += dTime;
        if (boss.bossTime) bossTime += dTime;
        time += clock.restart();
        while (time > Time) {
            time -= Time;
            processEvents();
            update(Time);
        }
        render();
    }
    gameOverMusic.stop();
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mWindow.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            handlePlayerInput(event.key.code, 1);
        }
        if (event.type == sf::Event::KeyReleased) {
            handlePlayerInput(event.key.code, 0);
        }
    }
}

void Game::update(sf::Time time) {
    background.move(time);
    if (boss.WIN || player.GameOver || pause) return;
    player.move(time);
    if (reward.alive) reward.move(time);
    if (!boss.bossComing) {
        enemy.creatEnemy(gameTime);
        if (gameTime.asMilliseconds() > rewardTimeInterval * timee) {
            timee ++;
            reward.setKind();
        }
    }
    enemy.shoot(gameTime);
    enemy.move(time);
    checkCrash();
    if (boss.bossTime) {
        boss.move(time);
        boss.shoot(bossTime, player);
    }
    else {
        if (boss.bossComing) {
            bool flag = 1;
            for (int i = 0; i < enemy.numOfEnemys; i++) {
                if (enemy.enemys[i].aliveCondition || enemy.enemys[i].shot.isAlive) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                boss.bossTime = 1;
            }
        }
    }
}

void Game::render() {
    mWindow.clear();
    mWindow.draw(background.background[0]);
    mWindow.draw(background.background[1]);
    if (gameMenu.inMenu) {
        mWindow.draw(gameMenu.getTitleText());
        mWindow.draw(gameMenu.getSelector());
        mWindow.draw(gameMenu.getStartText());
        mWindow.draw(gameMenu.getRankText());
        mWindow.draw(gameMenu.getQuitText());
        mWindow.display();
        return;
    }
    if (pause) {
        player.menu.setData(player.damage, player.speed, player.life);
        mWindow.draw(player.menu.getDamageText());
        mWindow.draw(player.menu.getSpeedText());
        mWindow.draw(player.menu.getLifeText());
        mWindow.draw(player.menu.getTitleText());
        mWindow.display();
        return;
    }
    if (player.GameOver) {
        gameMusic.stop();
        gameOverMusic.play();
        sf::Text over,toMenu;
        over.setFont(font);
        over.setCharacterSize(45);
        over.setString("Game Over");
        over.setPosition((windowWidth - over.getLocalBounds().width)/2, (windowHeight - over.getLocalBounds().height)/2 - 50);
        mWindow.draw(over);
        toMenu.setFont(font);
        toMenu.setString("ENTER to Menu");
        toMenu.setCharacterSize(25);
        toMenu.setPosition((windowWidth - toMenu.getLocalBounds().width)/2, (windowHeight - toMenu.getLocalBounds().height)/2 + 50);
        mWindow.draw(toMenu);
        mWindow.display();
        return;
    }
    if (boss.WIN) {
        sf::Text win,toMenu;
        win.setFont(font);
        win.setString("YOU WIN!!");
        win.setCharacterSize(45);
        win.setPosition((windowWidth - win.getLocalBounds().width)/2, (windowHeight - win.getLocalBounds().height)/2 - 50);
        mWindow.draw(win);
        toMenu.setFont(font);
        toMenu.setString("ENTER to Menu");
        toMenu.setCharacterSize(25);
        toMenu.setPosition((windowWidth - toMenu.getLocalBounds().width)/2, (windowHeight - toMenu.getLocalBounds().height)/2 + 50);
        mWindow.draw(toMenu);
        mWindow.display();
        return;
    }
    mWindow.draw(score.score);
    if (damageUP) {
        damageUP --;
        sf::Text damageUp;
        damageUp.setFont(font);
        damageUp.setCharacterSize(20);
        damageUp.setString("damage up");
        damageUp.setFillColor(sf::Color::Black);
        sf::Vector2f posPlayer = player.Plane.getPosition();
        damageUp.setPosition(posPlayer.x + player.rect.x / 2 - damageUp.getLocalBounds().width / 2, posPlayer.y - 50);
        mWindow.draw(damageUp);
    }
    if (speedUP) {
        speedUP --;
        sf::Text speedUp;
        speedUp.setFont(font);
        speedUp.setCharacterSize(20);
        speedUp.setString("speed up");
        speedUp.setFillColor(sf::Color::Black);
        sf::Vector2f posPlayer = player.Plane.getPosition();
        speedUp.setPosition(posPlayer.x + player.rect.x / 2 - speedUp.getLocalBounds().width / 2, posPlayer.y - 50);
        mWindow.draw(speedUp);
    }
    if (lifeUP) {
        lifeUP --;
        sf::Text lifeUp;
        lifeUp.setFont(font);
        lifeUp.setCharacterSize(20);
        lifeUp.setString("life up");
        lifeUp.setFillColor(sf::Color::Black);
        sf::Vector2f posPlayer = player.Plane.getPosition();
        lifeUp.setPosition(posPlayer.x + player.rect.x / 2 - lifeUp.getLocalBounds().width / 2, posPlayer.y - 50);
        mWindow.draw(lifeUp);
    }
    if (player.aliveCondition) {
        if ((player.inviolable && (player.inviolable/8) % 2) || !player.inviolable) mWindow.draw(player.Plane);
        if (player.inviolable) player.inviolable --;
    }
    if (reward.alive) mWindow.draw(reward.reward);
    for (int i = 0; i < numOfShots; i++) {
        if (player.shots[i].isAlive) {
            mWindow.draw(player.shots[i].shot);
        }
    }
    for (int i = 0; i < enemy.numOfEnemys; i++) {
        if (enemy.enemys[i].aliveCondition) {
            mWindow.draw(enemy.enemys[i].enemyPlane);
        }
    }
    for (int i = 0; i < enemy.numOfEnemys; i++) {
        if (enemy.enemys[i].shot.isAlive) {
            mWindow.draw(enemy.enemys[i].shot.shot);
        }
    }
    for (int i = 1; i <= player.life; i++) {
        heart.heart.setPosition(windowWidth - i * (20 + heart.getRect().x), 20);
        mWindow.draw(heart.heart);
    }
    if (boss.bossTime) {
        mWindow.draw(boss.Plane);
        for (int i = 0; i < numOfBossShots; i++) {
            if (boss.shots[i].isAlive) {
                mWindow.draw(boss.shots[i].shot);
            }
        }
    }
    mWindow.display();
}

void Game::reStart() {
    gameTime = sf::Time::Zero;
    bossTime = sf::Time::Zero;
    score.updateScore(0);
    player.reStart();
    enemy.reStart();
    boss.reStart();
    gameMusic.play();
    timee = 1;
    pause = 0;
    gameMenu.inMenu = 1;
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (gameMenu.inMenu) {
        if (key == sf::Keyboard::Up || key == sf::Keyboard::Down || key == sf::Keyboard::Return) {
            if (isPressed) {
                int k = gameMenu.setEvent(key);
                if (k == 1) gameMenu.inMenu = 0;
                if (k == 2) {}//输出排行榜
                if (k == 3) mWindow.close();
            }
        }
        return;
    }
    if (key == sf::Keyboard::Up || key == sf::Keyboard::Down || key == sf::Keyboard::Left || key == sf::Keyboard::Right) {
        player.setMove(key,isPressed);
    }
    if (key == sf::Keyboard::Space) {
        player.shoot(isPressed);
    }
    if (key == sf::Keyboard::Return) {
        if (player.GameOver || boss.WIN) {
            reStart();
        }
    }
    if (key == sf::Keyboard::Tab) {
        if (isPressed) pause = !pause;
    }
}

bool Game::isCollsion(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
    if (x1 >= x2 && x1 >= x2 + w2) return 0;
    if (x1 <= x2 && x1 + w1 <= x2) return 0;
    if (y1 >= y2 && y1 >= y2 + h2) return 0;
    if (y1 <= y2 && y1 + h1 <= y2) return 0;
    return 1;
}

void Game::checkCrash() {
    for (int i = 0; i < enemy.numOfEnemys; i++) {
        if (enemy.enemys[i].aliveCondition != 1) continue;
        for (int j = 0; j < numOfShots; j++) {
            if (!player.shots[j].isAlive) continue;
            sf::Vector2f posEnemy = enemy.enemys[i].enemyPlane.getPosition();
            sf::Vector2f posShot = player.shots[j].shot.getPosition();
            if (isCollsion(posEnemy.x, posEnemy.y, enemy.enemys[i].rect.x, enemy.enemys[i].rect.y, posShot.x, posShot.y, player.shots[j].rect.x, player.shots[j].rect.y)) {
                enemy.enemys[i].HP -= player.damage;
                if (enemy.enemys[i].HP <= 0) {
                    enemy.enemys[i].down(1);
                    enemyDownSound.play();
                    score.updateScore(10);
                }
                player.shots[j].isAlive = 0;
                if (score.getScore() > scoreBossComing) {
                    boss.bossComing = 1;
                }
                break;
            }
        }
    }
    if (boss.bossTime) {
        if (boss.aliveCondition == 1) {
            for (int i = 0; i < numOfShots; i++) {
                if (!player.shots[i].isAlive) continue;
                sf::Vector2f posBoss = boss.Plane.getPosition();
                sf::Vector2f posShot = player.shots[i].shot.getPosition();
                if (isCollsion(posBoss.x, posBoss.y, boss.rect.x, boss.rect.y, posShot.x, posShot.y, player.shots[i].rect.x, player.shots[i].rect.y)) {
                    boss.HP -= player.damage;
                    if (boss.HP <= 0) {
                        boss.down(1);
                    }
                    player.shots[i].isAlive = 0;
                    break;
                }
            }
        }
    }
    if (player.aliveCondition != 1) return;
    if (reward.alive) {
        sf::Vector2f posPlayer = player.Plane.getPosition();
        sf::Vector2f posReward = reward.reward.getPosition();
        if (isCollsion(posPlayer.x, posPlayer.y, player.rect.x, player.rect.y, posReward.x, posReward.y, reward.rect.x, reward.rect.y)) {
            reward.alive = 0;
            if (reward.getKind() == 0) {
                player.damage ++;
                damageUP = 10;
            }
            if (reward.getKind() == 1) {
                player.life ++;
                lifeUP = 10;
            }
            if (reward.getKind() == 2) {
                player.speed += 50;
                speedUP = 10;
            }
        }
    }
    if (player.inviolable) return;
    if (player.aliveCondition != 1) return;
    for (int i = 0; i < enemy.numOfEnemys; i++) {
        if (enemy.enemys[i].aliveCondition != 1) continue;
        sf::Vector2f posPlayer = player.Plane.getPosition();
        sf::Vector2f posEnemy = enemy.enemys[i].enemyPlane.getPosition();
        if (isCollsion(posPlayer.x, posPlayer.y, player.rect.x, player.rect.y, posEnemy.x, posEnemy.y, enemy.enemys[i].rect.x, enemy.enemys[i].rect.y)) {
                enemy.enemys[i].down(1);
                playerDownSound.play();
                player.down(1);
                break;
        }
    }
    if (player.aliveCondition != 1) return;
    for (int i = 0; i < enemy.numOfEnemys; i++) {
        if (enemy.enemys[i].shot.isAlive) {
            sf::Vector2f posPlayer = player.Plane.getPosition();
            sf::Vector2f posShot = enemy.enemys[i].shot.shot.getPosition();
            if (isCollsion(posPlayer.x, posPlayer.y, player.rect.x, player.rect.y, posShot.x, posShot.y, enemy.enemys[i].shot.rect.x, enemy.enemys[i].shot.rect.y)) {
                    enemy.enemys[i].shot.isAlive = 0;
                    playerDownSound.play();
                    player.down(1);
                    break;
            }
        }
    }
    if (player.aliveCondition != 1) return;
    for (int i = 0; i < numOfBossShots; i++) {
        if (boss.shots[i].isAlive) {
            sf::Vector2f posPlayer = player.Plane.getPosition();
            sf::Vector2f posShot = boss.shots[i].shot.getPosition();
            if (isCollsion(posPlayer.x, posPlayer.y, player.rect.x, player.rect.y, posShot.x, posShot.y, boss.shots[i].rect.x, boss.shots[i].rect.y)) {
                boss.shots[i].isAlive = 0;
                playerDownSound.play();
                player.down(1);
                break;
            }
        }
    }
    if (player.aliveCondition != 1) return;
    if (boss.bossTime) {
        sf::Vector2f posBoss = boss.Plane.getPosition();
        sf::Vector2f posPlayer = player.Plane.getPosition();
        if (isCollsion(posPlayer.x, posPlayer.y, player.rect.x, player.rect.y, posBoss.x, posBoss.y, boss.rect.x, boss.rect.y)) {
            playerDownSound.play();
            player.down(1);
        }
    }
}
