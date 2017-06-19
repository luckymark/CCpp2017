#ifndef Back_h
#define Back_h

class Back{
    
private:
    sf::Texture texture;
    sf::Sprite body[50];
    bool active[50];
    int side[50];
    float speed_x[50],speedup=1;
    
public:
    float state=0;
    Back(std::string type,int big=0){
        texture.loadFromFile(resourcePath()+"using/cloud"+type+".png");
        for(int i=0;i<50;i++) {
            if(i<=15) side[i]=0;
            else if(i<=30) side[i]=1;
            else if(i<=40) side[i]=2;
            else side[i]=3;
            active[i]=0;
            body[i].setTexture(texture);
            if(big==0) body[i].setOrigin(100,70);
            else body[i].setOrigin(250,175);
            if(side[i]==0) body[i].setPosition(-250,-150+rand()%1600);
            else if(side[i]==1) body[i].setPosition(1250,-150+rand()%1600);
            else if(side[i]==2) body[i].setPosition(50+rand()%1000,-350);
            else body[i].setPosition(-50+rand()%1000,-350);
            body[i].setColor(sf::Color(255,255,255,120));
            if(big==0) speed_x[i]=(1+rand()%5)/8.0;
            else speed_x[i]=(1+rand()%5)/5.0;
        }
    }
    
    void reset(int i) {
        if(side[i]==0) body[i].setPosition(-250,-150+rand()%1600);
        else if(side[i]==1) body[i].setPosition(1250,-150+rand()%1600);
        else if(side[i]==2) body[i].setPosition(50+rand()%1000,-350);
        else body[i].setPosition(-50+rand()%1000,-350);
        active[i]=0;
    }
    
    void load() {
        int range;
        if(state) range=50;
        else range=30;
        int rand_load=rand()%range;
        while(active[rand_load]) {
            rand_load=rand()%range;
        }
        active[rand_load]=1;
    }
    
    void draw(sf::RenderWindow* window){
        if(state==0) {
           for(int i=0;i<50;i++)
               if(active[i]) {
                   window->draw(body[i]);
                   if(side[i]==0) body[i].move(speed_x[i],0);
                   else if(side[i]==1) body[i].move(-speed_x[i],0);
                   else if(side[i]==2) body[i].move(speed_x[i],0);
                   else body[i].move(-speed_x[i],0);
               }
        }
        
        else if(state==1) {
            for(int i=0;i<50;i++)
                if(active[i]) {
                    window->draw(body[i]);
                    if(side[i]==0) body[i].move(speed_x[i],1);
                    else if(side[i]==1) body[i].move(-speed_x[i],1);
                    else if(side[i]==2) body[i].move(speed_x[i],1);
                    else body[i].move(-speed_x[i],1);
                }
        }
        
        else if(state==2) {
            for(int i=0;i<50;i++)
                if(active[i]) {
                    window->draw(body[i]);
                    if(speedup<20) speedup+=0.01;
                    if(side[i]==0) body[i].move(speedup*speed_x[i],0);
                    else if(side[i]==1) body[i].move(-speedup*speed_x[i],0);
                    else if(side[i]==2) body[i].move(speedup*speed_x[i],0);
                    else body[i].move(-speedup*speed_x[i],0);
                }
        }
        
        for(int i=0;i<50;i++) {
            float x=body[i].getPosition().x,y=body[i].getPosition().y;
            if(y>1600 or x>1600 or x<-600) {
                reset(i);
            }
        }
    }
    
    
    
    
};


#endif
