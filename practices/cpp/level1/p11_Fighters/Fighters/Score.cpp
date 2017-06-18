//
//  Score.cpp
//  Fighters
//
//  Created by Jimmy Fan on 2017/5/23.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <cstdio>
#include "Score.h"
using namespace std;

Score::Score() {
    scoreNow = 0;
    font.loadFromFile("/Users/fjm/Git/Fighters/Resources/Arial Black.ttf");
    score.setFont(font);
    score.setCharacterSize(30);
    score.setFillColor(sf::Color::White);
    score.setPosition(20, 20);
    score.setString("Score: " + to_string(scoreNow));
    score.setStyle(sf::Text::Bold);
}

void Score::updateScore(int x) {
    if (x == 0) scoreNow = 0;
    else scoreNow += x;
    score.setString("Score: " + to_string(scoreNow));
}

int Score::getScore() {
    return scoreNow;
}
