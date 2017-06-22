#ifndef ULTIMATE_H
#define ULTIMATE_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <windows.h>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#define XRANGE 800
#define YRANGE 1080
using namespace std;

class Ultimate{
public:
    int lastTime,time,type;
    bool able,on;
    sf::Vector2f position;
    string leftTime,ori;
    sf::Text text;
    Ultimate(int _type,sf::Font  &font);
    void upDate(int clockTime);
    void useUltimate(int clockTime);
    void setText(int clockTime);
    void reNew(int clockTime);
};
#endif // ULTIMATE_H
