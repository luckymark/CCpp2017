#ifndef ENEMY_H
#define ENEMY_H
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
using namespace sf;
class enemy:public Sprite, public Clock
{
    private:
        int hight;
        int width;
        int life;
        int type;//1为自身子弹，2为敌人子弹，3为敌人
        float movex,movey;
    public:
        enemy(const Texture & texture,int hight,int width,int type,int life)
        {
            setTexture(texture);
            this->life=life;
            this->hight=hight;
            this->width=width;
            this->type=type;
        }
        void movable()
        {
            if(life>0)
            move(movex,movey);
        }
        bool check()
        {
            if(type==1&&getPosition().y+hight<=100)life=0;
            else if(getPosition().y>=800)life==0;
            return life>0;
        }
        void hit(int hit)
        {
            life-=hit;
        }
        void  change(int s)
        {
            life=s;
        }
        int give()
        {
            return life;
        }
        void useful(double x,double y,int life)
        {
            this->life=life;
            setPosition(x,y);
            if(type==2)restart();
        }
        void speedset(float x,float y)
        {
            movex=x;
            movey=y;
        }
};
#endif
#include<cmath>
