#ifndef Ship_h
#define Ship_h

#include "Bullet.h"

/*
type:
    1.me
    2.little enemy
    3.big enemy
    4.umbrella
*/

class Ship {
    
private:
    sf::Clock color_clock,move_clock;
    sf::Texture texture;
    sf::FloatRect bound;
    const static int all_bullet=50,all_shell=50;
    std::string type;
    float blood1=30,blood2=2,blood3=20,reward2=0.5,reward3=3,to_transparent=250,positionx,positiony,rotate=0;
    int a=0,b=0;
public:
    sf::Sprite body;
    bool active,protect_active=0,collected=0,in_position=0,reviving=1,reseting=0;
    float blood,reward,clock0=0,transparent=255,rand_x,speed2,speed3=4,speed4x,speed4y=2;
    sf::Clock clock;
    Bullet *bullet_mid[all_bullet],*bullet_left[all_bullet],*bullet_right[all_bullet],*shell[all_shell];
    
    Ship(std::string type) {
        texture.loadFromFile(resourcePath()+"using/ship"+type+".png");
        body.setTexture(texture);
        this->type=type;
        
        if(type=="1") {
            body.setOrigin(50,80);
            body.setPosition(500,1700);
            blood=blood1;
            active=1;
            for(int i=0;i<all_bullet;i++) {
                bullet_left[i]=new Bullet(type,"left");
                bullet_right[i]=new Bullet(type,"right");
            }
            for(int i=0;i<all_shell;i++) {
                shell[i]=new Bullet("s"+type);
            }
        }
        
        
        else if(type=="2") {
            body.setOrigin(29,67);
            rand_x=60+rand()%870;
            body.setPosition(rand_x,0);
            blood=blood2;
            reward=reward2;
            active=0;
            speed2=5+rand()%5;
            for(int i=0;i<all_bullet;i++) {
                bullet_mid[i]=new Bullet(type);
            }
        }
        
        else if(type=="3") {
            body.setOrigin(45,50);
            rand_x=80+rand()%830;
            body.setPosition(rand_x,-100);
            blood=blood3;
            reward=reward3;
            active=0;
            for(int i=0;i<all_bullet;i++) {
                bullet_mid[i]=new Bullet(type,"mid");
                bullet_left[i]=new Bullet(type,"left");
                bullet_right[i]=new Bullet(type,"right");
            }
        }
        
        else if(type=="4") {
            body.setOrigin(40,50);
            rand_x=80+rand()%830;
            body.setPosition(rand_x,-80);
            active=0;
            blood=1;
            collected=0;
            if(body.getPosition().x<500) speed4x=(1+rand()%10)/10.0;
            else speed4x=-(1+rand()%10)/10.0;
        }
        
        else if(type=="5") {
            body.setOrigin(600,600);
            body.setPosition(500,-600);
            transparent=0;
            body.setScale(0.5,0.5);
            body.setColor(sf::Color(255,255,255,transparent));
            blood=1000;
            active=0;
            for(int i=0;i<all_bullet;i++) {
                bullet_mid[i]=new Bullet(type,"mid");
                bullet_left[i]=new Bullet(type,"left");
                bullet_right[i]=new Bullet(type,"right");
            }
        }
        
        
    }
    
    void total_reset() {
        if(type=="1") {
            //active=0;
            body.setPosition(500,1700);
            blood=blood1;
            active=1;
            reviving=1;
        }
        else if(type=="2") {
            active=0;
            rand_x=60+rand()%870;
            body.setPosition(rand_x,0);
            blood=blood2;
            speed2=5+rand()%5;
            transparent=255;
            body.setColor(sf::Color(255,255,255,transparent));
        }
        else if(type=="3") {
            active=0;
            rand_x=80+rand()%830;
            body.setPosition(rand_x,-100);
            blood=blood3;
            speed3=4;
            transparent=255;
            body.setColor(sf::Color(255,255,255,transparent));
        }
        else if(type=="4" ) {
            active=0;
            rand_x=80+rand()%830;
            body.setPosition(rand_x,-80);
            blood=1;
            transparent=255;
            body.setColor(sf::Color(255,255,255,transparent));
            collected=0;
        }
        else if(type=="5") {
            body.setPosition(500,-600);
            transparent=0;
            body.setColor(sf::Color(255,255,255,transparent));
            blood=1000;
            active=0;
            to_transparent=250;
            a=b=0;
        }
    }
    
    void revive() {
        active=1;
        if(body.getPosition().y>1200) {
            body.move(0,-(body.getPosition().y-1050)/30.0);
        }
        else reviving=0;
    }
    
    void reset(int c=0) {
        if(type=="1") {
            transparent-=3;
            if(c==0) transparent-=5;
            if(transparent>0 and transparent<255) {
                body.setColor(sf::Color(255,255,255,transparent));
            }
            else {
                reseting=0;
                active=0;
                body.setPosition(500,1700);
                blood=blood1;
                transparent=255;
                body.setColor(sf::Color(255,255,255,transparent));
            }
        }
        else if(type=="2") {
            transparent-=15;
            if(transparent>0 and transparent<255) {
                body.setColor(sf::Color(255,255,255,transparent));
            }
            else {
                active=0;
                rand_x=60+rand()%870;
                body.setPosition(rand_x,0);
                blood=blood2;
                transparent=255;
                body.setColor(sf::Color(255,255,255,transparent));
            }
            
        }
        else if(type=="3") {
            transparent-=15;
            if(transparent>0 and transparent<255) {
                body.setColor(sf::Color(255,255,255,transparent));
            }
            else {
                active=0;
                rand_x=80+rand()%830;
                body.setPosition(rand_x,-100);
                blood=blood3;
                transparent=255;
                body.setColor(sf::Color(255,255,255,transparent));
            }
        }
        else if(type=="4") {
            collected=1;
            transparent-=15;
            if(transparent>0 and transparent<255) {
                body.setColor(sf::Color(255,255,255,transparent));
            }
            else {
                active=0;
                collected=0;
                rand_x=80+rand()%830;
                body.setPosition(rand_x,-80);
                blood=blood3;
                transparent=255;
                body.setColor(sf::Color(255,255,255,transparent));
            }
        }
        else if(type=="5") {
            in_position=0;
            if(rand()%5==0) {
                transparent=50;
                a++;
            }
            if(rand()%5==1) {
                transparent=250;
                b++;
            }
            body.setColor(sf::Color(255,255,255,transparent));
            if(a>50 and b>50) {
                active=0;
            }
            //std::cout<<"a:"<<a<<"b:"<<b<<std::endl;
        }
        
    }
    
    
    //load one at a time
    void load_bullet(float x,float y) {
        if(type=="1") {
            int i=0;
            while(bullet_left[i]->active and i<all_bullet) {
                i++;
            }
            bullet_left[i]->active=1;
            bullet_left[i]->eject_from(x,y);
            i=0;
            while(bullet_right[i]->active and i<all_bullet) {
                i++;
            }
            bullet_right[i]->active=1;
            bullet_right[i]->eject_from(x,y);
        }
        else if(type=="2") {
            int i=0;
            while(bullet_mid[i]->active and i<all_bullet) {
                i++;
            }
            bullet_mid[i]->active=1;
            bullet_mid[i]->eject_from(x,y);
        }
        else if(type=="3") {
            int i=0;
            while(bullet_left[i]->active and i<all_bullet) {
                i++;
            }
            bullet_left[i]->active=1;
            bullet_left[i]->eject_from(x,y);
            i=0;
            while(bullet_right[i]->active and i<all_bullet) {
                i++;
            }
            bullet_right[i]->active=1;
            bullet_right[i]->eject_from(x,y);
            i=0;
            while(bullet_mid[i]->active and i<all_bullet) {
                i++;
            }
            bullet_mid[i]->active=1;
            bullet_mid[i]->eject_from(x,y);
        }
        else if(type=="5") {
            int i=0;
            while(bullet_mid[i]->active and i<all_bullet) {
                i++;
            }
            bullet_mid[i]->active=1;
            bullet_mid[i]->clock.restart();
            bullet_mid[i]->eject_from(x,y);
            
        }
            
        
    }
    
    void load_shell(float x, float y) {
        int i=0;
        while(shell[i]->active and i<all_shell) {
            i++;
        }
        shell[i]->active=1;
        shell[i]->eject_from(x,y);
    }
    
    void  load_protect() {
        body.setColor(sf::Color(255,255,255,30));
        protect_active=1;
    }
    
    void end_protect() {
        body.setColor(sf::Color(255,255,255,255));
        protect_active=0;
    }
    
    void check_protect(float time) {
        if(time>8 and time<8.2) body.setColor(sf::Color(255,255,255,255));
        else if(time>8.2 and time<8.4) body.setColor(sf::Color(255,255,255,30));
        else if(time>8.4 and time<8.6) body.setColor(sf::Color(255,255,255,255));
        else if(time>8.6 and time<8.8) body.setColor(sf::Color(255,255,255,30));
        else if(time>8.8 and time<9) body.setColor(sf::Color(255,255,255,255));
        else if(time>9 and time<9.2) body.setColor(sf::Color(255,255,255,30));
        else if(time>9.2 and time<9.4) body.setColor(sf::Color(255,255,255,255));
        else if(time>9.4 and time<9.6) body.setColor(sf::Color(255,255,255,30));
        else if(time>9.6 and time<9.8) body.setColor(sf::Color(255,255,255,255));
        else if(time>9.8 and time<10) body.setColor(sf::Color(255,255,255,30));
        if(time>=10) end_protect();
    }
    
    void color(float r=255,float g=255,float b=255) {
        if(transparent!=to_transparent){
            if(transparent>to_transparent) transparent-=1;
            else if(transparent<to_transparent) transparent+=1;
        }
        if(color_clock.getElapsedTime().asSeconds()>3) {
            if(rand()%3==0) to_transparent=50;
            else to_transparent=200;
            color_clock.restart();
        }
        body.setColor(sf::Color(r,g,b,transparent));
    }
    
    void move() {
        positionx=body.getPosition().x;
        positiony=body.getPosition().y;
        if(active) {
            if(type=="2") body.move(0,speed2);
            else if(type=="3") body.move(0,speed3);
            else if(type=="4"){
                body.move(speed4x,speed4y);
                
            }
            else if(type=="5") {
                if(positiony<350) body.move(0,(400-positiony)/500);
                else in_position=1;
            }
        }
        if(in_position) {
        }
        
    }
    
    //draw
    void draw_ship(sf::RenderWindow* window) {
        if(body.getPosition().x>1000 or body.getPosition().x<0) reset();
        if(body.getPosition().y>=1750){
            total_reset();
        }
        if(active) {
            window->draw(body);
        }
    }

    
    void draw_bullets(sf::RenderWindow* window,float trace_ship1_x=0,float trace_ship2_y=0) {
        if(type=="1") {
            for(int i=0;i<all_bullet;i++) {
                if(bullet_left[i]->active) {
                    bullet_left[i]->move();
                    window->draw(bullet_left[i]->body);
                }
                if(bullet_right[i]->active) {
                    bullet_right[i]->move();
                    window->draw(bullet_right[i]->body);
                }
            }
            for(int i=0;i<all_shell;i++) {
                if(shell[i]->active) {
                    shell[i]->move();
                    window->draw(shell[i]->body);
                }
            }

        }
        else if(type=="2") {
            for(int i=0;i<all_bullet;i++) {
                if(bullet_mid[i]->active) {
                    bullet_mid[i]->move();
                    window->draw(bullet_mid[i]->body);
                }
            }
        }
        else if(type=="3" or type=="5") {
            for(int i=0;i<all_bullet;i++) {
                if(bullet_mid[i]->active) {
                    bullet_mid[i]->move(trace_ship1_x,trace_ship2_y);
                    window->draw(bullet_mid[i]->body);
                }
                if(bullet_left[i]->active) {
                    bullet_left[i]->move(trace_ship1_x,trace_ship2_y);
                    window->draw(bullet_left[i]->body);
                }
                if(bullet_right[i]->active) {
                    bullet_right[i]->move(trace_ship1_x,trace_ship2_y);
                    window->draw(bullet_right[i]->body);
                }
            }
        }
        
    }
    
    void draw__bullets(sf::RenderWindow* window,float trace_ship1_x=0,float trace_ship2_y=0) {
        if(type=="1") {
            for(int i=0;i<all_bullet;i++) {
                if(bullet_left[i]->active) {
                    window->draw(bullet_left[i]->body);
                }
                if(bullet_right[i]->active) {
                    window->draw(bullet_right[i]->body);
                }
            }
            for(int i=0;i<all_shell;i++) {
                if(shell[i]->active) {
                    window->draw(shell[i]->body);
                }
            }
            
        }
        else if(type=="2") {
            for(int i=0;i<all_bullet;i++) {
                if(bullet_mid[i]->active) {
                    window->draw(bullet_mid[i]->body);
                }
            }
        }
        else if(type=="3") {
            for(int i=0;i<all_bullet;i++) {
                if(bullet_mid[i]->active) {
                    window->draw(bullet_mid[i]->body);
                }
                if(bullet_left[i]->active) {
                    window->draw(bullet_left[i]->body);
                }
                if(bullet_right[i]->active) {
                    window->draw(bullet_right[i]->body);
                }
            }
        }
        else if(type=="5") {
            for(int i=0;i<all_bullet;i++) {
                if(bullet_mid[i]->active) {
                    window->draw(bullet_mid[i]->body);
                }
                if(bullet_left[i]->active) {
                    window->draw(bullet_left[i]->body);
                }
                if(bullet_right[i]->active) {
                    window->draw(bullet_right[i]->body);
                }
            }
        }
        
    }
    
    
    //check if on target
    bool bullet_check_left(sf::FloatRect target_bound) {
            for(int i=0;i<all_bullet;i++) {
            if(bullet_left[i]->active and bullet_left[i]->check(target_bound)) {
                return 1;
            };
        }
        return 0;
    }
    
    bool bullet_check_right(sf::FloatRect target_bound) {
        for(int i=0;i<all_bullet;i++) {
            if(bullet_right[i]->active and bullet_right[i]->check(target_bound)) {
                return 1;
            };
        }
        return 0;
    }
    
    bool bullet_check_mid(sf::FloatRect target_bound) {
        for(int i=0;i<all_bullet;i++) {
            if(bullet_mid[i]->active and bullet_mid[i]->check(target_bound)) {
                return 1;
            };
        }
        return 0;
    }
    
    bool shell_check(sf::FloatRect target_bound) {
        for(int i=0;i<all_shell;i++) {
            if(shell[i]->active and shell[i]->check(target_bound)) {
                return 1;
            }
        }
        return 0;
    }
    bool boss_shell_check(float x,float y) {
        for(int i=0;i<all_shell;i++) {
            if(shell[i]->active and shell[i]->boss_check(x,y)) {
                return 1;
            }
        }
        return 0;
    }
    
    
    bool boss_check_left(float x,float y) {
        for(int i=0;i<all_bullet;i++) {
            if(bullet_left[i]->active and bullet_left[i]->boss_check(x,y)) {
                return 1;
            };
        }
        return 0;
    }
    bool boss_check_right(float x,float y) {
        for(int i=0;i<all_bullet;i++) {
            if(bullet_right[i]->active and bullet_right[i]->boss_check(x,y)) {
                return 1;
            };
        }
        return 0;
    }

    
};


#endif
