#ifndef Bar_h
#define Bar_h

class Bar {
private:
    sf::RectangleShape left_border,right_border,hide_score;
    sf::Texture control_bar_texture;
    sf::Sprite control_bar_sprite;
    sf::RectangleShape health,skill,boss_health;// total size: (450,40)
    sf::Text promote_text,life_text,distance_text,kill_text,score_text,score_big,num;
    sf::Font font;
    
    
    
public:
    
    int health_now=450,skill_now=0,health_update=15,skill_update=30,boss_health_now=1;
    int promote,life,kill2,kill3;
    bool boss=0,blood=0;
    //tictoc
    sf::Clock total_clock;
    float total_clock0,final_score;
    float bossr=0;
    
    Bar() {
        left_border.setSize(sf::Vector2f(0,1600));
        left_border.setOutlineColor(sf::Color::Black);
        left_border.setOutlineThickness(2);
        left_border.setPosition(2,0);
        right_border.setSize(sf::Vector2f(0,1600));
        right_border.setOutlineColor(sf::Color::Black);
        right_border.setOutlineThickness(2);
        right_border.setPosition(998,0);
        control_bar_texture.loadFromFile(resourcePath()+"using/control_bar.png");
        control_bar_sprite.setTexture(control_bar_texture);
        control_bar_sprite.setPosition(1,1349);
        control_bar_sprite.setColor(sf::Color(255,255,255,180));
        skill.setSize(sf::Vector2f(skill_now,40));
        skill.setFillColor(sf::Color::Black);
        skill.setPosition(167,1373);
        skill.setFillColor(sf::Color(100,100,100,200));
        health.setSize(sf::Vector2f(health_now,40));
        health.setFillColor(sf::Color::Black);
        health.setPosition(167,1441);
        health.setFillColor(sf::Color(100,100,100,200));
        boss_health.setSize(sf::Vector2f(boss_health_now,40));
        boss_health.setFillColor(sf::Color::Black);
        //boss_health.setPosition(0,0);
        boss_health.setFillColor(sf::Color(100,100,100,200));
        font.loadFromFile(resourcePath()+"using/font.ttf");
        promote_text.setFont(font);
        promote_text.setFillColor(sf::Color::Black);
        promote_text.setString(std::to_string(promote));
        promote_text.setPosition(665,1363);
        promote_text.setCharacterSize(50);
        promote_text.setOutlineThickness(1);
        life_text.setFont(font);
        life_text.setFillColor(sf::Color::Black);
        life_text.setString(std::to_string(life));
        life_text.setPosition(665,1431);
        life_text.setCharacterSize(50);
        life_text.setOutlineThickness(1);
        distance_text.setFont(font);
        distance_text.setFillColor(sf::Color::Black);
        distance_text.setString(std::to_string((int)(total_clock.getElapsedTime().asSeconds()+total_clock0))+" km");
        distance_text.setPosition(883,1405);
        distance_text.setCharacterSize(22);
        distance_text.setOutlineThickness(1);
        kill_text.setFont(font);
        kill_text.setFillColor(sf::Color::Black);
        kill_text.setString(std::to_string(kill2+kill3)+" ships");
        kill_text.setPosition(883,1368);
        kill_text.setCharacterSize(22);
        kill_text.setOutlineThickness(1);
        score_text.setFont(font);
        score_text.setFillColor(sf::Color::Black);
        score_text.setString(std::to_string(((float)kill3)*20+(float)kill2*8+(total_clock.getElapsedTime().asSeconds()+total_clock0)*2));
        score_text.setPosition(880,1447);
        score_text.setCharacterSize(28);
        score_text.setOutlineThickness(1);
        hide_score.setSize(sf::Vector2f(4,30));
        hide_score.setPosition(992,1450);
        hide_score.setFillColor(sf::Color(185,195,180));
        
        score_big.setFont(font);
        score_big.setFillColor(sf::Color::Black);
        score_big.setString(std::to_string(((float)kill3)*20+(float)kill2*8+(total_clock.getElapsedTime().asSeconds()+total_clock0)*2));
        score_big.setPosition(400,250);
        score_big.setCharacterSize(100);
        score_big.setOutlineThickness(3);
    }
    
    void update_health(float harm) {
        health_now-=harm*health_update;
        if(health_now<=0) {
            health_now+=450;
            life--;
        }
        if(health_now>450) {
            health_now-=450;
            life++;
        }
        if(life<1) health_now=0;
        health.setSize(sf::Vector2f(health_now,40));
    }
    void update_boss(float harm) {
        boss_health_now-=harm;
        if(boss_health_now<=0) boss_health_now=0;
        boss_health.setSize(sf::Vector2f(boss_health_now,40));
        //std::cout<<boss_health_now<<std::endl;
    }
    void update_skill(float reward) {
        if(promote<=9) {
            skill_now+=reward*skill_update;
            if(skill_now>=450) {
                skill_now-=450;
                promote++;
            }
            if(skill_now<=0) {
                skill_now+=450;
                promote--;
            }
            skill.setSize(sf::Vector2f(skill_now,40));
        }
        else if(promote==10) {
            skill_now+=reward*skill_update;
            if(skill_now>=450) {
                skill_now=450;
            }
            if(skill_now<=0) {
                skill_now+=450;
                promote--;
            }
            skill.setSize(sf::Vector2f(skill_now,40));
        }
    }
    void draw(sf::RenderWindow* window) {
        
        promote_text.setString(std::to_string(promote));
        life_text.setString(std::to_string(life));
        distance_text.setString(std::to_string((int)(total_clock.getElapsedTime().asSeconds()+total_clock0))+" km");
        kill_text.setString(std::to_string(kill2+kill3)+" ships");
        score_text.setString(std::to_string(final_score=((float)kill3)*20+(float)kill2*8+2*bossr+(total_clock.getElapsedTime().asSeconds()+total_clock0)*2));
        if(boss==1){
            if(boss_health_now<1000 and !blood) {
                boss_health_now+=10;
                boss_health.setSize(sf::Vector2f(boss_health_now,40));
            }
            else blood=1;
            window->draw(boss_health);
        }
        window->draw(control_bar_sprite);
        window->draw(left_border);
        window->draw(right_border);
        window->draw(skill);
        window->draw(health);
        window->draw(promote_text);
        window->draw(life_text);
        window->draw(distance_text);
        window->draw(kill_text);
        window->draw(score_text);
        window->draw(hide_score);
    }

    void draw_dead_score(sf::RenderWindow* window) {
        score_big.setString(std::to_string((int)final_score));
        window->draw(score_big);
    }
    
    void reset() {
        bossr=0;
        boss_health_now=1;
        blood=0;
        boss=0;
        promote=3;
        life=3;
        kill2=kill3=0;
        health_now=450;
        skill_now=0;
        health.setSize(sf::Vector2f(health_now,40));
        skill.setSize(sf::Vector2f(skill_now,40));
    }
};

#endif
