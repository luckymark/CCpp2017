#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <list>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "GlobalDefinitions.h"
#include "TextBoard.h"
#include "ScoreBoard.h"
#include "MobileObject.h"
#include "Ship.h"
#include "SpaceShip.h"
#include "Console.h"

extern sf::SoundBuffer shooted_ogg, self_bomb_wav;
extern sf::Texture enemy_pic[5], spaceship_pic_global, boss_pic[7];

void Console::init_window(){
    window = new sf::RenderWindow(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "SFML window");
    window->setVerticalSyncEnabled(true);
}

void Console::init_texts(){
    title = new TextBoard(TITLE);
    declaration = new TextBoard(DECLARATION);
    text_begin = new TextBoard(TEXTBEGIN);
    text_lost = new TextBoard(TEXTLOST);
    text_win = new TextBoard(TEXTWIN);
    life_point_recovered = new TextBoard(L_P_R);
    weapon_upgraded = new TextBoard(WEAPONUPGRADED);
    sparkle_dynamite = new TextBoard(SPARKLEDYNAMITE);
    upgrade_left = new TextBoard(UPGRADELEFT);
    elite_coming = new TextBoard(ELITECOMING);
    flagship_coming = new TextBoard(FLAGSHIPCOMING);
    boss_coming = new TextBoard(BOSSCOMING);
    ac_left = new TextBoard(ACLEFT);
    pac_left = new TextBoard(PACLEFT);
    speed_up = new TextBoard(SPEEDUP);
    bullet_acceralated = new TextBoard(BULLETACCELERATED);
}

void Console::init_scoreboard(){
    scoreboard = new ScoreBoard();
}

void Console::init_pictures(){
    boss_pic[0].loadFromFile("boss1.png");
    boss_pic[1].loadFromFile("boss2.png");
    boss_pic[2].loadFromFile("boss3.png");
    boss_pic[3].loadFromFile("boss4.png");
    boss_pic[4].loadFromFile("boss5.png");
    boss_pic[5].loadFromFile("boss6.png");
    boss_pic[6].loadFromFile("boss7.png");

    spaceship_pic_global.loadFromFile("spaceship1.png");

    pill_pic.loadFromFile("pill.png");

    enemy_pill_pic.loadFromFile("enemy_pill.png");

    enemy_pic[0].loadFromFile("enemy.png");
    enemy_pic[1].loadFromFile("enemy_bomb_1_blue.png");
    enemy_pic[2].loadFromFile("enemy_bomb_2_blue.png");
    enemy_pic[3].loadFromFile("enemy_bomb_3_blue.png");
    enemy_pic[4].loadFromFile("enemy_bomb_4.png");

    background_pic.loadFromFile("background.png");

    box_pic[0].loadFromFile("box_cure.png");
    box_pic[1].loadFromFile("box_weapon.png");
    box_pic[2].loadFromFile("box_dynamite.png");
    box_pic[3].loadFromFile("box_ac.png");
    box_pic[4].loadFromFile("box_pill_ac.png");

    pill_great_pic.loadFromFile("weapon2.png");
}

void Console::init_musics_and_sounds(){
    weapon2_wav.loadFromFile("weapon2.wav");
    bullet_ogg.loadFromFile("bullet.ogg");
    shooted_ogg.loadFromFile("enemy1_down.ogg");
    self_bomb_wav.loadFromFile("self_bomb.wav");

    bullet_sound.setBuffer(bullet_ogg);
    weapon2_sound.setBuffer(weapon2_wav);
    bgm.openFromFile("game_music.ogg");
    bgm.setVolume(10);
    bgm.setLoop(true);
    lost_music.openFromFile("lost.ogg");
    lost_music.setVolume(10);
    warning_music.openFromFile("warning.wav");
//    warning_music.setVolume(40);
    reward_music.openFromFile("reward.wav");
//    reward_music.setVolume(40);
    win_music.openFromFile("win.wav");
}

Console::Console(){
    last_change_charsize = clock();

    stage = 1;

    dynamited = 1;

    is_box = 0;

    ended = 0;

    pills.clear();
    enemy_pills.clear();
    enemys.clear();

    srand(time(0));
    init_window();
    init_texts();
    init_scoreboard();
    init_pictures();
    spaceship = new SpaceShip(spaceship_pic_global, sf::Color(254, 254, 65), 189, SPACESHIPMAXY, sf::Vector2f(0.0, 0.0), 2.0 , PILLRANGE);
    background = new sf::Sprite(background_pic);
    background->setColor(sf::Color(128, 64, 0));
    background2 = new sf::Sprite(background_pic);
    background2->setColor(sf::Color::Yellow);
    init_musics_and_sounds();

    bgm.play();
    last_enemy = clock();
    enemy_range = rand()%1000 + ENEMYRANGE;
    box_range = 3000;
    last_upgrade = clock() - 20100;
    last_ac = clock() - 20100;
    last_pill_ac = clock() - 20100;

    last_boss = clock() - BOSSRANGE - 5000;
    boss_range = rand()%5000 + BOSSRANGE;
}

Console::~Console(){
    pills.clear();
    enemy_pills.clear();
    enemys.clear();
    delete window;
    delete scoreboard;
    delete spaceship;
    delete background;
}

void Console::make_enemy(){
    if(clock() - last_enemy > enemy_range){
        int tmp = rand() % (WINDOWWIDTH - enemy_pic[0].getSize().x);
        sf::Color co = sf::Color(255, 0, 0); int hp = 1; int type = 1;
        if(scoreboard->cur_score > STAGE1 && scoreboard->cur_score <= STAGE2){
            co = sf::Color::Green; hp = 3; type = 2;
        }
        else if(scoreboard->cur_score > STAGE2){
            co = sf::Color(240, 255, 255); hp = 6; type = 3;
        }
        enemys.push_back(Ship(enemy_pic[0], co, tmp, -90, sf::Vector2f(0.0, 1.0), 1.0, 2000, hp, type));
        enemy_range = rand()%1000 + ENEMYRANGE;
        last_enemy = clock();
    }
    if(stage==4 && clock() - last_boss > boss_range){
        int tmp = rand() % (WINDOWWIDTH - boss_pic[0].getSize().x);
        enemys.push_back(Ship(boss_pic[0], sf::Color(142, 254, 122), tmp, -245, sf::Vector2f(0.0, 1.0), 0.3, 1000, 42, 4));
        boss_range = rand()%5000 + BOSSRANGE;
        last_boss = clock();
    }
}

void Console::make_box(){
    if(!is_box && clock() - last_get_box > box_range){
        int tmpx = rand() % (WINDOWWIDTH*2/3) + WINDOWWIDTH/6;
        int tmpy = rand() % (WINDOWHEIGHT*2/3) + WINDOWHEIGHT/6;
        box_type = rand() % 5;
        box = sf::Sprite(box_pic[box_type]);
        box.setPosition(tmpx, tmpy);
        is_box = 1;
    }
}

void Console::solve_input(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        spaceship->set_spaceship_sound();
        if(spaceship->sprite.getPosition().x > 0){
            spaceship->moveB(-spaceship->speed, 0);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        spaceship->set_spaceship_sound();
        if(spaceship->sprite.getPosition().x + spaceship->sprite.getTexture()->getSize().x < WINDOWWIDTH){
            spaceship->moveB(spaceship->speed, 0);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        spaceship->set_spaceship_sound();
        if(spaceship->sprite.getPosition().y > 0){
            spaceship->moveB(0, -spaceship->speed);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        spaceship->set_spaceship_sound();
        if(spaceship->sprite.getPosition().y  < SPACESHIPMAXY){
            spaceship->moveB(0, spaceship->speed);
        }
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        spaceship->spaceship_sound.stop();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && spaceship->can_shoot()){
        if(clock() - last_upgrade > 20000){
            bullet_sound.play();
            spaceship->pill_range = (clock() - last_pill_ac < 20000 ? PILLRANGE / 2 : PILLRANGE);
            float tmpx = spaceship->sprite.getPosition().x + spaceship->sprite.getTexture()->getSize().x / CONSTRATIO_2;
            float tmpy = spaceship->sprite.getPosition().y + spaceship->sprite.getTexture()->getSize().y / CONSTRATIO_4;
            spaceship->shoot(pills, MobileObject(pill_pic, tmpx, tmpy, sf::Vector2f(0, -1), 3.0));

            tmpx = spaceship->sprite.getPosition().x + spaceship->sprite.getTexture()->getSize().x / CONSTRATIO_3;
            spaceship->shoot(pills, MobileObject(pill_pic, tmpx, tmpy, sf::Vector2f(0, -1), 3.0));

            spaceship->create_gun_fires();
        }
        else{
            weapon2_sound.play();
            spaceship->pill_range = (clock() - last_pill_ac < 20000 ? PILLRANGE2 / 2 : PILLRANGE2);
            float tmpx = spaceship->sprite.getPosition().x + spaceship->sprite.getTexture()->getSize().x / CONSTRATIO_6;
            float tmpy = spaceship->sprite.getPosition().y + 0 * spaceship->sprite.getTexture()->getSize().y / CONSTRATIO_4;
            spaceship->shoot(pills, MobileObject(pill_great_pic, tmpx, tmpy, sf::Vector2f(0, -1), 3.0));
        }
    }

    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || clock() - last_upgrade < 20000){
        spaceship->gun_fires.clear();
    }
}

void Console::draw(){
    window->clear();

    if((!ended && clock() - last_ready_dynamite > 550) || (ended && time_condense - last_ready_dynamite > 550)){
        window->draw(*background);
    }
    else{
        window->draw(*background2);
    }
    if((!ended && clock() - last_get_box > box_range) || (ended && time_condense - last_get_box > box_range)){
        window->draw(box);
    }
    for(ITER_B it=enemys.begin(); it!=enemys.end(); ++it){
        if(clock() - it->lastshooted < 50){
            it->sprite.setColor(sf::Color::Blue);
        }
        else{
            if(it->type == 1){
                it->sprite.setColor(sf::Color(255, 0, 0));
            }
            else if(it->type == 2){
                it->sprite.setColor(sf::Color::Green);
            }
            else if(it->type == 3){
                it->sprite.setColor(sf::Color(240, 255, 255));
            }
            else if(it->type == 4){
                it->sprite.setColor(sf::Color(142, 254, 122));
            }
        }
    }
    for(ITER_B it=enemys.begin(); it!=enemys.end(); ++it){
        if(it->type == 4){
            window->draw(it->sprite);
        }
    }
    for(ITER_A it=pills.begin(); it!=pills.end(); ++it){
        window->draw(it->sprite);
    }
    for(ITER_A it=enemy_pills.begin(); it!=enemy_pills.end(); ++it){
        window->draw(it->sprite);
    }
    for(ITER_B it=enemys.begin(); it!=enemys.end(); ++it){
        if(it->type != 4){
            window->draw(it->sprite);
        }
    }
    for(ITER it=spaceship->gun_fires.begin(); it!=spaceship->gun_fires.end(); ++it){
        window->draw(*it);
    }
    window->draw(spaceship->sprite);
    window->draw(*scoreboard->text);
    if(clock() - last_get_box < 2000){
        if(last_type == 0){
            window->draw(*life_point_recovered->text);
        }
        else if(last_type == 1){
            window->draw(*weapon_upgraded->text);
        }
        else if(last_type == 2){
            window->draw(*sparkle_dynamite->text);
        }
        else if(last_type == 3){
            window->draw(*speed_up->text);
        }
        else if(last_type == 4){
            window->draw(*bullet_acceralated->text);
        }
    }
    if((!ended && clock() - last_upgrade < 20000) || (ended && time_condense - last_upgrade < 20000)){
        if(!ended){
            sprintf(upgrade_left->text_s, "Upgrade Time: %d", (20000 - (clock() - last_upgrade)) / 1000);
            upgrade_left->text->setString(upgrade_left->text_s);
        }
        window->draw(*upgrade_left->text);
    }
    if((!ended && clock() - last_ac < 20000) || (ended && time_condense - last_ac < 20000)){
        if(!ended){
            sprintf(ac_left->text_s, "Acceleration Time: %d", (20000 - (clock() - last_ac)) / 1000);
            ac_left->text->setString(ac_left->text_s);
        }
        window->draw(*ac_left->text);
    }
    if((!ended && clock() - last_pill_ac < 20000) || (ended && time_condense - last_pill_ac < 20000)){
        if(!ended){
            sprintf(pac_left->text_s, "Bullet's Acceleration Time: %d", (20000 - (clock() - last_pill_ac)) / 1000);
            pac_left->text->setString(pac_left->text_s);
        }
        window->draw(*pac_left->text);
    }
    if((stage==1 || (stage==2 && clock() - last_change_stage < 2000)) && scoreboard->cur_score >= STAGE1){
        if(elite_coming->text->getCharacterSize() < 48 && clock() - last_change_charsize > 50){
            last_change_charsize = clock();
            elite_coming->text->setCharacterSize(elite_coming->text->getCharacterSize() + 1);
        }
        window->draw(*elite_coming->text);
        if(stage == 1){
            stage=2;
            last_change_stage = clock();
            warning_music.play();
        }
    }
    if((stage==2 || (stage==3 && clock() - last_change_stage < 2000)) && scoreboard->cur_score >= STAGE2){
        if(flagship_coming->text->getCharacterSize() < 48 && clock() - last_change_charsize > 50){
            last_change_charsize = clock();
            flagship_coming->text->setCharacterSize(flagship_coming->text->getCharacterSize() + 1);
        }
        window->draw(*flagship_coming->text);
        if(stage == 2){
            stage=3;
            last_change_stage = clock();
            warning_music.play();
        }
    }
    if((stage==3 || (stage==4 && clock() - last_change_stage < 2000)) && scoreboard->cur_score >= STAGE3){
        if(boss_coming->text->getCharacterSize() < 48 && clock() - last_change_charsize > 50){
            last_change_charsize = clock();
            boss_coming->text->setCharacterSize(boss_coming->text->getCharacterSize() + 1);
        }
        window->draw(*boss_coming->text);
        if(stage == 3){
            stage=4;
            last_change_stage = clock();
            warning_music.play();
        }
    }
    if(ended){
        if(spaceship->status > 3){
            window->draw(*text_lost->text);
        }
        else{
            window->draw(*text_win->text);
        }
    }

    window->display();
}

void Console::update(){
    if(clock() - last_ac < 20000){
        spaceship->speed = 3.0;
    }
    else{
        spaceship->speed = 2.0;
    }
    for(ITER_A it=pills.begin(); it!=pills.end(); ++it){
        it->move();
    }
    for(ITER_A it=enemy_pills.begin(); it!=enemy_pills.end(); ++it){
        it->move();
    }
    for(ITER_B it=enemys.begin(); it!=enemys.end(); ++it){
        it->move();
    }
    for(ITER_A it=pills.begin(); it!=pills.end(); ){
        if(it->sprite.getPosition().y + it->sprite.getTexture()->getSize().y < 0){
            ITER_A jt=it;
            ++it;
            pills.erase(jt);
        }
        else{
            ++it;
        }
    }
    for(ITER_A it=enemy_pills.begin(); it!=enemy_pills.end(); ){
        if(it->sprite.getPosition().y > WINDOWHEIGHT){
            ITER_A jt=it;
            ++it;
            enemy_pills.erase(jt);
        }
        else{
            ++it;
        }
    }
    for(ITER_B it=enemys.begin(); it!=enemys.end(); ){
        if(it->status < 4){
            bool destroyed = 0;
            for(ITER_A kt=pills.begin(); kt!=pills.end(); ){
                if(it->dis(kt->p) <= (it->type!=4 ? CONSTR : CONSTR2)){
                    it->hp -= (clock()-last_upgrade < 20000 ? 6 : 1);
                    if(it->hp <= 0){
                        destroyed = 1;
                    }
                    ITER_A lt = kt;
                    ++kt;
                    pills.erase(lt);
                    it->shooteding();
                }
                else{
                    ++kt;
                }
            }
            if(destroyed && (!it->status)){
                it->bombing();
                it->status = 1;
            }
        }
        if(it->sprite.getPosition().y > WINDOWHEIGHT){
            if(it->status < (it->type!=4 ? 4 : 7)){
                if(scoreboard->cur_life){
                    --scoreboard->cur_life;
                    spaceship->shooteding();
                    if(scoreboard->cur_life == 0){
                        spaceship->bombing();
                        spaceship->status = 1;
                    }
                }
                scoreboard->update();
            }
            ITER_B jt = it;
            ++it;
            enemys.erase(jt);
        }
        else{
            ++it;
        }
    }
    if(clock() - last_ready_dynamite > 500 && !dynamited){
        dynamited = 1;
        for(ITER_B it=enemys.begin(); it!=enemys.end(); ++it){
            if(!it->status){
                it->hp -= 9;
                it->shooteding();
                if(it->hp <= 0){
                    it->bombing();
                    it->status = 1;
                }
            }
        }
    }
    for(ITER_B it=enemys.begin(); it!=enemys.end(); ){
        if(it->status){
            ++it->last;
        }
        if(it->last > CONSTROUNDS){
            it->last = 0;
            ++it->status;
        }
        if(it->status > (it->type!=4 ? 4 : 6)){
            ITER_B jt = it;
            ++it;
            enemys.erase(jt);
            scoreboard->cur_score += (it->type!=4 ? 100 : 1000);
            scoreboard->update();
        }
        else{
            it->sprite.setTexture(it->type!=4 ? enemy_pic[it->status] : boss_pic[it->status]);
            ++it;
        }
    }

    if(spaceship->status <= 3){
        bool destroyed = 0;
        for(ITER_A kt=enemy_pills.begin(); kt!=enemy_pills.end(); ){
            if(spaceship->dis(kt->p) <= CONSTR){
                if(scoreboard->cur_life){
                    --scoreboard->cur_life;
                    if(scoreboard->cur_life <= 0){
                        destroyed = 1;
                    }
                }
                scoreboard->update();
                ITER_A lt = kt;
                ++kt;
                enemy_pills.erase(lt);
                spaceship->shooteding();
                }
                else{
                    ++kt;
                }
        }
        if(destroyed && (!spaceship->status)){
            spaceship->bombing();
            spaceship->status = 1;
        }
    }

    spaceship->update();

    if(spaceship->status > 3){
        ended = 1;
        time_condense = clock();
        bgm.stop();
        lost_music.play();
    }

    if(spaceship->status <=3 && scoreboard->cur_score > IS_WIN){
        ended = 1;
        time_condense = clock();
        bgm.stop();
        win_music.play();
    }

    for(ITER_B it=enemys.begin(); it!=enemys.end(); ++it){
        if(it->type != 4){
            if(!it->status && it->can_shoot() && it->sprite.getPosition().y + it->sprite.getTexture()->getSize().y < spaceship->sprite.getPosition().y){
                it->shoot(enemy_pills, MobileObject(enemy_pill_pic,
                it->sprite.getPosition().x + it->sprite.getTexture()->getSize().x / CONSTRATIO_5,
                it->sprite.getPosition().y + it->sprite.getTexture()->getSize().y + 5.0,
                spaceship->p - it->p, 2));
            }
        }
        else{
            if(!it->status && it->can_shoot() && it->sprite.getPosition().y + it->sprite.getTexture()->getSize().y / CONSTRATIO_8 < spaceship->sprite.getPosition().y){
                it->shoot(enemy_pills, MobileObject(enemy_pill_pic,
                it->sprite.getPosition().x + it->sprite.getTexture()->getSize().x / CONSTRATIO_7,
                it->sprite.getPosition().y + it->sprite.getTexture()->getSize().y / CONSTRATIO_8,
                spaceship->p - it->p, 2));
            }
        }
        it->delete_sounds();
    }

    if(is_box && spaceship->dis(box.getPosition()) < 35.0){
        last_get_box = clock();
        is_box = 0;
        reward_music.play();
        if(box_type == 0){
            scoreboard->cur_life += CONSTHP;
            scoreboard->update();
            last_type = 0;
        }
        else if(box_type == 1){
            last_upgrade = clock();
            last_type = 1;
        }
        else if(box_type == 2){
            last_ready_dynamite = clock();
            dynamited = 0;
            last_type = 2;
        }
        else if(box_type == 3){
            last_ac = clock();
            last_type = 3;
        }
        else if(box_type == 4){
            last_pill_ac = clock();
            last_type = 4;
        }
    }
}

void Console::work(){
    while(window->isOpen()){
        sf::Event event;
        bool flag = 1;
        while(window->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window->close();
            }
            else if(event.type == sf::Event::KeyPressed){
                flag = 0;
                break;
            }
        }
        if(!flag){
            break;
        }
        window->clear();
        window->draw(*background);
        window->draw(*title->text);
        window->draw(*declaration->text);
        window->draw(*text_begin->text);
        window->display();
    }

    last_ready_dynamite = clock() - 560;
    last_get_box = clock() - 2010;

    while(window->isOpen()){
        if(!ended){
            spaceship->reset_spaceship_sound();
            make_enemy();
            make_box();
            solve_input();
        }
        sf::Event event;
        while(window->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window->close();
            }
        }
        draw();
        if(!ended){
            update();
        }
    }
}
