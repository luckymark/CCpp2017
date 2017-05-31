#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<list>
using namespace sf;
using namespace std;
class enemy:public Sprite
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
            if(type==1)speed=-5;
            else if(type==2)speed=5;
            else speed=2;
        }
        void movable()
        {
            if(live==true)move(0,-5);
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
        }
};
int main()
{
    float speed;
    int ammonum=1;
    bool p;
    //创建窗口并限制帧数
    RenderWindow window(VideoMode(400,800), "SFML works!");
    window.setFramerateLimit(120);
    //背景，敌人，子弹，自机的纹理和图片
    Texture texture,back1,ammopic;
    Image image,ammop;
    ammop.create(3.f,3.f,Color::Black);
    image.loadFromFile("test.png");
    texture.loadFromImage(image,IntRect(0,0,50,50));
    back1.loadFromFile("test.png");
    back1.setRepeated(true);
    ammopic.loadFromImage(ammop);
    //音乐和音效设定
    Music music;
    music.openFromFile("Zektbach - L'erisia(Primal Logic).ogg");
    music.setVolume(50);
    music.setLoop(true);
    //music.play();

    //自机，背景，敌人，子弹
    Sprite sprite(texture);
    sprite.setPosition(200.f,200.f);
    Sprite back,ammodraw;
    back.setTexture(back1);
    back.setTextureRect(IntRect(1000,100,400,800));
    list<enemy> ammo;   
    list<enemy>::iterator l;
    Event event;
    while (window.isOpen())
    {
        p=1;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        //移动
        if(Keyboard::isKeyPressed(Keyboard::LShift))speed=0.5;
        else speed=5;
        if(Keyboard::isKeyPressed(Keyboard::S))if(sprite.getPosition().y+speed+50<800)sprite.move(0,speed);
        if(Keyboard::isKeyPressed(Keyboard::D))if(sprite.getPosition().x+speed+50<400) sprite.move(speed,0);
        if(Keyboard::isKeyPressed(Keyboard::A))if(sprite.getPosition().x+speed>0)sprite.move(-speed,0);
        if(Keyboard::isKeyPressed(Keyboard::W))if(sprite.getPosition().y+speed>0)sprite.move(0,-speed);
        //自机子弹
        if(Keyboard::isKeyPressed(Keyboard::J))
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
                ammo.push_back(enemy(ammopic,3,3,1));
                l=--ammo.end();
                l->useful(sprite.getPosition().x,sprite.getPosition().y);
            }
        }
        if(!ammo.empty())
        {
            for(l=ammo.begin();l!=ammo.end();l++)l->movable();
        }
        
        window.clear();
        window.draw(back);
        window.draw(sprite);
        if(!ammo.empty())
        for(l=ammo.begin();l!=ammo.end();l++)
        {
            if(l->check())window.draw(*l);
        }
        window.display();
    }

    return 0;
}