#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <cmath>
#include "Object.h"

Object::Object(sf::Texture &texture,int classes){
    sprite.setTexture(texture);
    double tmp=rand()%1199;
    type=classes;
    switch(type){
        case BOSS1:                 life=50;speed.x=0;speed.y=20;break;
        case BOSS2:                 life=80;speed.x=120;speed.y=0;break;
        case ENEMY0_TYPE:           life=3;speed.x=(tmp-599)/8;speed.y=sqrt(360000-speed.x*speed.x)/8;break;
        case ENEMY1_TYPE:           life=10;speed.x=(tmp-599)/8;speed.y=sqrt(360000-speed.x*speed.x)/8;break;
        case ULTIMATE_BULLET_TYPE:  life=3;speed.x=tmp-599;speed.y=-sqrt(360000-speed.x*speed.x);break;
        case BULLET_TYPE:           life=2;speed.x=0;speed.y=-480;break;
        case ENEMY1_BULLET_TYPE:    life=1;speed.x=0;speed.y= 480;break;
        case HERO:                  life=50;break;
        case BOSS_BULLET_TYPE:      life=1;speed.x=tmp-599;speed.y=sqrt(360000-speed.x*speed.x);break;
    }
}

void Object::speedChange(sf::Vector2f axis){
    double x2=axis.x,y2=axis.y,  x11=speed.x,y11=speed.y;
    speed.x=(2*y11*x2*y2 - x11*(x2*x2-y2*y2))/(x2*x2+y2*y2);
    speed.y=2*x11*x2*y2/(x2*x2+y2*y2) + y11;
}
