#include <string>
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
    int LEVEL=1;
    int score_temp=0;
    int score_time;
    int positionExplosion_x;
    int positionExplosion_y;
    int level_1=1300;
    int transparency=40;
    int ui_score_temp;
    bool ui_score_temp_onOff=0;
    int music_over_temp=0;


    sf::RenderWindow window(sf::VideoMode(1600, 900), "Fighters!",sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    srand(time(0));
    Plane myPlane;
    sf::Event event;
    sf::Mouse mouse;
    //****************************************ui
    sf::Font font;

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
    ui_score.setString("Score :");

    sf::Text ui_LEVEL;                       //ui_level
    ui_LEVEL.setFont(font);
    ui_LEVEL.setCharacterSize(40);
    ui_LEVEL.setFillColor(sf::Color::Black);
    ui_LEVEL.setPosition(1220,230);
    ui_LEVEL.setString("Level :");
    sf::Text ui_LEVEL_count;
    ui_LEVEL_count.setFont(font);
    ui_LEVEL_count.setCharacterSize(40);
    ui_LEVEL_count.setFillColor(sf::Color::Black);
    ui_LEVEL_count.setPosition(1380,226);

    sf::RectangleShape ui_over(sf::Vector2f(1600,900));  //ui_over_png
    sf::Sprite ui_over_sprite;
    sf::Texture ui_over_texture;
    ui_over_texture.loadFromFile("game_over.png");
    ui_over_sprite.setTexture(ui_over_texture);
    ui_over_sprite.setPosition(600,899);
    sf::Text ui_over_score;                                //ui_over_score
    ui_over_score.setFont(font);
    ui_over_score.setCharacterSize(50);
    ui_over_score.setFillColor(sf::Color::Black);
    ui_over_score.setPosition(570,899);
    ui_over_score.setString("Your Score :");
    sf::Text ui_over_scoreClock;
    ui_over_scoreClock.setFont(font);
    ui_over_scoreClock.setCharacterSize(45);
    ui_over_scoreClock.setFillColor(sf::Color::Black);
    ui_over_scoreClock.setPosition(870,899);




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
    music.setVolume(50);
    music.setLoop(true);
    sf::Music music_over;
    music_over.openFromFile("game_music.wav");
    music_over.setLoop(true);
    music_over.setVolume(50);
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
    sf::Clock clock_level;
    sf::Clock clock_transparency;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if(mouse.getPosition().x>900&&mouse.getPosition().x<1200&&mouse.getPosition().y>578&&mouse.getPosition().y<614&&myPlane.explosion_status==4)
            {
                if (mouse.isButtonPressed(mouse.Left))
                {
                    window.close();
                }
            }
        }
        if(clock_level.getElapsedTime().asSeconds()>15) //*********************control_level
        {
            LEVEL++;
            level_1-=100;
            for(int i=0;i<30;i++)
            {
                enemyPlane[i].level_enemyPlane+=1;
                for(int j=0;j<50;j++)
                {
                    enemyPlane[i].enemyfire[j].level_enemyShoot+=2;
                }
            }
            clock_level.restart();
        }
        window.clear();
        window.draw(rectangle);


        score_time=score_clock.getElapsedTime().asSeconds()+score_temp;
        if(myPlane.explosion_status==4&&ui_score_temp_onOff==0)
        {
            ui_score_temp=score_time;
            ui_score_temp_onOff=1;
        }
        ui_score_clock.setString(myPlane.int_to_string(score_time));
        ui_LEVEL_count.setString(myPlane.int_to_string(LEVEL));
        ui_over.setFillColor(sf::Color(217,217,217,transparency));



        myPlane.moveShoot(&window);
        myPlane.movePlane();


        for(int i=0;i<30;i++)  //control Plane
        {
            if(enemyPlane[i].enemyPlane.active==0&&clock_enemyPlane.getElapsedTime().asMilliseconds()>level_1)
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

                if(enemyPlane[i].sprite_enemyPlane.getPosition().y>899)
                {
                    myPlane.HP--;
                }
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
                            score_temp+=10;
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
        if((myPlane.HP>0||myPlane.HP==0)&&myPlane.myPlane_status==0)
        {
            window.draw(myPlane.sprite);
        }else
        {
            if(myPlane.myPlane_status==0)
            {
                myPlane.explosion_status=1;
                myPlane.myPlane_status=1;

            }
        }
        myPlane.explosion(myPlane.sprite.getPosition().x,myPlane.sprite.getPosition().y);
        switch (myPlane.explosion_status) //draw myPlane_explosion
        {
            case 1 :window.draw(myPlane.sprite_myPlaneExplosion1);
            myPlane.controlExplosion();
            soundExplosion_2.play();
            break;
            case 2 :window.draw(myPlane.sprite_myPlaneExplosion2);
            myPlane.controlExplosion();
            break;
            case 3 :window.draw(myPlane.sprite_myPlaneExplosion3);
            myPlane.controlExplosion();
            break;
            case 4 :window.draw(myPlane.sprite_myPlaneExplosion4);
            myPlane.controlExplosion();
            break;
        }
        if(myPlane.myPlane_status)
        {
            myPlane.HP=0;
        }

        if(myPlane.explosion_status==4&&transparency<245&&clock_transparency.getElapsedTime().asMilliseconds()>80)
        {
            transparency+=10;
            clock_transparency.restart();

        }
        if(ui_over_sprite.getPosition().y>460&&myPlane.explosion_status==4)
        {

            ui_over_sprite.move(0,-2);

        }
        if(ui_over_score.getPosition().y>380&&myPlane.explosion_status==4)
        {
            ui_over_score.move(0,-3.5);
            ui_over_scoreClock.move(0,-3.5);
        }
        if(myPlane.explosion_status==4&&music_over_temp==0)
        {
            music.stop();
            music_over.play();
            music_over_temp=1;
        }
        ui_liveHP.setString(myPlane.int_to_string(myPlane.HP));
        ui_over_scoreClock.setString(myPlane.int_to_string(ui_score_temp));
        window.draw(line,2,sf::Lines);
        window.draw(ui_spriteLive);
        window.draw(ui_liveHP);
        window.draw(X_shape);
        window.draw(ui_score);
        window.draw(ui_score_clock);
        window.draw(ui_LEVEL);
        window.draw(ui_LEVEL_count);
        if(myPlane.explosion_status==4)
        {
            window.draw(ui_over);
            window.draw(ui_over_sprite);
            window.draw(ui_over_score);
            window.draw(ui_over_scoreClock);
        }
        window.display();
    }
    return 0;
}


