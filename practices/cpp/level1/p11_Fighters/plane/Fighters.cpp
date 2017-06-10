#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Fire.h"
#include "Plane.h"
#include "EnemyPlane.h"


int main()
{
    int positionExplosion_x;
    int positionExplosion_y;

    sf::RenderWindow window(sf::VideoMode(1600, 900), "Fighters!",sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    srand(time(0));
    Plane myPlane;
    //****************************************ui
    sf::Font font;
    sf::Event event;
    font.loadFromFile("msyh.ttf");

    sf::Text ui_liveHP;
    ui_liveHP.setFont(font);
    ui_liveHP.setCharacterSize(50);
    ui_liveHP.setFillColor(sf::Color::Black);
    ui_liveHP.setPosition(1400,40);
                                            //ui_score
    sf::Text ui_score;
    ui_score.setFont(font);
    ui_score.setCharacterSize(50);
    ui_score.setFillColor(sf::Color::Black);
    ui_score.setPosition(1220,150);
    sf::Text ui_score_clock;
    ui_score_clock.setFont(font);
    ui_score_clock.setCharacterSize(40);
    ui_score_clock.setFillColor(sf::Color::Black);
    ui_score_clock.setPosition(1400,155);

    sf::RectangleShape ui_line(sf::Vector2f());
    sf::Sprite X_shape;
    sf::Texture X_texture;
    X_texture.loadFromFile("X.png");
    X_shape.setTexture(X_texture);
    X_shape.setPosition(1320,45);
    EnemyPlane enemyPlane[30];

    sf::RectangleShape rectangle(sf::Vector2f(1600,900));
    rectangle.setFillColor(sf::Color(217,217,217));

    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(1200, 0)),
        sf::Vertex(sf::Vector2f(1200, 900))
    };
    line[0].color=sf::Color::Red;
    line[1].color=sf::Color::Black;
    sf::Sprite ui_spriteLive;
    sf::Texture ui_textureLive;
    ui_textureLive.loadFromFile("plane.png");
    ui_spriteLive.setTexture(ui_textureLive);
    ui_spriteLive.setPosition(1220,40);
    ui_spriteLive.setScale(1.0f,1.0f);
    ui_spriteLive.scale(0.5f,0.5f);
    sf::Vector2f scale=ui_spriteLive.getScale();
    //**************************************************************************
    myPlane.loadPlane();
    myPlane.loadShoot();
    sf::Clock clock_enemyPlane;
    //*******************************************************************************music
    sf::Music music;
    music.openFromFile("Saints Row The Third.wav");
    music.play();
    music.setVolume(20);
    music.setLoop(true);
    //*******************************************************************************explosion
    sf::SoundBuffer explosion_soundBuffer_1;
    sf::Sound soundExplosion_1;
    sf::SoundBuffer explosion_soundBuffer_2;
    sf::Sound soundExplosion_2;
    explosion_soundBuffer_1.loadFromFile("enemy1_down.wav");
    explosion_soundBuffer_2.loadFromFile("enemy2_down.wav");
    soundExplosion_1.setBuffer(explosion_soundBuffer_1);
    soundExplosion_2.setBuffer(explosion_soundBuffer_2);

    sf::Clock score_clock;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                 window.close();
            }
        }
        window.clear();
        window.draw(rectangle);

        ui_liveHP.setString(myPlane.int_to_string(myPlane.HP));
        ui_score_clock.setString(myPlane.int_to_string(score_clock.getElapsedTime().asMilliseconds()));
        ui_score.setString("Score :");

        myPlane.moveShoot(&window);
        myPlane.movePlane();


        for(int i=0;i<30;i++)  //control Plane
        {
            if(enemyPlane[i].enemyPlane.active==0&&clock_enemyPlane.getElapsedTime().asMilliseconds()>2000)
            {
                enemyPlane[i].on_off();
                clock_enemyPlane.restart();
                enemyPlane[i].clock_enemyFire.restart();
                break;
            }
        }
        for(int i=0;i<30;i++)  //control enemyFire
        {
            if(enemyPlane[i].enemyPlane.active==1&&enemyPlane[i].clock_enemyFire.getElapsedTime().asMilliseconds()>1700)
            {
                for (int j=0;j<50;j++)
                {
                    if(enemyPlane[i].enemyfire[j].enemy_active==0)
                    {
                        enemyPlane[i].enemyfire[j].on_off();
                        enemyPlane[i].enemyfire[j].load_enemyFire(enemyPlane[i].sprite_enemyPlane.getPosition().x+26,
                                                     enemyPlane[i].sprite_enemyPlane.getPosition().y+30);
                        enemyPlane[i].clock_enemyFire.restart();
                        break;
                    }
                }
            }
        }
        for(int i=0;i<30;i++)   //move
        {
            if(enemyPlane[i].enemyPlane.active==1)
            {
                enemyPlane[i].move_enemyPlane();
            }
            for (int j=0;j<50;j++)
            {
                if(enemyPlane[i].enemyfire[j].enemy_active==1)
                {
                    enemyPlane[i].enemyfire[j].move_enemyShoot();
                }
            }
        }

        //*********************************************************************************//

        for(int i=0;i<30;i++)   //check collision
        {
            if(enemyPlane[i].enemyPlane.active==1)
            {
                for (int j=0;j<100;j++)
                {
                    if(myPlane.bullet[j].active==1)
                    {
                        if(myPlane.spriteShoot[j].getGlobalBounds().intersects(enemyPlane[i].sprite_enemyPlane.getGlobalBounds()))
                        {

                            enemyPlane[i].explosion_status=1;
                            positionExplosion_x=enemyPlane[i].sprite_enemyPlane.getPosition().x;
                            positionExplosion_y=enemyPlane[i].sprite_enemyPlane.getPosition().y;
                            enemyPlane[i].reset();
                            myPlane.bullet[j].active=0;
                        }
                    }
                }
            }
            for (int k=0;k<50;k++)
            {
                if(enemyPlane[i].enemyfire[k].enemy_active==1)
                {
                    if(enemyPlane[i].enemyfire[k].sprite_enemyFire.getGlobalBounds().intersects(myPlane.sprite.getGlobalBounds()))
                    {
                        myPlane.HP--;
                        enemyPlane[i].enemyfire[k].enemy_active=0;
                    }
                }
            }
        }

        for(int i=0;i<30;i++)
        {
            enemyPlane[i].explosion(positionExplosion_x,positionExplosion_y);
        }
        for(int i=0;i<30;i++)   //draw
        {
            if(enemyPlane[i].enemyPlane.active==1)
            {
                window.draw(enemyPlane[i].sprite_enemyPlane);
            }
            switch (enemyPlane[i].explosion_status) //draw explosion
            {
                case 1 :window.draw(enemyPlane[i].spriteExplosion1);
                enemyPlane[i].controlExplosion();
                soundExplosion_1.play();
                break;
                case 2 :window.draw(enemyPlane[i].spriteExplosion2);
                //soundExplosion_2.play();
                enemyPlane[i].controlExplosion();
                break;
                case 3 :window.draw(enemyPlane[i].spriteExplosion3);
                enemyPlane[i].controlExplosion();
                break;
                case 4 :window.draw(enemyPlane[i].spriteExplosion4);
                enemyPlane[i].controlExplosion();
                break;
            }
            for (int j=0;j<50;j++)
            {
                if(enemyPlane[i].enemyfire[j].enemy_active==1)
                {
                    window.draw(enemyPlane[i].enemyfire[j].sprite_enemyFire);
                }
            }
        }
        if(myPlane.HP>0)
        {
            window.draw(myPlane.sprite);
        }else
        {

        }
        window.draw(line,2,sf::Lines);
        window.draw(ui_spriteLive);
        window.draw(ui_liveHP);
        window.draw(X_shape);
        window.draw(ui_score);
        window.draw(ui_score_clock);
        window.display();
    }
    return 0;
}


