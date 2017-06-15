#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include <deque>
#include <cmath>
#include <ctime>
#include "GlobalDefinitions.h"
#include "MobileObject.h"
#include "Ship.h"
#include "SpaceShip.h"

SpaceShip::SpaceShip(const sf::Texture &tex, const sf::Color &col, const float &posx, const float &posy, const sf::Vector2f &dir, const float &speed, const int &pill_range)
: Ship(tex, col, posx, posy, dir, speed, pill_range){
    gun_fires.clear();
    spaceship_pic[0].loadFromFile("spaceship1.png");
    spaceship_pic[1].loadFromFile("spaceship_bomb_1.png");
    spaceship_pic[2].loadFromFile("spaceship_bomb_2.png");
    spaceship_pic[3].loadFromFile("spaceship_bomb_3.png");
    gun_fire_pic.loadFromFile("test_fire_3.png");
    spaceship_ogg.loadFromFile("big_spaceship_flying.ogg");
    spaceship_sound.setBuffer(spaceship_ogg);
    spaceship_sound_time_tag = sf::milliseconds(1000);
    spaceship_sound_time_tag_2 = sf::milliseconds(2000);
    lastshooted = clock() - 50;
}

SpaceShip::~SpaceShip(){
    gun_fires.clear();
}

void SpaceShip::reset_spaceship_sound(){
    if(spaceship_sound.getPlayingOffset() > spaceship_sound_time_tag_2){
        spaceship_sound.setPlayingOffset(spaceship_sound_time_tag);
    }
}

void SpaceShip::set_spaceship_sound(){
    if(!spaceship_sound.getStatus()){
        spaceship_sound.play();
        spaceship_sound.setPlayingOffset(spaceship_sound_time_tag);
    }
}

void SpaceShip::moveB(const float &dx, const float &dy){
    move(dx, dy);
    for(ITER it=gun_fires.begin(); it!=gun_fires.end(); ++it){
        it->move(dx, dy);
    }
}

void SpaceShip::create_gun_fires(){
    if(gun_fires.empty()){
        gun_fires.push_back(sf::Sprite(gun_fire_pic));
        gun_fires.back().setPosition(
            sprite.getPosition().x + sprite.getTexture()->getSize().x / CONSTRATIO_2,
            sprite.getPosition().y + sprite.getTexture()->getSize().y / (CONSTRATIO_4 - 2.55));

        gun_fires.push_back(sf::Sprite(gun_fire_pic));
        gun_fires.back().setPosition(
            sprite.getPosition().x + sprite.getTexture()->getSize().x / CONSTRATIO_3,
            sprite.getPosition().y + sprite.getTexture()->getSize().y / (CONSTRATIO_4 - 2.55));
    }
}

void SpaceShip::update(){
    if(clock() - lastshooted > 50){
        sprite.setColor(sf::Color(254, 254, 65));
    }
    else{
        sprite.setColor(sf::Color(0, 0, 255));
    }

    if(status){
        ++last;
    }
    if(last > CONSTROUNDS){
        last = 0;
        ++status;
    }
    if(status <= 3){
        sprite.setTexture(spaceship_pic[status]);
    }

    delete_sounds();
}
