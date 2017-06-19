#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/window.hpp>
#include "ResourcePath.hpp"
#include "Menu.h"
#include "Back.h"
#include "Lyric.h"
#include "Bar.h"
#include "Ship.h"
#include "Bullet.h"
#include "BGM.h"

/*

STATE: 0:main menu
       1:game
           1:little
           2:big
           3:2big
           4:boss
       2:pause
       3:dead
       4:rank
       6:help
       7:story
*/


float min(float a,float b) {
    if(a<=b) return a;
    return b;
}
float max(float a,float b) {
    if(a>=b) return a;
    return b;
}
void initial_game() {
    
}


int main()
{
    //prepare
    srand((unsigned)time(0));
    int width=1000,height=1500;
    sf::RenderWindow window(sf::VideoMode(width,height),"CODK",sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    Menu menu;
    Bar bar;
    Lyric lyrics;
    BGM bgm_game("game"),bgm_pause("pause"),bgm_menu("menu"),bgm_win("win");\
    const int all_cloud=12;
    sf::Image icon;
    icon.loadFromFile(resourcePath()+"using/icon.png");
    window.setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());
    sf::RectangleShape blur;
    blur.setSize(sf::Vector2f(1000,1600));
    blur.setFillColor(sf::Color(220,220,220,150));
    Back *cloud[all_cloud],*cloudb[all_cloud];
    for(int i=0;i<all_cloud;i++) {
        cloud[i]=new Back(std::to_string(i+1));
        cloudb[i]=new Back("b"+std::to_string(i+1),1);
    }
    Ship ship1("1");
    const int all_ship2=50,all_ship3=50,all_umbrella=10;
    Ship *ship2[all_ship2];
    for(int i=0;i<all_ship2;i++) ship2[i]=new Ship("2");
    Ship *ship3[all_ship3];
    for(int i=0;i<all_ship3;i++) ship3[i]=new Ship("3");
    Ship *umbrella[all_umbrella];
    for(int i=0;i<all_umbrella;i++) umbrella[i]=new Ship("4");
    Ship boss_ship("5");
  
    
    //GAME LOOP
    while(window.isOpen()) {
        sf::Event event;
        float x,y;
        int gap=200,gap1=160,state=0,gamestate=0,cloud_possibility=1000,life1,life2;
        bool fire1=0,mouse=0,mid=0;
        sf::Clock ship2_gap,ship3_gap,boss_gap,quick_fire1,protect_clock;
        float ship2_gap0=0,ship3_gap0=0,boss_gap0=0,quick_fire10=0,protect_clock0=0,r=205,g=210,b=215;
        while(true) {
            window.pollEvent(event);
            window.clear(sf::Color(r,g,b));
            
            if(event.type==sf::Event::MouseMoved) {
                x=max(min(event.mouseMove.x,930),58);
                y=max(min(event.mouseMove.y,1295),120);
                
            }
            
            //cloud
            int type=rand()%cloud_possibility;
            type=rand()%(4*cloud_possibility);
            if(type<all_cloud) {
                cloudb[type]->load();
            }
            for(int i=0;i<all_cloud;i++) {
                cloudb[i]->draw(&window);
            }
            if(type<all_cloud) {
                cloud[type]->load();
            }
            for(int i=0;i<all_cloud;i++) {
                cloud[i]->draw(&window);
            }
            if(boss_ship.in_position) {
                for(int i=0;i<all_cloud;i++) {
                    cloudb[i]->state=2;
                    cloud[i]->state=2;
                }
            }
            
            //quit
            if(event.type==sf::Event::Closed) {
                window.close();
                break;
            }
            
            //menu
            if(state==0) {
                mid=0;
                bgm_game.reseting();
                bgm_win.reseting();
                //bgm_pause.reseting();
                gamestate=0;
                boss_ship.total_reset();
                for(int i=0;i<all_cloud;i++) {
                    cloud[i]->state=0;
                    cloudb[i]->state=0;
                }
                cloud_possibility=1000;
                //bgm_game.stop();
                bgm_pause.stop();
                bgm_menu.restart();
                menu.main_check_mouse(x,y);
                if(event.type==sf::Event::MouseButtonReleased) {
                    state=menu.state;
                    
                    //initial in game settings
                    if(state==1) {
                        mouse=0;
                        fire1=0;
                        //clocks
                        ship2_gap.restart();
                        ship2_gap0=0;
                        ship3_gap.restart();
                        ship3_gap0=0;
                        boss_gap.restart();
                        boss_gap0=0;
                        quick_fire1.restart();
                        quick_fire10=0;
                        protect_clock.restart();
                        protect_clock0=0;
                        ship1.total_reset();
                        for(int i=0;i<50;i++) {
                            ship1.bullet_right[i]->active=0;
                            ship1.bullet_left[i]->active=0;
                            ship1.shell[i]->active=0;
                        }
                        for(int i=0;i<all_ship2;i++){
                            ship2[i]->total_reset();
                            for(int j=0;j<50;j++) {
                                ship2[i]->bullet_mid[j]->active=0;
                            }
                            ship2[i]->clock.restart();
                            ship2[i]->clock0=0;
                        }
                        for(int i=0;i<all_ship3;i++) {
                            ship3[i]->total_reset();
                            for(int j=0;j<50;j++) {
                                ship3[i]->bullet_mid[j]->active=0;
                                ship3[i]->bullet_left[j]->active=0;
                                ship3[i]->bullet_right[j]->active=0;
                            }
                            ship3[i]->clock.restart();
                            ship3[i]->clock0=0;
                        }
                        boss_ship.total_reset();
                        for(int j=0;j<50;j++) {
                            boss_ship.bullet_mid[j]->active=0;
                        }
                        for(int i=0;i<all_umbrella;i++) {
                            umbrella[i]->total_reset();
                        }
                        bar.total_clock.restart();
                        bar.total_clock0=0;
                        bar.reset();
                    }
                }
                
                
                
                menu.draw_main_menu(&window);
                
                
                
                
            }
            
            //pause
            else if(state==2) {
                for(int i=0;i<all_cloud;i++) {
                    cloud[i]->state=0;
                    cloudb[i]->state=0;
                }
                cloud_possibility=1000;
                bgm_game.pause();
                bgm_pause.restart();
                menu.pause_check_mouse(x,y);
                if(event.type==sf::Event::MouseButtonReleased) {
                    state=menu.state;
                    
                    //update in game clock
                    if(state==1) {
                        mouse=0;
                        //clock
                        ship2_gap.restart();
                        ship3_gap.restart();
                        boss_gap.restart();
                        quick_fire1.restart();
                        protect_clock.restart();
                        for(int i=0;i<all_ship2;i++) ship2[i]->clock.restart();
                        for(int i=0;i<all_ship3;i++) ship3[i]->clock.restart();
                        boss_ship.clock.restart();
                        bar.total_clock.restart();
                    }
                }
                if (event.type==sf::Event::KeyReleased and event.key.code==sf::Keyboard::Escape) {
                    state=1;
                    ship2_gap.restart();
                    ship3_gap.restart();
                    boss_gap.restart();
                    quick_fire1.restart();
                    protect_clock.restart();
                    for(int i=0;i<all_ship2;i++) ship2[i]->clock.restart();
                    for(int i=0;i<all_ship3;i++) ship3[i]->clock.restart();
                    boss_ship.clock.restart();
                    bar.total_clock.restart();
                }
                
                
                
                for(int i=0;i<all_umbrella;i++) {
                    umbrella[i]->draw_ship(&window);
                }
                for(int i=0;i<all_ship2;i++) {
                    ship2[i]->draw__bullets(&window);
                    ship2[i]->draw_ship(&window);
                }
                for(int i=0;i<all_ship3;i++) {
                    ship3[i]->draw_ship(&window);
                    ship3[i]->draw__bullets(&window,x,y);
                }
                ship1.draw__bullets(&window);
                boss_ship.draw_ship(&window);
                boss_ship.draw__bullets(&window);
                ship1.draw_ship(&window);
                window.draw(blur);
                menu.draw_pause_menu(&window);
            }
            
            //dead
            else if(state==3) {
                for(int i=0;i<all_cloud;i++) {
                    cloud[i]->state=0;
                    cloudb[i]->state=0;
                }
                cloud_possibility=1000;
                menu.final_score=bar.final_score;
                bgm_game.stop();
                bgm_pause.restart();
                menu.dead_check_mouse(x,y);
                if(event.type==sf::Event::MouseButtonReleased) {
                    state=menu.state;
                }
                //type in
                if(event.type==sf::Event::KeyReleased) {
                    if(event.key.code==sf::Keyboard::A) menu.typein='A';
                    else if(event.key.code==sf::Keyboard::B) menu.typein='B';
                    else if(event.key.code==sf::Keyboard::C) menu.typein='C';
                    else if(event.key.code==sf::Keyboard::D) menu.typein='D';
                    else if(event.key.code==sf::Keyboard::E) menu.typein='E';
                    else if(event.key.code==sf::Keyboard::F) menu.typein='F';
                    else if(event.key.code==sf::Keyboard::G) menu.typein='G';
                    else if(event.key.code==sf::Keyboard::H) menu.typein='H';
                    else if(event.key.code==sf::Keyboard::I) menu.typein='I';
                    else if(event.key.code==sf::Keyboard::J) menu.typein='J';
                    else if(event.key.code==sf::Keyboard::K) menu.typein='K';
                    else if(event.key.code==sf::Keyboard::L) menu.typein='L';
                    else if(event.key.code==sf::Keyboard::M) menu.typein='M';
                    else if(event.key.code==sf::Keyboard::N) menu.typein='N';
                    else if(event.key.code==sf::Keyboard::O) menu.typein='O';
                    else if(event.key.code==sf::Keyboard::P) menu.typein='P';
                    else if(event.key.code==sf::Keyboard::Q) menu.typein='Q';
                    else if(event.key.code==sf::Keyboard::R) menu.typein='R';
                    else if(event.key.code==sf::Keyboard::S) menu.typein='S';
                    else if(event.key.code==sf::Keyboard::T) menu.typein='T';
                    else if(event.key.code==sf::Keyboard::U) menu.typein='U';
                    else if(event.key.code==sf::Keyboard::V) menu.typein='V';
                    else if(event.key.code==sf::Keyboard::W) menu.typein='W';
                    else if(event.key.code==sf::Keyboard::X) menu.typein='X';
                    else if(event.key.code==sf::Keyboard::Y) menu.typein='Y';
                    else if(event.key.code==sf::Keyboard::Z) menu.typein='Z';
                    else if(event.key.code==sf::Keyboard::BackSpace) {
                        menu.pop_back();
                        goto jump;
                    }
                    else menu.typein="";
                    menu.type_react();
                jump:;
                }
                menu.updated=0;
                for(int i=0;i<all_umbrella;i++) {
                    umbrella[i]->draw_ship(&window);
                }
                for(int i=0;i<all_ship2;i++) {
                    ship2[i]->draw__bullets(&window);
                    ship2[i]->draw_ship(&window);
                }
                for(int i=0;i<all_ship3;i++) {
                    ship3[i]->draw_ship(&window);
                    ship3[i]->draw__bullets(&window,x,y);
                }
                ship1.draw__bullets(&window);
                boss_ship.draw_ship(&window);
                boss_ship.draw__bullets(&window);
                ship1.draw_ship(&window);
                window.draw(blur);
                menu.draw_dead_menu(&window);
                bar.draw_dead_score(&window);
                
                
                
                
            }
            
            //rank
            else if(state==4) {
                for(int i=0;i<all_cloud;i++) {
                    cloud[i]->state=0;
                    cloudb[i]->state=0;
                }
                cloud_possibility=1000;
                menu.rank_check_mouse(x,y);
                if(event.type==sf::Event::MouseButtonReleased) {
                    state=menu.state;
                }
                menu.draw_rank_menu(&window);
            }

            //game
            else if(state==1) {
                for(int i=0;i<all_cloud;i++) {
                    if(boss_ship.in_position) {
                        cloud[i]->state=2;
                        cloudb[i]->state=2;
                    }
                    else {
                        cloud[i]->state=1;
                        cloudb[i]->state=1;
                    }
                    
                }
                cloud_possibility=300;
                bgm_menu.stop();
                bgm_pause.stop();
                if(gamestate!=4){
                    bgm_game.play();
                }
                bar.final_score=-1;
                //pause setting
                if (event.type==sf::Event::KeyReleased and event.key.code==sf::Keyboard::Escape and gamestate!=4) {
                    ship2_gap0+=ship2_gap.getElapsedTime().asSeconds();
                    ship3_gap0+=ship3_gap.getElapsedTime().asSeconds();
                    boss_gap0+=boss_gap.getElapsedTime().asSeconds();
                    quick_fire10+=quick_fire1.getElapsedTime().asSeconds();
                    protect_clock0+=protect_clock.getElapsedTime().asSeconds();
                    for(int i=0;i<all_ship2;i++) ship2[i]->clock0+=ship2[i]->clock.getElapsedTime().asSeconds();
                    for(int i=0;i<all_ship3;i++) ship3[i]->clock0+=ship3[i]->clock.getElapsedTime().asSeconds();
                    boss_ship.clock0+=boss_ship.clock.getElapsedTime().asSeconds();
                    bar.total_clock0+=bar.total_clock.getElapsedTime().asSeconds();
                    
                    
                    ////////
                    state=2;
                }
                
                
                
                
                life1=bar.life;
                
                //ship 1 position
                if(mouse) ship1.body.setPosition(x,y);
                else if(ship1.body.getGlobalBounds().contains(x,y)) mouse=1;
                
                //fire 1 switch
                if(event.type == sf::Event::MouseButtonReleased) fire1^=1;
                
                //fire 1 gap control
                if(ship1.active and fire1 and ship1.clock.getElapsedTime().asMilliseconds()>gap1) {
                    ship1.clock.restart();
                    ship1.load_bullet(ship1.body.getPosition().x,ship1.body.getPosition().y);
                }
                
                //skill release
                if(event.type==sf::Event::KeyReleased and bar.promote>0) {
                    //quick shoot
                    if (event.key.code==sf::Keyboard::Num1 and gap1!=60) {
                        gap1=60;
                        quick_fire1.restart();
                        quick_fire10=0;
                        bar.promote--;
                    }//shell 1
                    else if (event.key.code==sf::Keyboard::Num2) {
                        ship1.load_shell(ship1.body.getPosition().x,ship1.body.getPosition().y);
                        bar.promote--;
                    }//protection
                    else if(event.key.code==sf::Keyboard::Num3 and !ship1.protect_active) {
                        ship1.load_protect();
                        protect_clock.restart();
                        protect_clock0=0;
                        bar.promote--;
                    }
                }
                
                //skill control
                if(quick_fire1.getElapsedTime().asSeconds()+quick_fire10>=4) gap1=160;
                if(ship1.protect_active) ship1.check_protect(protect_clock.getElapsedTime().asSeconds()+protect_clock0);
                
                //wether fire 1 shoot on target
                for(int i=0;i<all_ship2;i++) {
                    //ship 2
                    float harm1=ship1.bullet_left[0]->harm;
                    float reward2=ship2[0]->reward;
                    if(ship2[i]->active) {
                        if(ship1.bullet_check_left(ship2[i]->body.getGlobalBounds())) {
                            ship2[i]->blood-=harm1;
                            if(ship2[i]->blood<=0){
                                bar.kill2++;
                                bar.update_skill(reward2);
                                ship2[i]->reset();
                            }
                        }
                        if(ship1.bullet_check_right(ship2[i]->body.getGlobalBounds())) {
                            ship2[i]->blood-=harm1;
                            if(ship2[i]->blood<=0){
                                bar.kill2++;
                                bar.update_skill(reward2);
                                ship2[i]->reset();
                            }
                        }
                        //dying
                        if(ship2[i]->blood<=0) ship2[i]->reset();
                    }
                    //ship 3
                    float reward3=ship3[0]->reward;
                    if(ship3[i]->active) {
                        if(ship1.bullet_check_left(ship3[i]->body.getGlobalBounds())) {
                            ship3[i]->blood-=harm1;
                            if(ship3[i]->blood<=0){
                                bar.kill3++;
                                bar.update_skill(reward3);
                                ship3[i]->reset();
                            }
                        }
                        if(ship1.bullet_check_right(ship3[i]->body.getGlobalBounds())) {
                            ship3[i]->blood-=harm1;
                            if(ship3[i]->blood<=0){
                                bar.kill3++;
                                bar.update_skill(reward3);
                                ship3[i]->reset();
                            }
                        }
                        //dying
                        if(ship3[i]->blood<=0) ship3[i]->reset();
                    }
                    
                }
                //boss ship
                if(boss_ship.in_position and bar.blood and boss_ship.transparent>150) {
                    if(ship1.boss_check_left(boss_ship.body.getPosition().x,boss_ship.body.getPosition().y)) {
                        bar.update_boss(1.5);
                        boss_ship.blood-=1.5;
                        if(bar.boss_health_now<0){
                            bar.kill3++;
                            boss_ship.reset();
                        }
                        bar.bossr+=1.5;
                    }
                    if(ship1.boss_check_right(boss_ship.body.getPosition().x,boss_ship.body.getPosition().y)) {
                        bar.update_boss(1.5);
                        boss_ship.blood-=1.5;
                        if(bar.boss_health_now<0){
                            bar.kill3++;
                            boss_ship.reset();
                        }
                        bar.bossr+=1.5;
                    }
                }
                //dying boss
                if(bar.boss_health_now<=0) boss_ship.reset();
                //umbrella
                for(int i=0;i<all_umbrella;i++) {
                    if(umbrella[i]->active) {
                        if(ship1.bullet_check_left(umbrella[i]->body.getGlobalBounds())) {
                            umbrella[i]->blood=0;
                            if(umbrella[i]->blood<=0) umbrella[i]->reset();
                        }
                        if(ship1.bullet_check_right(umbrella[i]->body.getGlobalBounds())) {
                            umbrella[i]->blood=0;
                            if(umbrella[i]->blood<=0) umbrella[i]->reset();
                        }
                        //dying
                        if(umbrella[i]->blood<=0) umbrella[i]->reset();
                    }
                }
                
                
                
                //wether collected umbrella
                for(int i=0;i<all_umbrella;i++) {
                    if(ship1.body.getGlobalBounds().intersects(umbrella[i]->body.getGlobalBounds()) and !umbrella[i]->collected) {
                        umbrella[i]->blood=0;
                        umbrella[i]->reset();
                        bar.life++;
                    }
                }
                
                //wether shell 1 shoot on target
                float sharm1=ship1.shell[0]->harm;
                for(int i=0;i<all_ship2;i++) {
                    //ship 2
                    float sreward2=ship2[0]->reward;
                    if(ship2[i]->active) {
                        if(ship1.shell_check(ship2[i]->body.getGlobalBounds())) {
                            ship2[i]->blood-=sharm1;
                            if(ship2[i]->blood<=0){
                                bar.update_skill(sreward2);
                                ship2[i]->reset();
                            }
                        }
                    }
                    //ship 3
                    float sreward3=ship3[0]->reward;
                    if(ship3[i]->active) {
                        if(ship1.shell_check(ship3[i]->body.getGlobalBounds())) {
                            ship3[i]->blood-=sharm1;
                            if(ship3[i]->blood<=0){
                                bar.update_skill(sreward3);
                                ship3[i]->reset();
                            }
                        }
                    }
                }
                //umbrella
                int i=0;
                if(umbrella[i]->active) {
                    if(ship1.shell_check(umbrella[i]->body.getGlobalBounds())) {
                        umbrella[i]->blood=0;
                        if(umbrella[i]->blood<=0){
                            umbrella[i]->reset();
                        }
                    }
                }
                //boss ship
                if(boss_ship.in_position and bar.blood and boss_ship.transparent>150) {
                    if(ship1.boss_shell_check(boss_ship.body.getPosition().x,boss_ship.body.getPosition().y)) {
                        boss_ship.blood-=1.5*sharm1;
                        bar.update_boss(1.5*sharm1);
                        if(boss_ship.blood<=0){
                            bar.kill3++;
                            boss_ship.reset();
                        }
                        bar.bossr+=30;
                    }
                }
                
                
                
                
                //wether ship1 is shooted
                if(ship1.active) {
                    if(!ship1.protect_active) {
                        //fire 2
                        float harm2=ship2[0]->bullet_mid[0]->harm;
                        for(int i=0;i<all_ship2;i++) {
                            if(ship2[i]->bullet_check_mid(ship1.body.getGlobalBounds())) {
                                ship1.blood-=harm2;
                                bar.update_health(harm2);
                            }
                        }
                        //fire 3
                        float harm3=ship3[0]->bullet_mid[0]->harm;
                        for(int i=0;i<all_ship3;i++) {
                            if(ship3[i]->bullet_check_mid(ship1.body.getGlobalBounds())) {
                                ship1.blood-=harm3;
                                bar.update_health(harm3);
                            }
                            if(ship3[i]->bullet_check_left(ship1.body.getGlobalBounds())) {
                                ship1.blood-=harm3;
                                bar.update_health(harm3);
                            }
                            if(ship3[i]->bullet_check_right(ship1.body.getGlobalBounds())) {
                                ship1.blood-=harm3;
                                bar.update_health(harm3);
                            }
                        }
                        //fire n...
                        
                        //  fire
                        float harm5=boss_ship.bullet_mid[0]->harm;
                        if(boss_ship.bullet_check_mid(ship1.body.getGlobalBounds())) {
                            ship1.blood-=harm5;
                            bar.update_health(harm5);
                        }

                    }
                }
                
                //wether missed ship2
                for(int i=0;i<all_ship2;i++) {
                    float y2=ship2[i]->body.getPosition().y;
                    if(y2>=1700 and ship2[i]->blood>0){
                        ship1.blood-=ship2[i]->blood/2.0;
                        bar.update_health(ship2[i]->blood);
                        ship2[i]->blood=0;
                    }
                }
                
                //wether missed ship3
                for(int i=0;i<all_ship3;i++) {
                    float y3=ship3[i]->body.getPosition().y;
                    if(y3>=1700 and ship3[i]->blood>0){
                        ship1.blood-=ship3[i]->blood/2.0;
                        bar.update_health(ship3[i]->blood);
                        ship3[i]->blood=0;
                    }
                }
                
                
                
                
                //ship 2 gap control
                float addition=(bar.total_clock.getElapsedTime().asSeconds()+bar.total_clock0)/500;
                float real_gap2=max(0.2,1.2-addition);
                if(ship2_gap.getElapsedTime().asSeconds()+ship2_gap0>real_gap2 and (gamestate==0 or gamestate==1 or gamestate==2)) {
                    ship2_gap.restart();
                    ship2_gap0=0;
                    int i=0;
                    while(ship2[i]->active) i++;
                    ship2[i]->active=1;
                }
                
                //fires 2 gap control
                for(int i=0;i<all_ship2;i++) {
                    if(ship2[i]->active and ship2[i]->clock.getElapsedTime().asMilliseconds()+ship2[i]->clock0>8*gap) {
                        ship2[i]->clock.restart();
                        ship2[i]->clock0=0;
                        ship2[i]->load_bullet(ship2[i]->body.getPosition().x,ship2[i]->body.getPosition().y);
                    }
                }
                
                //ship 3 gap control
                addition=(bar.total_clock.getElapsedTime().asSeconds()+bar.total_clock0)/100;
                float real_gap3=min(5,10-addition);
                if(ship3_gap.getElapsedTime().asSeconds()+ship3_gap0>real_gap3 and (gamestate==1 or gamestate==2)) {
                    ship3_gap.restart();
                    ship3_gap0=0;
                    int i=0;
                    while(ship3[i]->active) i++;
                    ship3[i]->active=1;
                    if(gamestate==2) {
                        int i=0;
                        while(ship3[i]->active) i++;
                        ship3[i]->active=1;
                    }
                    
                }
                
                //fires 3 gap control
                for(int i=0;i<all_ship3;i++) {
                    if(ship3[i]->active and ship3[i]->clock.getElapsedTime().asMilliseconds()+ship3[i]->clock0>15*gap) {
                        ship3[i]->clock.restart();
                        ship3[i]->clock0=0;
                        ship3[i]->load_bullet(ship3[i]->body.getPosition().x,ship3[i]->body.getPosition().y);
                    }
                }
                
                //boss fire control
                int random;
                if(boss_ship.active and boss_ship.in_position) {
                    bar.boss=1;
                    if(boss_ship.transparent>150) {
                        if(rand()%100==0) {
                            boss_ship.load_bullet(boss_ship.body.getPosition().x,boss_ship.body.getPosition().y);
                        }
                    }
                    if(boss_ship.transparent<=50 and boss_gap0+boss_gap.getElapsedTime().asSeconds()>3){
                        random=rand()%3;
                        if(random==0) {
                            int i=0;
                            for(int i=0;i<9;i++) {
                                i=0;
                                while(ship2[i]->active) i++;
                                ship2[i]->active=1;
                                ship2[i]->speed2=4-(abs(i-4))/2.0;
                                ship2[i]->body.setPosition(100*(i+1),-20);
                            }
                        }
                        else if(random==1) {
                            int i=0;
                            for(int i=0;i<3;i++) {
                                i=0;
                                while(ship3[i]->active) i++;
                                ship3[i]->active=1;
                                ship3[i]->speed3=2-(abs(i-1))/2.0;
                                ship3[i]->body.setPosition(400*i+100,-50);
                            }
                        }
                        boss_gap.restart();
                    }
                }
                
                //umbrella possibility control
                if(rand()%1500==0 and gamestate!=4) {
                    int i=0;
                    while(umbrella[i]->active) i++;
                    umbrella[i]->active=1;
                }
                
                
                //revive or die
                life2=bar.life;
                if(life1>life2) {
                    std::cout<<1;
                    ship1.reseting=1;
                }
                if(ship1.reseting) {
                    std::cout<<2;
                    if(bar.life>=1) ship1.reset();
                    else ship1.reset(1);
                }
                if(!ship1.active and bar.life<1) state=3;
                if(!ship1.active and bar.life>=1 and !ship1.reviving){
                    std::cout<<3;
                    ship1.reviving=1;
                    ship1.load_protect();
                    protect_clock.restart();
                    protect_clock0=8;
                }
                if(ship1.reviving){
                    std::cout<<4;
                    mouse=0;
                    ship1.revive();
                }
                
                
                //game state control
                
                float time=bar.total_clock.getElapsedTime().asSeconds()+bar.total_clock0;
                if(time<=25) gamestate=0;
                else if(time<=95) gamestate=1;
                else if(time<=123) gamestate=2;
                else if(time<130) {
                    gamestate=3;
                    boss_ship.active=1;
                }
                else if(boss_ship.active==0){
                    gamestate=4;
                    
                }
                if(mid==0) {
                    lyrics.mid();
                    mid=1;
                }
                //winning congratulation
                if(gamestate==4) {
                    bgm_game.go();
                    lyrics.draw(&window);
                    lyrics.move();
                    lyrics.change();
                    if(lyrics.start()) {
                        bgm_win.play();
                        if(bgm_win.clock.getElapsedTime().asSeconds()>110) {
                            if(bgm_win.go()) {
                                state=3;
                            }
                        }
                    }
                }
                
                
                
                //show
                for(int i=0;i<all_umbrella;i++) {
                    umbrella[i]->move();
                    umbrella[i]->draw_ship(&window);
                }
                for(int i=0;i<all_ship2;i++) {
                    ship2[i]->draw_bullets(&window);
                    ship2[i]->move();
                    ship2[i]->draw_ship(&window);
                }
                for(int i=0;i<all_ship3;i++) {
                    ship3[i]->draw_ship(&window);
                    ship3[i]->move();
                    ship3[i]->draw_bullets(&window,ship1.body.getPosition().x,ship1.body.getPosition().y);
                }
                
                ship1.draw_ship(&window);
                ship1.draw_bullets(&window);
                boss_ship.move();
                boss_ship.color();
                
                boss_ship.draw_ship(&window);
                boss_ship.draw_bullets(&window,ship1.body.getPosition().x,ship1.body.getPosition().y);
                
                
                
                
                
                bar.draw(&window);
                
                
                
            }
            
            //story
            else if(state==7) {
                for(int i=0;i<all_cloud;i++) {
                    cloud[i]->state=0;
                    cloudb[i]->state=0;
                }
                cloud_possibility=1000;
                menu.story_check_mouse(x,y);
                if(event.type==sf::Event::MouseButtonReleased) {
                    state=menu.state;
                }
                menu.draw_story_menu(&window);
            }
            
            //help
            else if(state==6) {
                for(int i=0;i<all_cloud;i++) {
                    cloud[i]->state=0;
                    cloudb[i]->state=0;
                }
                cloud_possibility=1000;
                menu.help_check_mouse(x,y);
                if(event.type==sf::Event::MouseButtonReleased) {
                    state=menu.state;
                }
                menu.draw_help_menu(&window);
            }
           
            
            
            window.display();
            event.type=sf::Event::KeyPressed;
        }
    }
    return 0;
}
