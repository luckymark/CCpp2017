//
//  GameMenu.h
//  Fighters
//
//  Created by Jimmy Fan on 2017/6/15.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef GameMenu_h
#define GameMenu_h

#include <SFML/Graphics.hpp>
#define windowWidth 480

class GameMenu {
private:
    sf::Font font;
    sf::Text title;
    sf::Text start;
    sf::Text rank;
    sf::Text quit;
    sf::Sprite selector;
    sf::Texture texture;
    int index = 1;
public:
    bool inMenu;
    GameMenu();
    int setEvent(sf::Keyboard::Key key);
    sf::Text getTitleText();
    sf::Text getStartText();
    sf::Text getRankText();
    sf::Text getQuitText();
    sf::Sprite getSelector();
};


#endif /* GameMenu_h */
