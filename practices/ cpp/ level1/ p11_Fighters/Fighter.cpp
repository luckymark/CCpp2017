#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<windows.h>
#include<time.h>
#define move_speed_my_aircraft 5
#define move_speed_my_missle 3
#define move_speed_enemy_aircraft 1.5
#define move_speed_enemy_missile 2
#define window_lenth 1920
#define window_width 1020

void move_aircraft(sf::Sprite &duixiang)
{
    sf::Vector2f now_position=duixiang.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&(now_position.x>53.25)){
    duixiang.move(-move_speed_my_aircraft, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&(now_position.x<window_lenth-53.25)){
    duixiang.move(move_speed_my_aircraft, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&(now_position.y>75)){
    duixiang.move(0, -move_speed_my_aircraft);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&(now_position.y<window_width-75)){
    duixiang.move(0, move_speed_my_aircraft);
    }
}
//飞机类
class AIRCRAFT{
public:
    sf::Texture tex_aircraft;
    sf::Sprite aircraft;
    };
//导弹类
class MISSILE{
public:
    sf::Texture tex_missile;
    sf::Sprite missile;
    };
//我方战机类
class MY_AIRCRAFT:public AIRCRAFT
{
public:
    MY_AIRCRAFT()
    {
       if (!tex_aircraft.loadFromFile("my_aircraft.jpg")){
    // error...
}
aircraft.setTexture(tex_aircraft);
aircraft.setOrigin(106.5,150);
aircraft.setPosition(960,930);
aircraft.setScale(0.5f,0.5f);
    }
};
//我方导弹类
class MY_MISSILE:public MISSILE
{
public:
    int if_exist=0;
    MY_MISSILE()
    {
if (!tex_missile.loadFromFile("missile.jpg")){
    // error...
}
missile.setTexture(tex_missile);
missile.setOrigin(62.5,62.5);
missile.setScale(0.3f,0.3f);
    }
};
//敌机类
class ENEMY_AIRCRAFT:public AIRCRAFT
{
public:
    int index=0;
    int if_exist=0;
    ENEMY_AIRCRAFT()
    {
        if (!tex_aircraft.loadFromFile("enemy_aircraft.png")){
    // error...
}
aircraft.setTexture(tex_aircraft);
aircraft.setOrigin(147,134);
aircraft.setScale(0.4f,0.4f);
    }
};
//敌机导弹类
class ENEMY_MISSILE:public MISSILE
{
public:
    int if_begin_move=0;
    int index=0;
    int if_exist=0;
    ENEMY_MISSILE()
    {
        if (!tex_missile.loadFromFile("missile.jpg")){
    // error...
}
missile.setTexture(tex_missile);
missile.setOrigin(62.5,62.5);
missile.setScale(0.3f,0.3f);
    }
};
int main()
{
    //播放背景音乐
    sf::Music music;
    if (!music.openFromFile("Sight.wav")){
    return -1;
    }
    music.setVolume(10);
    music.play();
    music.setLoop(true);
    sf::Clock clock1;
    MY_MISSILE my_missile[50];
    ENEMY_AIRCRAFT enemy_aircraft[30];
    ENEMY_MISSILE enemy_missile[30];
    int between_time,enemy_number;
    int if_my_aircraft_exist;
    int your_life=3;
    int your_blood_number;
    sf::RenderWindow window(sf::VideoMode(window_lenth,window_width), "SFML works!");
    clock_t start_time,finish_time;
    start_time=clock();
    srand(time(0));
    while(your_life>0){
            your_blood_number=300;
    MY_AIRCRAFT *my_aircraft=new (MY_AIRCRAFT);
    if_my_aircraft_exist=1;
    while (window.isOpen()){
            //window.setFramerateLimit(60);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    finish_time=clock();
    between_time=finish_time-start_time;
    if(between_time>6000){
       enemy_number=rand()%3+1;
            for(int j=0;j<30;j++){
                if((0==enemy_aircraft[j].if_exist)&&(0==enemy_missile[j].if_exist)){
                enemy_aircraft[j].if_exist=1;
                enemy_aircraft[j].index=rand()%window_lenth+1;
                enemy_aircraft[j].aircraft.setPosition(enemy_aircraft[j].index,0);
                enemy_missile[j].index=(rand()%window_width+1)/2;
                enemy_missile[j].missile.setPosition(enemy_aircraft[j].index,enemy_missile[j].index);
                enemy_number--;
                if(0==enemy_number){
                    break;
                }
            }
        }
    start_time=finish_time;
    }
    move_aircraft(my_aircraft->aircraft);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        sf::Time elapsed = clock1.getElapsedTime();
        clock1.restart();
        if(elapsed.asSeconds()>0.05){
            for(int i=0;i<50;i++){
                if(0==my_missile[i].if_exist){
                    my_missile[i].missile.setPosition(my_aircraft->aircraft.getPosition());
                    my_missile[i].if_exist=1;
                    break;
                }
            }
        }
    }
    for(int i=0;i<50;i++){
            if(1==my_missile[i].if_exist){
                my_missile[i].missile.move(0,-move_speed_my_missle);
                }
            if(my_missile[i].missile.getPosition().y<-20){
                my_missile[i].if_exist=0;
                }
            }
    for(int j=0;j<30;j++){
        if(enemy_aircraft[j].if_exist==1){
            if((enemy_aircraft[j].aircraft.getPosition().y)>=(enemy_missile[j].index)){
                enemy_missile[j].if_begin_move=1;
            }
        }
            if((1==enemy_missile[j].if_begin_move)&&(enemy_missile[j].missile.getPosition().y<window_width)){
                enemy_missile[j].if_exist=1;
                enemy_missile[j].missile.move(0,move_speed_enemy_missile);
        }
            if(1==enemy_aircraft[j].if_exist){
                enemy_aircraft[j].aircraft.move(0,move_speed_enemy_aircraft);
        }
            if(enemy_aircraft[j].if_exist==1){
                if(enemy_aircraft[j].aircraft.getPosition().y>window_width){
                    enemy_aircraft[j].if_exist=0;
            }
        }
            if(1==enemy_missile[j].if_begin_move){
                if(enemy_missile[j].missile.getPosition().y>=window_width){
                    enemy_missile[j].if_exist=0;
                    enemy_missile[j].if_begin_move=0;
            }
        }
}
    window.clear(sf::Color::White);
    window.draw(my_aircraft->aircraft);
    for(int i=0;i<50;i++){
        if(1==my_missile[i].if_exist){
            window.draw(my_missile[i].missile);
        }
    }
    for(int j=0;j<30;j++){
        if(1==enemy_aircraft[j].if_exist){
            window.draw(enemy_aircraft[j].aircraft);
        }
        if(1==enemy_missile[j].if_exist){
            window.draw(enemy_missile[j].missile);
        }
    }



    sf::VertexArray quad(sf::Quads,4);
    quad[0].position=sf::Vector2f(10,10);
    quad[1].position=sf::Vector2f(10+your_blood_number,10);
    quad[2].position=sf::Vector2f(10+your_blood_number,60);
    quad[3].position=sf::Vector2f(10,60);
    quad[0].color=sf::Color::Red;
    quad[1].color=sf::Color::Red;
    quad[2].color=sf::Color::Red;
    quad[3].color=sf::Color::Red;
    window.draw(quad);

    for(int i=0;i<50;i++){
        for(int j=0;j<30;j++){
            if((1==my_missile[i].if_exist)&&(1==enemy_aircraft[j].if_exist)){
                sf::FloatRect boundingBox1 = enemy_aircraft[j].aircraft.getGlobalBounds();
                sf::FloatRect boundingBox2 = my_missile[i].missile.getGlobalBounds();
                if(boundingBox1.intersects(boundingBox2)){
                    my_missile[i].if_exist=0;
                    enemy_aircraft[j].if_exist=0;
                }
            }
        }
    }
    sf::FloatRect boundingBox3 = my_aircraft->aircraft.getGlobalBounds();
    for(int j=0;j<30;j++){
        if(1==enemy_aircraft[j].if_exist){
            sf::FloatRect boundingBox1 = enemy_aircraft[j].aircraft.getGlobalBounds();
            if(boundingBox3.intersects(boundingBox1)){

                enemy_aircraft[j].if_exist=0;
                your_blood_number-=20;
                break;
            }
        }

    }
            for(int j=0;j<30;j++){
                if(1==enemy_missile[j].if_exist){
            sf::FloatRect boundingBox2 = enemy_missile[j].missile.getGlobalBounds();
            if(boundingBox2.intersects(boundingBox3)){
            enemy_missile[j].if_exist=0;
            enemy_missile[j].if_begin_move=0;
            enemy_missile[j].index=window_lenth;
                your_blood_number-=10;
                break;
            }
        }
            }
            if(your_blood_number<=0){
                if_my_aircraft_exist=0;
            }
    if(0==if_my_aircraft_exist){
            for(int j=0;j<30;j++){
                enemy_aircraft[j].if_exist=0;
                enemy_missile[j].if_exist=0;
                enemy_missile[j].if_begin_move=0;
            }
      window.clear(sf::Color::White);
      window.display();
      Sleep(3000);
      break;
    }
    window.display();
}
        }
    return 0;
}
