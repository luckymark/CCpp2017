#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include <deque>
#include <cmath>
#include "MobileObject.h"
#include "Ship.h"

extern sf::Time self_bomb_sound_time_tag;
extern sf::SoundBuffer shooted_ogg, self_bomb_wav;

Ship::Ship(const sf::Texture &tex, const sf::Color &col, const float &posx, const float &posy, const sf::Vector2f &dir, const float &speed, const int &pill_range, int hp, int type)
: MobileObject(tex, posx, posy, dir, speed){
    this->hp = hp;
    this->type = type;
    shooteds.clear();
    self_bombs.clear();
    sprite.setColor(col);
    status = last = 0;
    lastshoot = clock();
    this->pill_range = pill_range;
    lastshooted = clock() - 50;
}

Ship::~Ship(){
    shooteds.clear();
    self_bombs.clear();
}

float Ship::dis(const sf::Vector2f &p){
    return sqrt((this->p.x - p.x)*(this->p.x - p.x)+
                (this->p.y - p.y)*(this->p.y - p.y));
}

bool Ship::can_shoot(){
    return clock() - lastshoot > pill_range;
}

void Ship::shoot(std::list<MobileObject> &List, const MobileObject &pill){
    List.push_back(pill);
    lastshoot = clock();
}

void Ship::shooteding(){
    shooteds.push_back(sf::Sound());
    shooteds.back().setBuffer(shooted_ogg);
    shooteds.back().play();
    lastshooted = clock();
}

void Ship::bombing(){
    self_bombs.push_back(sf::Sound());
    self_bombs.back().setBuffer(self_bomb_wav);
    self_bombs.back().play();
}

void Ship::delete_sounds(){
    while(!shooteds.empty() && !shooteds.front().getStatus()){
        shooteds.pop_front();
    }
    while(!self_bombs.empty() && self_bombs.front().getPlayingOffset() > self_bomb_sound_time_tag){
        self_bombs.pop_front();
    }
}
