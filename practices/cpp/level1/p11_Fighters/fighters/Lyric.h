#ifndef Lyric_h
#define Lyric_h

class Lyric {
private:
    sf::Font font;
    sf::Text text[31];
    std::string string[31];
    sf::RectangleShape rect,mag;
    bool mided=0;
    
public:
    Lyric() {
        rect.setSize(sf::Vector2f(0,10000));
        rect.setPosition(100,0);
        rect.setOutlineColor(sf::Color::Black);
        rect.setOutlineThickness(1);
        mag.setSize(sf::Vector2f(1000,300));
        mag.setPosition(0,460);
        mag.setFillColor(sf::Color(200,200,200,150));
        font.loadFromFile(resourcePath()+"using/font.ttf");
        std::ifstream data(resourcePath()+"using/lyric.txt");
        for(int i=0;i<31;i++) getline(data,string[i]);
        data.close();
        for(int i=0;i<31;i++) {
            text[i].setFont(font);
            text[i].setString(string[i]);
            text[i].setCharacterSize(100);
            text[i].setOutlineThickness(2);
            text[i].setOutlineColor(sf::Color(0,0,0,0));
            text[i].setFillColor(sf::Color(0,0,0,0));
            text[i].setPosition(0,0);
        }
    }
    
    void mid() {
        for(int i=0;i<31;i++) {
            if(mided==0) {
                rect.setPosition(3000,0);
                while(!rect.getGlobalBounds().intersects(text[i].getGlobalBounds())) rect.move(-1,0);
                text[i].setOrigin(rect.getPosition().x/2,0);
            }
            text[i].setScale(0.3,0.3);
            text[i].setPosition(500,-250*i+(1+i)*i-250);
            if(i>20) text[i].move(0,15-i);
            if(i>28) text[i].move(0,18-i);
        }
        mided=1;
    }
    
    void change() {
        for(int i=0;i<31;i++) {
            float y=text[i].getPosition().y;
            if(y>0 and y<600) {
                text[i].setScale(0.2+y/3000,0.2+y/3000);
                text[i].setFillColor(sf::Color(0,0,0,0.4*y));
                text[i].setOutlineColor(sf::Color(0,0,0,0.4*y));
                //if(i==0)std::cout<<0.4*y<<std::endl;
            }
            if(y>600 and y<1200) {
                text[i].setScale(0.2+(1200-y)/3000,0.2+(1200-y)/3000);
                text[i].setFillColor(sf::Color(0,0,0,0.4*(1200-y)));
                text[i].setOutlineColor(sf::Color(0,0,0,0.4*(1200-y)));
            }
        }
    }
    
    void reset() {
        for(int i=0;i<31;i++) {
            text[i].setPosition(500,-250*i+(1+i)*i-250);
            if(i>20) text[i].move(0,15-i);
            if(i>28) text[i].move(0,18-i);
        }
    }
    
    void move() {
        for(int i=0;i<31;i++) {
            text[i].move(0,1.15);
        }
    }
    
    bool start() {
        return (text[0].getPosition().y>465);
    }
    
    void draw(sf::RenderWindow* window) {
        for(int i=0;i<31;i++) {
            window->draw(text[i]);
        }
    }
    
};

#endif
