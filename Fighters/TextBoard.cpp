#include <SFML/Graphics.hpp>
#include <list>
#include "GlobalDefinitions.h"
#include "TextBoard.h"

TextBoard::TextBoard(){
    font = new sf::Font();
    font->loadFromFile("calibri.ttf");
    text = new sf::Text();
    text->setFont(*font);
}

TextBoard::TextBoard(int op){
    font = new sf::Font();
    font->loadFromFile("calibri.ttf");
    text = new sf::Text();
    text->setFont(*font);
    if(op == TITLE){
        sprintf(text_s, "SHOOTING SHIPS");
        text->setString(text_s);
        text->setCharacterSize(40);
        text->setFillColor(sf::Color::Yellow);
        text->setStyle(sf::Text::Bold);
        text->setPosition(0, 180);
    }
    else if(op == DECLARATION){
        sprintf(text_s, "Made by AutSky_JadeK \n(Li Zitong, UESTC, CCSE, 2016060106003)\n\nUse Direction Key to Control\nYour Movement.\nUse Space Bar to Shoot.");
        text->setString(text_s);
        text->setCharacterSize(24);
        text->setFillColor(sf::Color::White);
        text->setStyle(sf::Text::Bold);
        text->setPosition(0, 250);
    }
    else if(op == TEXTBEGIN){
        sprintf(text_s, "PRESS ANY KEY TO START");
        text->setString(text_s);
        text->setCharacterSize(40);
        text->setFillColor(sf::Color::White);
        text->setStyle(sf::Text::Bold);
        text->setPosition(0, 480);
    }
    else if(op == TEXTLOST){
        sprintf(text_s, "YOU LOSE!!!");
        text->setString(text_s);
        text->setCharacterSize(60);
        text->setFillColor(sf::Color::Black);
        text->setStyle(sf::Text::Bold);
        text->setPosition(80, 300);
    }
    else if(op == TEXTWIN){
        sprintf(text_s, "YOU WIN!!!");
        text->setString(text_s);
        text->setCharacterSize(60);
        text->setFillColor(sf::Color::Yellow);
        text->setStyle(sf::Text::Bold);
        text->setPosition(80, 300);
    }
    else if(op == L_P_R){
        sprintf(text_s, "Life Point Recovered!");
        text->setString(text_s);
        text->setCharacterSize(40);
        text->setFillColor(sf::Color::Green);
        text->setStyle(sf::Text::Bold);
        text->setPosition(20, 100);
    }
    else if(op == SPEEDUP){
        sprintf(text_s, "Speed Up!");
        text->setString(text_s);
        text->setCharacterSize(40);
        text->setFillColor(sf::Color::White);
        text->setStyle(sf::Text::Bold);
        text->setPosition(20, 100);
    }
    else if(op == BULLETACCELERATED){
        sprintf(text_s, "Bullet Accelerated!");
        text->setString(text_s);
        text->setCharacterSize(40);
        text->setFillColor(sf::Color::Yellow);
        text->setStyle(sf::Text::Bold);
        text->setPosition(20, 100);
    }
    else if(op == WEAPONUPGRADED){
        sprintf(text_s, "Weapon Upgraded!");
        text->setString(text_s);
        text->setCharacterSize(40);
        text->setFillColor(sf::Color::Black);
        text->setStyle(sf::Text::Bold);
        text->setPosition(20, 100);
    }
    else if(op == SPARKLEDYNAMITE){
        sprintf(text_s, "Sparkle Dynamite!");
        text->setString(text_s);
        text->setCharacterSize(40);
        text->setFillColor(sf::Color(250, 128, 10));
        text->setStyle(sf::Text::Bold);
        text->setPosition(20, 100);
    }
    else if(op == UPGRADELEFT){
        sprintf(text_s, "Upgrade Time: 20");
        text->setString(text_s);
        text->setCharacterSize(20);
        text->setFillColor(sf::Color::Black);
        text->setStyle(sf::Text::Bold);
        text->setPosition(280, 685);
    }
    else if(op == ACLEFT){
        sprintf(text_s, "Acceleration Time: 20");
        text->setString(text_s);
        text->setCharacterSize(20);
        text->setFillColor(sf::Color::Black);
        text->setStyle(sf::Text::Bold);
        text->setPosition(270, 50);
    }
    else if(op == PACLEFT){
        sprintf(text_s, "Bullets' Acceleration Time: 20");
        text->setString(text_s);
        text->setCharacterSize(20);
        text->setFillColor(sf::Color::Black);
        text->setStyle(sf::Text::Bold);
        text->setPosition(206, 70);
    }
    else if(op == ELITECOMING){
        sprintf(text_s, "Elite Enemies Coming!");
        text->setString(text_s);
        text->setCharacterSize(40);
        text->setFillColor(sf::Color::Red);
        text->setStyle(sf::Text::Bold);
        text->setPosition(20, 150);
    }
    else if(op == FLAGSHIPCOMING){
        sprintf(text_s, "Flagship-Enemies\nComing!");
        text->setString(text_s);
        text->setCharacterSize(40);
        text->setFillColor(sf::Color::Yellow);
        text->setStyle(sf::Text::Bold);
        text->setPosition(20, 150);
    }
    else if(op == BOSSCOMING){
        sprintf(text_s, "BOSSes Coming!");
        text->setString(text_s);
        text->setCharacterSize(40);
        text->setFillColor(sf::Color::Black);
        text->setStyle(sf::Text::Bold);
        text->setPosition(20, 150);
    }
}

TextBoard::~TextBoard(){
    delete font;
    delete text;
}
