#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <windows.h>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "Ultimate.h"
using namespace std;

Ultimate::Ultimate(int _type,sf::Font  &font){
    type=_type;
    able=false;on=false;
    lastTime=0;time=0;
    if (type==1){
        ori="Ultimate1 CD:";
        position.x=0;position.y=30;
        text.setColor(sf::Color::Green);
    }
    else if (type==2){
        ori="Ultimate2 CD:";
        position.x=0;position.y=60;
        text.setColor(sf::Color::Blue);
    }
    text.setCharacterSize(20);
    text.setFont(font);
    text.setPosition(position);
}

void Ultimate::upDate(int clockTime){
    if (type==1){
        if (lastTime+5000<clockTime)        able=true;
        if (time+3000<clockTime)            on=false;
    }
    else if (type==2){
        if (lastTime+15000<clockTime)       able=true;
        if (time+5000<clockTime)            on=false;
    }
}

void Ultimate::useUltimate(int clockTime){
    lastTime=clockTime;
    time=clockTime;
    on=true;
    able=false;
}

void Ultimate::setText(int clockTime){
    char num[10];int x;
    if (type==1)        x=max(0,5000+lastTime-clockTime);
    else if (type==2)   x=max(0,15000+lastTime-clockTime);
    itoa((x+999)/1000,num,10);
    leftTime=ori;
    leftTime.append(num);
    text.setString(leftTime);
}

void Ultimate::reNew(int clockTime){
    lastTime=clockTime;
    time=clockTime;
    on=false;
    able=false;
}
