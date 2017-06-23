#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <list>
#include <iostream>
#include <deque>
#include <windows.h>

using namespace sf;
int amount=50;
int scores=0;
float playerSpeed=10;
int EnemySpeed=2;
int level=1;
int yourlife=3;
int bulletspeed=7;
int ebulletspeed=5;
void musicplay(Music &t,std::string musicname,bool isLoop,bool pause=false){
        t.openFromFile(musicname);
        t.play();
        t.setLoop(isLoop);
        if(pause==true){
            t.pause();
        }
}

bool beginwindow(){
    RenderWindow window(VideoMode(1200,630),"AirGameFinal");
        while(window.isOpen()){
            Event event;
            while(window.pollEvent(event)){
                if(event.type==Event::Closed)
                    window.close();
                if(Keyboard::isKeyPressed(Keyboard::Space)){
                    return true;
                    window.close();
                }
            }
            Texture beginwindow;
            beginwindow.loadFromFile("begin.jpg");
            Sprite sprite(beginwindow);
            Font font;
            font.loadFromFile("pixelmix.ttf");
            Text text;
            text.setFont(font);
            text.setPosition(300,400);
            text.setString("Press Space To Enter Game");
        window.clear();
        window.draw(sprite);
        window.draw(text);
        window.display();
        }
}

class Entity{
    public:
        float x,y,R;
        bool life;
        std::string name;
        Sprite sprite;
        Entity(){life=1;}
        void settings(Texture &t,int X,int Y,int radius=1){
            sprite.setTexture(t);
            x=X;
            y=Y;
            R=radius;
        }

        virtual void update(){};

        void draw(RenderWindow &window){
            sprite.setPosition(x,y);
            window.draw(sprite);
        }

        virtual ~Entity(){};
};

class enemyflight: public Entity{
    public:
        enemyflight(){name="enemyflight";}

        void update(){
            y+=EnemySpeed;
            if(y>1080){
                life=false;
            }
        }
};




class bullet:public Entity{
    public:
    bullet(){name="bullet";}

    void update(){
        y-=bulletspeed;
        /////sidemanage/////
        if(y<0){
            life=false;
        }
    }
};

class ebullet:public Entity{
    public:
    ebullet(){name="ebullet";}

    void update(){
        y+=ebulletspeed;
        /////sidemanage/////
        if(y>1080){
            life=false;
        }
    }
};

class player:public Entity{
    public:
    player(){name="player";}
    void update(){

    }
};
bool isCollide(Entity *a,Entity *b){
    return (b->x - a->x)*(b->x - a->x)+
         (b->y - a->y)*(b->y - a->y)<
         (a->R + b->R)*(a->R + b->R);
}

class Game{
    public:
        Font font;

        void over(){
            Texture texture;
            texture.loadFromFile("gameover.jpg");
            Sprite sprite(texture);
            Text text;
            text.setFont(font);
            text.setString("Press Space");
            text.setPosition(125,150);
            RenderWindow window(VideoMode(500,200),"AirGameFinal");
            while(window.isOpen()){
                Event event;
                while(window.pollEvent(event)){
                    if(event.type==Event::Closed)
                        window.close();
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Space)){
                        window.close();
                    }
                window.clear();
                window.draw(sprite);
                window.draw(text);
                window.display();
            }
        }

        void run(){

            srand(time(0));


            RenderWindow window(VideoMode(1000,1080),"AirGameFinal");
            window.setFramerateLimit(60);



            Texture eBullet;
            eBullet.loadFromFile("ebullet.png");

            Texture Background,Player;
            Player.loadFromFile("player.png");

            Background.loadFromFile("background.jpg");
            Sprite mBackground(Background);

            Texture mbullet;
            mbullet.loadFromFile("bullet.png");

            Texture enemy;
            enemy.loadFromFile("enemy.png");

            Texture explosion;
            explosion.loadFromFile("explosion.png");

            font.loadFromFile("pixelmix.ttf");

            Text text;
            text.setFont(font);
            text.setPosition(600,0);
            text.setString("Scores");

            Text text1;
            text1.setFont(font);
            text1.setPosition(750,0);

            Text text2;
            text2.setFont(font);
            text2.setString("Level");
            text2.setPosition(600,100);

            Text Level;
            Level.setFont(font);
            Level.setPosition(750,100);

            Text text3;
            text3.setFont(font);
            text3.setString("Life");
            text3.setPosition(600,200);

            Text life;
            life.setFont(font);
            life.setPosition(700,200);

            Music backgroundmusic;
            Music explosionsound;
            musicplay(backgroundmusic,"backgroundmusic.ogg",true);


            std::deque<Entity*> entities;

            player *p = new player();
            p->sprite.setOrigin(32,32);
            p->settings(Player,260,900,32);
            entities.push_back(p);


                while(window.isOpen()){
                    Event event;
                    while(window.pollEvent(event)){
                        if(event.type==Event::Closed)
                            window.close();
                        if (event.type == Event::KeyPressed)
                        if (event.key.code == Keyboard::Space){
                            bullet *b = new bullet();
                            bullet *c = new bullet();
                            b->settings(mbullet,p->x-30,p->y-30,1);
                            c->settings(mbullet,p->x+30,p->y-30,1);
                            entities.push_back(b);
                            entities.push_back(c);
                        }

                    }


                    if (Keyboard::isKeyPressed(Keyboard::Down)&&p->y<=980){p->y+=playerSpeed;}
                    if (Keyboard::isKeyPressed(Keyboard::Up)&&p->y>=0){p->y-=playerSpeed;}
                    if (Keyboard::isKeyPressed(Keyboard::Left)&&p->x>=100){p->x-=playerSpeed;}
                    if (Keyboard::isKeyPressed(Keyboard::Right)&&p->x<=500){p->x+=playerSpeed;}


                    int randomflighty=rand()%(100)+50;
                    int randomflightx=rand()%(400)+100;

                    if(clock()%amount==0){

                    enemyflight *e= new enemyflight();
                    e->sprite.setOrigin(100,100);
                    e->settings(enemy,randomflightx,randomflighty,100);
                    entities.push_back(e);

                    ebullet *a = new ebullet();
                    a->settings(eBullet,e->x,e->y,1);
                    entities.push_back(a);
                    }

                    for(auto a:entities)
                    for(auto b:entities){
                        if(a->name=="enemyflight"&&b->name=="bullet")
                        if(isCollide(a,b)){
                            a->life=false;
                            b->life=false;
                            scores+=10;
                            musicplay(explosionsound,"explosionsound.ogg",false);
                        }

                        if(a->name=="ebullet"&&b->name=="player"){
                            if(isCollide(a,b)){
                                a->life=false;
                                yourlife-=1;
                            }
                        }
                        if(a->name=="enemyflight"&&b->name=="player"){
                            if(isCollide(a,b)){
                                a->life=false;
                                yourlife-=1;
                            }
                        }
                        if(scores%100==0&&scores>=100){
                            EnemySpeed=2*(int)scores/100;
                            ebulletspeed=EnemySpeed+3;
                        }

                    }

                    text1.setString(std::to_string(scores));
                    Level.setString(std::to_string(level));
                    level=EnemySpeed/2;
                    life.setString(std::to_string(yourlife));

                    for(auto i=entities.begin();i!=entities.end();){
                        Entity *e=*i;
                        e->update();
                        if(e->life==false){i=entities.erase(i);delete e;}
                        else i++;
                    }
                    if(yourlife==0){
                        window.close();
                        musicplay(backgroundmusic,"backgroundmusic.ogg",true,true);
                        over();
                    }
                    window.clear();
                    window.draw(mBackground);
                    for(auto i:entities){i->draw(window);}
                    window.draw(text);
                    window.draw(text1);
                    window.draw(text2);
                    window.draw(Level);
                    window.draw(text3);
                    window.draw(life);
                    window.display();

                }

        }

};


