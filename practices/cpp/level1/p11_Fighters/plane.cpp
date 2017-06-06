#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<list>
#include<cstdlib>
using namespace sf;
using namespace std;
class enemy:public Sprite, public Clock
{
    private:
        int hight;
        int width;
        bool live;
        int type;//1为自身子弹，2为敌人子弹，3为敌人
        int speed;
    public:
        enemy(const Texture & texture,int hight,int width,int type)
        {
            setTexture(texture);
            live=false;
            this->hight=hight;
            this->width=width;
            this->type=type;
            if(type==1)speed=-10;
            else if(type==2)
            {
                speed=5;
                restart();
            }
            else speed=2;
        }
        void movable()
        {
            if(live==true)
            switch(type)
            {
                case 1 :move(0.f,-5.f);break;
                case 2 :move(0.f,5.f);break;
                case 3 :move(0.f,3.f);break;
            }
        }
        bool check()
        {
            if(type==1&&getPosition().y+hight<=0)live=false;
            else if(getPosition().y>=800)live==false;
            return live;
        }
        void useful(double x,double y)
        {
            live=true;
            setPosition(x,y);
            if(type==2)restart();
        }
};
int main()
{
    float speed;
    bool p;
    //创建窗口并限制帧数
    RenderWindow window(VideoMode(400,800), "SFML works!");
    window.setFramerateLimit(120);
    //背景，敌人，子弹，自机的纹理和图片
    Texture texture,back1,ammopic,enemypic,enammopic;
    Image image,ammop;
    ammop.loadFromFile("ammo.png");
    image.loadFromFile("plane1.png");
    texture.loadFromImage(image);
    back1.loadFromFile("test.png");
    back1.setRepeated(true);
    ammopic.loadFromImage(ammop);
    enemypic.loadFromFile("enemy1.png");
    enammopic.loadFromFile("enammo.png");
    //音乐和音效设定
    Music music;
    music.openFromFile("Zektbach - L'erisia(Primal Logic).ogg");
    music.setVolume(50);
    music.setLoop(true);
    //music.play();

    //自机，背景，敌人，子弹
    Sprite sprite(texture);
    sprite.setPosition(200.f,200.f);
    sprite.setOrigin(16.f,0.f);
    Sprite back;
    back.setTexture(back1);
    back.setTextureRect(IntRect(1000,100,400,800));//背景
    list<enemy> ammo,en,enam;   
    list<enemy>::iterator l,r;
    Event event;
    //获取运行时间用于调整射速和敌人刷新频率
    Clock amt,enet,total;
    while (window.isOpen())
    {
        p=1;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        //移动
        if(Keyboard::isKeyPressed(Keyboard::LShift))speed=1.0;
        else speed=5;
        if(Keyboard::isKeyPressed(Keyboard::Down))if(sprite.getPosition().y+speed+32<800)sprite.move(0,speed);
        if(Keyboard::isKeyPressed(Keyboard::Right))if(sprite.getPosition().x+speed+16<400) sprite.move(speed,0);
        if(Keyboard::isKeyPressed(Keyboard::Left))if(sprite.getPosition().x+speed-16>0)sprite.move(-speed,0);
        if(Keyboard::isKeyPressed(Keyboard::Up))if(sprite.getPosition().y+speed>0)sprite.move(0,-speed);
        //自机子弹
        if(Keyboard::isKeyPressed(Keyboard::Z)&&amt.getElapsedTime().asMilliseconds()>50)
        {
           if(!ammo.empty())
           {

               for(l=ammo.begin();l!=ammo.end();l++)
               {
                   if(!l->check())
                   {
                       l->useful(sprite.getPosition().x,sprite.getPosition().y);
                       p=0;
                       break;

                   }
               }
           }
            if(p)
            {
                ammo.push_back(enemy(ammopic,12,12,1));
                l=--ammo.end();
                l->useful(sprite.getPosition().x,sprite.getPosition().y);

            }
            amt.restart();
        }
        if(!ammo.empty())
        {
            for(l=ammo.begin();l!=ammo.end();l++)l->movable();
        }

        //敌人
        if(enet.getElapsedTime().asMilliseconds()>500)
        {
            p=1;
            srand((int)total.getElapsedTime().asMilliseconds());
            int num=rand()%10;
            for(int i=0;i<num;i++)
            {
                
                if(!en.empty())
                {
                    
                    for(l=en.begin();l!=en.end();l++)
                    {
                            if(!l->check())
                            {
                                l->useful(rand()%(400-32),0.f);
                                p=0;
                                break;
                            }
                            
                    }
                }
                if(p)
                {
                    en.push_back(enemy(enemypic,32,32,3));
                    l=--en.end();
                    l->useful(rand()%(400-32),0.f);

                } 
                enet.restart();
            }
         }
        if(!en.empty())
        {
            for(l=en.begin();l!=en.end();l++)l->movable();
        }
        //敌方子弹
        if(!en.empty())
        {
            for(l=en.begin();l!=en.end();l++)
            {
                p=1;
                if((int)l->getElapsedTime().asMilliseconds()>100&&l->check())
                {
                    if(!enam.empty())
                    {
                        for(r=enam.begin();r!=enam.end();r++)
                        {
                            if(!r->check())
                            {
                                r->useful(l->getPosition().x,l->getPosition().y);
                                p=0;break;
                            }

                        }
                        if(p)
                        {
                            enam.push_back(enemy(enammopic,12,12,2));
                            r=--enam.end();
                            r->useful(l->getPosition().x,l->getPosition().y);
                        }
                    }
                }
            }
        }
        if(!enam.empty())
        {
            for(l=enam.begin();l!=enam.end();l++)l->movable();
        }
        //绘制
        window.clear();
        window.draw(back);
        window.draw(sprite);
        if(!ammo.empty())
        for(l=ammo.begin();l!=ammo.end();l++)
        {
            if(l->check())window.draw(*l);
        }
        if(!en.empty())
        for(l=en.begin();l!=en.end();l++)
        {
            if(l->check())window.draw(*l);
        }
        if(!enam.empty())
        for(l=enam.begin();l!=enam.end();l++)
        {
            if(l->check())window.draw(*l);
        }
        window.display();
    }

    return 0;
}