//
//  Heart.h
//  Fighters
//
//  Created by Jimmy Fan on 2017/5/25.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Heart_h
#define Heart_h

#include <SFML/Graphics.hpp>

class Heart {
private:
    sf::Texture texture;
    sf::Vector2u rect;
public:
    sf::Sprite heart;
    Heart();
    sf::Vector2u getRect();
};


#endif /* Heart_h */
