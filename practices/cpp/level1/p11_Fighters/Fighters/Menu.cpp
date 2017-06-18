//
//  Menu.cpp
//  Fighters
//
//  Created by Jimmy Fan on 2017/6/12.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include "Menu.h"
#include <cstdio>
using namespace std;

Menu::Menu() {
    font.loadFromFile("/Users/fjm/Git/Fighters/Resources/Arial Black.ttf");
    Damage.setFont(font);
    Speed.setFont(font);
    Life.setFont(font);
    Title.setFont(font);
    Title.setString("Ability");
    Title.setCharacterSize(40);
    Title.setPosition((windowWidth - Title.getLocalBounds().width) / 2, 50);
    Damage.setPosition(120, 150);
    Speed.setPosition(120, 220);
    Life.setPosition(120, 290);

}

void Menu::setData(int damage, int speed, int life) {
    Damage.setString("Damamge:  " + to_string(damage));
    Speed.setString( "Speed:        " + to_string(speed/50));
    Life.setString(  "Life:            " + to_string(life));
}

sf::Text Menu::getDamageText() {
    return Damage;
}

sf::Text Menu::getSpeedText() {
    return Speed;
}

sf::Text Menu::getLifeText() {
    return Life;
}

sf::Text Menu::getTitleText() {
    return Title;
}
