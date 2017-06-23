//
//  Game.h
//  Fighters
//
//  Created by Jimmy Fan on 2017/5/15.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Enemys.h"
#include "Score.h"
#include "Heart.h"
#include "Boss.h"
#include "Reward.h"
#include "Background.h"
#include "GameMenu.h"
#define rewardTimeInterval 8000
#define scoreBossComing 200

class Game {
private:
    sf::Music gameMusic;
    sf::Music gameOverMusic;
    sf::SoundBuffer enemyDownBuffer;
    sf::Sound enemyDownSound;
    sf::SoundBuffer playerDownBuffer;
    sf::Sound playerDownSound;
    sf::Font font;
    sf::RenderWindow mWindow;
    sf::Time gameTime;
    sf::Time bossTime;
    Score score;
    Player player;
    Enemys enemy;
    Heart heart;
    Boss boss;
    Background background;
    Reward reward;
    GameMenu gameMenu;
    int damageUP, speedUP, lifeUP;
    int timee;
    bool pause;
    void processEvents();
    void update(sf::Time time);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void checkCrash();
    void reStart();
    bool isCollsion(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
public:
    Game();
    void run();
};


#endif /* Game_h */
