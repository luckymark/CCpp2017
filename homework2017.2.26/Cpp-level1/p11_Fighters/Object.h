#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#define XRANGE 800
#define YRANGE 1080
#define BULLET_TYPE 2
#define ULTIMATE_BULLET_TYPE 3
#define ENEMY0_TYPE 4
#define ENEMY1_TYPE 5
#define BOSS1 6
#define BOSS_BULLET_TYPE 11
#define BOSS2 8
#define HERO 1
#define ENEMY1_BULLET_TYPE 7
class Object{
public:
    int life,type;
    sf::Vector2f speed;
    sf::Sprite sprite;
    Object(sf::Texture &texture,int classic);
    void speedChange(sf::Vector2f axis);
};
#endif // OBJECT_H
