#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Boom.h"
BOOM::BOOM(const sf::Texture *obj,int nowTime){
    for (int i=1;i<=5;i++){
        sprite[i].setTexture(obj[i]);
    }
    index=1;
    time=nowTime;
}
