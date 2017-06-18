//
//  Sprite.h
//  Fighters
//
//  Created by Jimmy Fan on 2017/5/15.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Sprite_h
#define Sprite_h


#include <SFML/Graphics.hpp>
#define windowWidth 480
#define windowHeight 600

class Sprite {
public:
    sf::Vector2u rect;
    sf::Texture texture;
    virtual void move(sf::Time time) = 0;
    int speed;
};

#endif /* Sprite_h */
