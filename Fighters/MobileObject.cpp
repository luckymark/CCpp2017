#include <SFML/Graphics.hpp>
#include <cmath>
#include <list>
#include "MobileObject.h"

MobileObject::MobileObject(const sf::Texture &tex, const float &posx, const float &posy, const sf::Vector2f &dir, const float &speed){
    sprite = sf::Sprite(tex);
    sprite.setPosition(posx, posy);
    p = sf::Vector2f(posx + tex.getSize().x / 2.0,
                     posy + tex.getSize().y / 2.0);
    this->dir = dir;
    this->speed = speed;
}

void MobileObject::move(const float &dx, const float &dy){
    sprite.move(dx, dy);
    p+=sf::Vector2f(dx, dy);
}

void MobileObject::move(){
    float dir_l = sqrt(dir.x * dir.x + dir.y * dir.y);
    move(dir.x / dir_l * speed, dir.y / dir_l * speed);
}
