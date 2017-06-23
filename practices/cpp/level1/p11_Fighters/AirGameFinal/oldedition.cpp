#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <list>
#include <iostream>
#include <deque>
using namespace sf;
const int H=1080;
const int W=1920;

class Entity{
    public:
        float x,y,dx,dy,R,angle;
        bool life;
        std::string name;
        Sprite sprite;
        Entity(){life=1;}

void settings(Texture &t,int X,int Y,int radius=1){
  sprite.setTexture(t);
  x=X; y=Y;
  R = radius;
}

virtual void update(){};

void draw(RenderWindow &window)
{
  sprite.setPosition(x,y);
  window.draw(sprite);
}

virtual ~Entity(){};
};

class enemyflight: public Entity{
    public:
        enemyflight(){name="enemyflight";}

        void update(){
            x-=3;
            if(x<0){
            life=false;}
        }
};

class bullet:public Entity{
    public:
    bullet(){name="bullet";}

    void update(){
        x+=10;
        /////sidemanage/////
        if(x>2000){
            life=false;
        }
        /////////explosion//////
        if(life==false){

        }
    }
};

bool isCollide(Entity *a,Entity *b){
    return (b->x - a->x)*(b->x - a->x)+
         (b->y - a->y)*(b->y - a->y)<
         (a->R + b->R)*(a->R + b->R);
}
int main(){
    srand(time(0));
//////////window///////////
    RenderWindow window(VideoMode(W,H),"AirGameFinal+1s");
//    window.setFramerateLimit(60);
//    window.setVerticalSyncEnabled(true);
/////////background////////
    Texture background;
    background.loadFromFile("rmdht.jpg");
    Sprite mBackground(background);
////////player////////////
    Texture player;
    player.loadFromFile("jzm.jpg");
    Sprite mPlayer(player);
    mPlayer.setPosition(0,500);
/////////////backgroundmusic////////////
    Music music;
    music.openFromFile("backgroundmusic.ogg");
    music.play();
    music.setLoop(true);
///////////////explosion////////////
    Texture explosion;
    explosion.loadFromFile("images/explosions/type_A.png");
    Sprite mExplosion;

///////////////////bullet/////////////////////
    Texture mbullet;
    mbullet.loadFromFile("bullet.png");
///////////////linklist////////////
std::deque<Entity*> entities;
///////////////////
    int scores=0;

////////mainloop//////////
    while(window.isOpen()){
        Vector2f pos=mPlayer.getPosition();
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed)
               window.close();
            }
////////////////explosion/////////
    mExplosion.setPosition(300,300);
    float Frame=0;
    float animSpeed=0.4;
    int frameCount=20;
    Frame+=animSpeed;
    if(Frame>frameCount)Frame-=frameCount;
    mExplosion.setTextureRect(IntRect(int(Frame)*50,0,50,50));
///////////////////enemy/////////////////
    Texture enemy;
    int randomflighty=rand()%1080;
    int randomflightx=rand()%(30000-1900)+1900;
    enemy.loadFromFile("enemy.png");
    enemyflight *e= new enemyflight();
    e->settings(enemy,randomflightx,randomflighty,100);
    entities.push_back(e);

////////bulletcontrol///////
    if (Keyboard::isKeyPressed(Keyboard::Space)){
        bullet *b = new bullet();
        b->settings(mbullet,(int)pos.x+81,(int)pos.y+40);
        b->sprite.setRotation(90);
        entities.push_back(b);
    }

/////////collide/////////
    for(auto a:entities)
        for(auto b:entities){
            if(a->name=="enemyflight"&&b->name=="bullet")
            if(isCollide(a,b)){
                scores+=10;
                a->life=false;
                b->life=false;
            }

    }
//////////player move/////
        if (Keyboard::isKeyPressed(Keyboard::Right)&&pos.x<=1840) mPlayer.move(5,0);
        if (Keyboard::isKeyPressed(Keyboard::Left)&&pos.x>=0) mPlayer.move(-5,0);
        if (Keyboard::isKeyPressed(Keyboard::Up)&&pos.y>=0) mPlayer.move(0,-5);
        if (Keyboard::isKeyPressed(Keyboard::Down)&&pos.y<=1000) mPlayer.move(0,5);
////////////////////////
////////////////////through////////////
    for(auto i=entities.begin();i!=entities.end();){
    Entity *e=*i;
    e->update();
    if(e->life==false){i=entities.erase(i);delete e;}
    else i++;
    }
//////////draw//////////
        window.clear();
        window.draw(mBackground);
        window.draw(mPlayer);
        for(auto i:entities) i->draw(window);
        window.draw(mExplosion);
        window.display();
        }
}




















/*#include<SFML/Graphics.hpp>
#include<time.h>
#include<list>

const int H = 800;
const int W = 1200;

using namespace sf;

class Animation{
    public:

        float Frame,speed;
        Sprite sprite;
        std::vector<IntRect> frames;

        Animation(){}

        Animation(Texture &t,int x,int y,int w,int h,int count,float Speed){
            Frame=0;
            speed=Speed;

            for(int i=0;i<count;i++)
                frames.push_back(IntRect(x+i*w,y,w,h));
                sprite.setTexture(t);
                sprite.setOrigin(w/2,h/2);
                sprite.setTextureRect(frames[0]);
        }

        void update(){
            Frame+=speed;
            int n=frames.size();
            if(Frame>=n) Frame-=n;
            if(n>0) sprite.setTextureRect(frames[int(Frame)]);
        }

};

class Entity{
    public:
        float x,y,R;
        bool life;
        std::string name;
        Animation anim;

        Entity(){life=1;}

        void settings(Animation &a,int X,int Y,int radius=1){
            x=X;y=Y; anim=a;
            R=radius;
        }

        virtual void update(){};

        void draw(RenderWindow &window){
            anim.sprite.setPosition(x,y);
            window.draw(anim.sprite);
        }
};

class bullet:public Entity{
    public:
        bullet(){
            name="bullet";
        }
        void update(){
            if(x>W||x<0||y>H||y<0) life=0;
        }
};


int main(){
    RenderWindow window(VideoMode(W,H),"AirGameFinal+1s");
    window.setFramerateLimit(60);

    Texture background,player,explosions,rock,fire;

    background.loadFromFile("background.jpg");
    player.loadFromFile("spaceship.png");
    explosions.loadFromFile("images/explosions/type_A.png");
    rock.loadFromFile("images/rock.png");
    fire.loadFromFile("images/fire_blue.png");

    Sprite mBackground(background);

    Sprite mPlayer(player);
    mPlayer.setOrigin(20,20);


    Sprite mExplosions(explosions);
    mExplosions.setPosition(300,300);


    Animation mRock(rock,0,0,64,64,16,0.2);
    Animation mBullet(fire,0,0,32,64,16,0.8);
    mRock.sprite.setPosition(400,400);


std::list<Entity*> entities;
    float Frame=0;
    float animSpeed=0.4;
    int frameCount=20;

    float x=300,y=300;


    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed){
                window.close();
            }
            if(event.type==Event::KeyPressed)
            if(event.key.code==Keyboard::Space){
                bullet *b=new bullet();
                b->settings(mBullet,x,y,10);
                entities.push_back(b);
            }
        if(Frame>frameCount) Frame-=frameCount;
        mExplosions.setTextureRect(IntRect(int(Frame)*50,0,50,50));








        Vector2f pos=mPlayer.getPosition();
        float airspeed=5;
        if(Keyboard::isKeyPressed(Keyboard::Right)&&pos.x<=1200) mPlayer.move(airspeed,0);
        if(Keyboard::isKeyPressed(Keyboard::Left)&&pos.x>=0) mPlayer.move(-airspeed,0);
        if(Keyboard::isKeyPressed(Keyboard::Up)&&pos.y>=0) mPlayer.move(0,-airspeed);
        if(Keyboard::isKeyPressed(Keyboard::Down)&&pos.y<=800) mPlayer.move(0,airspeed);

        mRock.update();

        window.clear();
        window.draw(mBackground);
        window.draw(mPlayer);
        window.draw(mExplosions);
        window.draw(mRock.sprite);
        window.display();
        }
    }
    return 0;
}
*/
