//
//  Score.h
//  Fighters
//
//  Created by Jimmy Fan on 2017/5/23.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Score_h
#define Score_h

#include <SFML/Graphics.hpp>

class Score {
private:
    sf::Font font;
    int scoreNow;
public:
    sf::Text score;
    Score();
    void updateScore(int x);
    int getScore();
};


#endif /* Score_h */
