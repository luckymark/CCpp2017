#ifndef Bullet_h
#define Bullet_h


class Bullet {
    
private:
    sf::Texture texture;
    sf::FloatRect bound;
    int side=0;
    float x,y;
    std::string type;
    float harm1=1,sharm1=20,harm2=1,harm3=1,harm5=5;
    float sizex=0.08,sizey=0.08;
    
public:
    sf::Clock clock;
    bool active=0;
    float harm,dx,dy,formal_dx,formal_dy;
    sf::Sprite body;
    
    
    Bullet(std::string type,std::string side="left"): type(type)
    {
        texture.loadFromFile(resourcePath()+"using/bullet"+type+".png");
        body.setTexture(texture);
        if(type=="1") {
            harm=harm1;
            if(side=="right") this->side=1;
        }
        else if(type=="s1") {
            harm=sharm1;
            body.setOrigin(220,-300);
            body.setScale(0.08,0.08);
        }
        else if(type=="2") {
            harm=harm2;
            
        }
        else if(type=="3") {
            harm=harm3;
            if(side=="right") this->side=1;
            if(side=="mid") this->side=2;
        }
        else if(type=="5") {
            harm=harm5;
            if(side=="right") this->side=1;
            if(side=="mid") this->side=2;
        }
        
    }
    
    
    void eject_from(float x,float y) {
        if(type=="1") {
            if(side) this->x=x+18;
            else this->x=x-18;
            this->y=y-80;
        }
        else if(type=="s1") {
            this->x=x;
            this->y=y-140;
        }
        else if(type=="2") {
            this->x=x;
            this->y=y-20;
        }
        else if(type=="3") {
            if(side==2) {
                this->x=x;
                this->y=y-18;
            }
            else if(side==1) {
                this->x=x+40;
                this->y=y+10;
            }
            else {
                this->x=x-40;
                this->y=y+10;
            }
        }
        else if(type=="5") {
            if(side==2) {
                this->x=x-40;
                this->y=y+30;
            }
            else if(side==1) {
                this->x=x;
                this->y=y;
            }
            else {
                this->x=x;
                this->y=y;
            }
        }
        body.setPosition(x,y);
    }
    
    
    void move(float trace_ship1_x=500,float trace_ship1_y=500) {
        if(type=="1") {
            body.setPosition(x,y-=30);
            if(body.getPosition().y<=0) active=0;
        }
        else if(type=="s1") {
            body.setPosition(x-=0.1,y-=10);
            //body.setScale(sizex+=0.001,sizey+=0.001);
            if(body.getScale().x<0.02) body.setScale(sizex+=0.001,sizey+=0.001);
            if(body.getPosition().y<=-500){
                active=0;
                sizex=sizey=0.08;
            }
        }
        else if(type=="2") {
            body.setPosition(x,y+=20);
            if(y>=1700) active=0;
        }
        else if(type=="3") {
            if(trace_ship1_y>y) {
                dx=(trace_ship1_x-x),dy=(trace_ship1_y-y);
                if(dy<std::abs(dx)) dy=std::abs(dx);
                formal_dx=dx/pow(dx*dx+dy*dy,0.5),formal_dy=dy/pow(dx*dx+dy*dy,0.5);
            }
            if(side==2) {
                body.setPosition(x+=20*formal_dx,y+=20*formal_dy);
            }
            else {
                body.setPosition(x+=15*formal_dx,y+=15*formal_dy);
            }
            if(y>=1700) active=0;
        }
        else if(type=="5") {
            if(clock.getElapsedTime().asSeconds()<5) {
                body.setColor(sf::Color(255,255,255,255-50*clock.getElapsedTime().asSeconds()));
            }
            else {
                active=0;
            }
            
            dx=(trace_ship1_x-x),dy=(trace_ship1_y-y);
            formal_dx=dx/pow(dx*dx+dy*dy,0.5),formal_dy=dy/pow(dx*dx+dy*dy,0.5);
            if(side==2) {
                body.setPosition(x+=7*formal_dx,y+=7*formal_dy);
            }
            else {
                body.setPosition(x+=7*formal_dx,y+=7*formal_dy);
            }
            if(y>=1700) active=0;
        }
        return body;
    }
    
    
    
    bool check(sf::FloatRect target_bound) {
        bound=body.getGlobalBounds();
        if (bound.intersects(target_bound)){
            if(type=="s1") return 1;
            active=0;
            return 1;
        }
        return 0;
    }
    
    bool boss_check(float bx,float by) {
        if((bx-body.getPosition().x)*(bx-body.getPosition().x)+(by-body.getPosition().y)*(by-body.getPosition().y)<36000) {
            active=0;
            return 1;
        }
        return 0;
    }
    
    
    
    
};

#endif
