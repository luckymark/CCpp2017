#include<list>
#include<cstdlib>
#include<vector>
#include<iostream>
#include"enemy.hpp"
using namespace sf;
using namespace std;
int logistic(float score,float level);
int main()
{
    //声明速度，生命，分数,子弹伤害等级,游戏难度等级
    int life=3,score=0,power,num,level=1,max;
    int temp=0;
    float speed;
    bool p=true,clear;
    //创建窗口并限制帧数
    RenderWindow window(VideoMode(400,800), "SFML works!");
    window.setFramerateLimit(120);
    //背景，敌人，子弹，自机的纹理和图片
    Texture texture,back1,back2,ammopic,enemypic,enammopic,boompic;
    Texture enemypic2,enammopic2;
    Image image,ammop;
    boompic.loadFromFile("boom.png");
    ammop.loadFromFile("ammo2.png");
    image.loadFromFile("plane1.png");
    texture.loadFromImage(image);
    back1.loadFromFile("test.png");
    back1.setRepeated(true);
    ammopic.loadFromImage(ammop);
    enemypic.loadFromFile("enemy1.png");
    enammopic.loadFromFile("enammo2.png");
    enemypic2.loadFromFile("enemy2.png");
    enammopic2.loadFromFile("enammo.png");
    //音乐和音效设定
    Music music;
    music.openFromFile("Zektbach - L'erisia(Primal Logic).ogg");
    music.setVolume(50);
    music.setLoop(true);
    SoundBuffer enboomsound;
    enboomsound.loadFromFile("enemyboom.wav");
    Sound enemyboom(enboomsound);
    enemyboom.setVolume(20);
    music.play();

    //自机，背景，敌人，子弹,爆炸
    Sprite sprite(texture);
    sprite.setPosition(200.f,200.f);
    sprite.setOrigin(15.f,0.f);
    Sprite back; 
    back.setTexture(back1);
    back.setTextureRect(IntRect(500,50,400,700));//背景
    back.setPosition(0,100);
    Sprite boomp(boompic);
    list<enemy> ammo,en,enam,en2,enam2;   
    list<enemy>::iterator l,r;
    Event event;
    //获取运行时间用于调整射速和敌人刷新频率
    Clock amt,enet,enet2,total,ena,hurt;
    Time stop=milliseconds(3000);
    //用于显示自机剩余数量,分数和表示游戏结束
    char tex[30];
    String s;
    Font font1;
    font1.loadFromFile("sanserif.ttf");
    Text over("Game Over",font1,50);
    Text scoretext,leveltext,leastlife;
    over.setPosition(0.f,350);
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
        else speed=4;
        if(Keyboard::isKeyPressed(Keyboard::Down))if(sprite.getPosition().y+speed+32<800)sprite.move(0,speed);
        if(Keyboard::isKeyPressed(Keyboard::Right))if(sprite.getPosition().x+speed+16<400)sprite.move(speed,0);
        if(Keyboard::isKeyPressed(Keyboard::Left))if(sprite.getPosition().x+speed-16>0)sprite.move(-speed,0);
        if(Keyboard::isKeyPressed(Keyboard::Up))if(sprite.getPosition().y+speed>100)sprite.move(0,-speed);
        //自机子弹
        if(Keyboard::isKeyPressed(Keyboard::Z)&&amt.getElapsedTime().asMilliseconds()>80)
        {
           if(!ammo.empty())
           {

               for(l=ammo.begin();l!=ammo.end();l++)
               {
                   if(!l->check())
                   {
                       l->useful(sprite.getPosition().x,sprite.getPosition().y,2+power);
                       p=0;
                       break;

                   }
               }
           }
            if(p)
            {
                ammo.push_back(enemy(ammopic,12,12,1,2+power));
                l=--ammo.end();
                l->useful(sprite.getPosition().x,sprite.getPosition().y,2+power);
                l->speedset(0.f,-5.f);
            }
            amt.restart();
        }
        if(!ammo.empty())
        {
            for(l=ammo.begin();l!=ammo.end();l++)l->movable();
        }
        //普通敌人
        if(enet.getElapsedTime().asMilliseconds()>500)
        {
            p=1;
            srand(total.getElapsedTime().asMilliseconds());
            max=8+level*3+score/1000;
            num=rand()%max;//随机产生敌机量
            for(int j=0;j<num;j++)
            {
                
                if(!en.empty())
                {
                    l=en.begin();
                    for(l=en.begin();l!=en.end();l++)
                    {
                            if(!l->check())
                            {
                                l->useful(rand()%(400-32),100.f,3);
                                p=0;
                                l->restart();
                                break;
                            }
                    }
                }
                if(p)
                {
                    en.push_back(enemy(enemypic,32,32,3,3));
                    l=--en.end();
                    srand(total.getElapsedTime().asMilliseconds());
                    l->useful(rand()%(400-32),100.f,3);
                    l->speedset(0.f,3.f);
                }  
            }
            enet.restart();
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
                if(l->getElapsedTime().asMilliseconds()>300&&l->check())
                {
                        for(r=enam.begin();r!=enam.end();r++)
                        {
                            if(!r->check())
                            {
                                r->useful(l->getPosition().x,l->getPosition().y,1);
                                p=0;break;
                            }

                        }
                        if(p)
                        {
                            enam.push_back(enemy(enammopic,12,12,2,1));
                            r=--enam.end();
                            r->useful(l->getPosition().x,l->getPosition().y,1);
                            r->speedset(0.f,5.f);
                        }
                    l->restart();
                }
            }
        }
        if(!enam.empty())
        {
            for(l=enam.begin();l!=enam.end();l++)l->movable();
        }
        //等级2开始出现的新敌人
        if(level>1)
        {
            if(enet2.getElapsedTime().asMilliseconds()>10000)
            {
                if(!en2.empty())
                {
                    l=en2.begin();
                    for(l=en2.begin();l!=en2.end();l++)
                    {
                            if(!l->check())
                            {
                                l->useful(rand()%(400-117),100.f,3);
                                p=0;
                                l->restart();
                                break;
                            }
                    }
                }
                if(p)
                {
                    en2.push_back(enemy(enemypic2,32,32,3,50));
                    l=--en2.end();
                    srand(total.getElapsedTime().asMilliseconds());
                    l->useful(rand()%(400-117),100.f,50);
                    l->speedset(1.f,0.f);
                }
            }
            enet2.restart();
        }
        if(!en2.empty())
        {
            for(l=en2.begin();l!=en2.end();l++)
            {
                l->movable();
                if(l->getPosition().x<0)l->speedset(-1.f,0.f);
                if(l->getPosition().y>400-128)l->speedset(1.f,0.f);
            }
        }
        //2级新敌人子弹
        if(!en2.empty())
        {

            if(enet2.getElapsedTime().asMilliseconds()>500)
            for(l=en2.begin();l!=en2.end();l++)
            {
                for(int i=0;i<3;i++)
                {
                    p=1;
                    if(l->getElapsedTime().asMilliseconds()>500&&l->check())
                    {
                            for(r=enam2.begin();r!=enam2.end();r++)
                            {
                                if(!r->check())
                                {
                                    r->useful(l->getPosition().x,l->getPosition().y,1);
                                    p=0;break;
                                }

                            }
                            if(p)
                            {
                                enam2.push_back(enemy(enammopic2,12,12,2,1));
                                r=--enam2.end();
                                r->useful(l->getPosition().x,l->getPosition().y,1);
                                r->speedset(0.f,10.f);
                            }
                    }
                    l->restart();
                }
            }
            if(enet2.getElapsedTime().asMilliseconds()>1001)enet.restart();
        }
        if(!enam2.empty())
        {
            for(l=enam2.begin();l!=enam2.end();l++)l->movable();
        }
        //展示分数，等级，剩余生命
        sprintf(tex,"Score:%d",score);
        s=String(tex);
        scoretext=Text(s,font1,20);
        scoretext.setPosition(0.f,50.f);
        sprintf(tex,"level%d",level);
        s=String(tex);
        leveltext=Text(s,font1,20);
        leveltext.setPosition(120.f,50.f);
        sprintf(tex,"life:%d",life);
        s=String(tex);
        leastlife=Text(s,font1,20);
        leastlife.setPosition(300.f,50.f);
        //绘制
        window.clear();
        window.draw(back);
        window.draw(leastlife);
        window.draw(leveltext);
        window.draw(scoretext);
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
        if(!en2.empty())
        for(l=en2.begin();l!=en2.end();l++)
        {
            if(l->check())window.draw(*l);
        }
        if(!enam.empty())
        for(l=enam.begin();l!=enam.end();l++)
        {
            if(l->check())window.draw(*l);
        }
        if(!enam2.empty())
        for(l=enam2.begin();l!=enam2.end();l++)
        {
            if(l->check())window.draw(*l);
        }       
        window.display(); 
        //自机子弹击中敌机
        if(!en.empty()&&!ammo.empty())
        for(l=en.begin();l!=en.end();l++)
        {
            for(r=ammo.begin();r!=ammo.end();r++)
            {  
                if(r->check()&&l->check())
                if(r->getGlobalBounds().intersects(l->getGlobalBounds()))
                {
                    int p=l->give();
                    l->hit(r->give());
                    r->hit(p);
                    enemyboom.play();
                    boomp.setPosition(l->getPosition().x,l->getPosition().y);
                    window.draw(boomp);
                    score+=50;
                    break;
                }
            }
        }
        //判定伤害等级,难度等级,生命奖励
        power=1+score/300;
        if(score/1000>temp)
        {
            life+=score/1000-temp;
            temp=score/1000;
        }
        if(level<3)level=1+score/1000;
        cout<<life<<endl;
        //自机被击中
        if(hurt.getElapsedTime().asMilliseconds()>500)
        {
            for(l=enam.begin();l!=enam.end();l++)
            {
                if(l->check())
                if(sprite.getGlobalBounds().intersects(l->getGlobalBounds()))
                {
                    life--;
                    break;
                    cout<<life<<endl;
                    l->change(0);
                }
            }
            hurt.restart();
        }
        if(life<=0)
        {
            boomp.setPosition(sprite.getPosition().x,sprite.getPosition().y);
            window.draw(boomp);
            window.draw(over);
            window.display();
            sleep(stop);
            break;
        }
        
    }

    return 0;
}

