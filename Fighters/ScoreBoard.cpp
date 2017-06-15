#include <SFML/Graphics.hpp>
#include "TextBoard.h"
#include "ScoreBoard.h"
#include <list>
#include "GlobalDefinitions.h"

ScoreBoard::ScoreBoard(): TextBoard(){
    cur_score = 0;
    cur_life = CONSTHP;
    sprintf(text_s, "Score: %d\nLife: %d", cur_score, cur_life);
    text->setString(text_s);
    text->setCharacterSize(24);
    text->setFillColor(sf::Color::White);
    text->setStyle(sf::Text::Bold);
}

void ScoreBoard::update(){
    sprintf(text_s, "Score: %d\nLife: %d", cur_score, cur_life);
    text->setString(text_s);
}
