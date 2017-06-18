//
//  GameMenu.cpp
//  Fighters
//
//  Created by Jimmy Fan on 2017/6/15.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <cstdio>
#include "GameMenu.h"
using namespace std;

GameMenu::GameMenu() {
    font.loadFromFile("/Users/fjm/Git/Fighters/Resources/Arial Black.ttf");
    title.setFont(font);
    title.setStyle(sf::Text::Bold);
    title.setString("Fighters");
    title.setCharacterSize(80);
    sf::FloatRect rect = title.getLocalBounds();
    title.setPosition((windowWidth - rect.width)/2, 50);
    
    start.setFont(font);
    start.setString("Start Game");
    start.setCharacterSize(35);
    rect = start.getLocalBounds();
    start.setPosition((windowWidth - rect.width)/2, 200);
    
    rank.setFont(font);
    rank.setString("Rank");
    rank.setCharacterSize(35);
    rect = rank.getLocalBounds();
    rank.setPosition((windowWidth - rect.width)/2, 300);
    
    quit.setFont(font);
    quit.setString("Quit Game");
    quit.setCharacterSize(35);
    rect = quit.getLocalBounds();
    quit.setPosition((windowWidth - rect.width)/2, 400);
    
    texture.loadFromFile("/Users/fjm/Git/Fighters/Resources/selector.png");
    selector.setTexture(texture);
}

int GameMenu::setEvent(sf::Keyboard::Key key) {
    if (key == sf::Keyboard::Up) {
        index = index==1?1:index-1;
    }
    if (key == sf::Keyboard::Down) {
        index = index==3?3:index+1;
    }
    if (key == sf::Keyboard::Return) {
        return index;
    }
    return 0;
}

sf::Text GameMenu::getTitleText() {
    return title;
}

sf::Text GameMenu::getStartText() {
    return start;
}

sf::Text GameMenu::getRankText() {
    return rank;
}

sf::Text GameMenu::getQuitText() {
    return quit;
}

sf::Sprite GameMenu::getSelector() {
    selector.setPosition(60, (index+1) * 100 + 5);
    return selector;
}
