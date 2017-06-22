#ifndef BOOM_H
#define BOOM_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class BOOM{
public:
    sf::Sprite sprite[6];
    int index,time;
    BOOM(const sf::Texture *obj,int nowTime);
};
#endif // BOOM_H
