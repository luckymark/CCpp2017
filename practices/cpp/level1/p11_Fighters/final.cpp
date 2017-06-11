#include <SFML/Graphics.hpp>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>
#include <time.h>
const    float window_size_x=512;
const    float window_size_y=652;
sf::RenderWindow window(sf::VideoMode(window_size_x,  window_size_y), "My window");
sf::Sound boom_muc;

sf::Texture texture_bullet;
sf::Texture texture_boom;
sf::Texture texture_plane_me;
sf::Texture texture_plane_enemy;
int score=0;
int level=1;
bool bo_win=0;
const int mod[7]={0,13*17,200,160,120,100,80};


struct BackGround{
    sf::Sprite sprite;
    sf::Texture textrure;
    void prepare(){
    textrure.loadFromFile("background2.jpg");
    textrure.setSmooth(true);
    sprite.setTexture(textrure);
    sprite.setTextureRect(sf::IntRect(0, 0, 640, 1336));
    float scale_x=window_size_x/640;
    float scale_y=window_size_y/1136;
    sprite.scale(sf::Vector2f(scale_x,scale_y));
    }
};


struct bullet{
    float size_x,size_y;
    float speed;
    bool is_friend;
    sf::Sprite sprite;
    bullet(){
    }

    bullet(bool in_is_friend,float in_size_x,float in_size_y,float scale_f,float v){
    speed=v;
    is_friend=in_is_friend;
    sprite.setTexture(texture_bullet);
    //sprite.setTextureRect(sf::IntRect(0, 0, in_size_x,in_size_y));
    sprite.setTextureRect(sf::IntRect(in_size_x/5, 0, in_size_x/5*4,in_size_y));
    in_size_x=in_size_x/5*3;
    if (!is_friend)
    {
        in_size_x=-in_size_x;
        in_size_y=-in_size_y;
    }
    sprite.scale(sf::Vector2f(scale_f,scale_f));
    size_x=scale_f*(in_size_x);
    size_y=scale_f*(in_size_y);
    }

    void Go(){
        sprite.move(0,speed);
    }
};

std::vector<bullet*> B_enemy;
std::vector<bullet*> B_me;
sf::Clock clock_st;

struct plane{
    float size_x,size_y;
    float speed;
    bool is_friend;
    int life;
    INT32 t_prefire;
    sf::Sprite sprite;
    plane(){
    }

    plane(bool in_is_friend,float in_size_x,float in_size_y,float scale_f){
    is_friend=in_is_friend;
    if (is_friend)
        {
            sprite.setTexture(texture_plane_me);
            life=3;
        }
    else
        {
            sprite.setTexture(texture_plane_enemy);
            life=1;
        }
    sprite.setTextureRect(sf::IntRect(0, 0, in_size_x,in_size_y));
    sprite.scale(sf::Vector2f(scale_f,scale_f));
    size_x=scale_f*in_size_x;
    size_y=scale_f*in_size_y;
    if (!is_friend)
    {
        size_x=-size_x;
        size_y=-size_y;
    }
    t_prefire=0;
    }



    void fire(){
        sf::Time Time1=clock_st.getElapsedTime();
        sf::Int32 t1=Time1.asMilliseconds();
        float pos_x=sprite.getPosition().x,pos_y=sprite.getPosition().y;

        if (!is_friend)
            {
                if (t1-t_prefire<1000/(1+(level-1)*0.1))
                    return;
            }
        else
            if (t1-t_prefire<80)
                return;
        if ((!is_friend)||(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
        {

            bullet *T;
            float V;
            if (is_friend)
                V=-0.5;
            else
                V=0.5;
            if (!is_friend)
                V=V*(1+(level-1)*0.1);
            T=new bullet(is_friend,512,512,0.05,V);
            (*T).sprite.setPosition(sf::Vector2f(pos_x+size_x/2-(*T).size_x/2,pos_y));
            t_prefire=t1;
            if (is_friend)
                B_me.push_back(T);
            else
                {
                    (*T).sprite.rotate(180);
                    B_enemy.push_back(T);
                }
        }
    }

    void Go(){
        float pos_x=sprite.getPosition().x,pos_y=sprite.getPosition().y;
        if (!is_friend)
            {
                sprite.move(0,speed);
                return;
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (pos_x-speed>1e-7)
                {
                    sprite.move(-speed, 0);
                    pos_x+=-speed;
                }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (pos_x+size_x+speed<window_size_x+1e-7)
                {
                    sprite.move(speed, 0);
                    pos_x+=speed;
                }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (pos_y-speed>1e-7)
                {
                    sprite.move(0,-speed);
                    pos_y+=-speed;
                }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (pos_y+speed+size_y<window_size_y+1e-7)
                {
                    sprite.move(0,speed);
                    pos_y+=speed;
                }
        }
    }
}me;


bool check_in(float X,float Y,float x1,float y1,float x2,float y2){
if ((X>x1)&&(X<x2))
    if ((Y>y1)&&(Y<y2))
        return 1;
return 0;
}


bool check_impact(float x1,float y1,float x2,float y2,float XX1,float YY1,float XX2,float YY2){
if (check_in(x1,y1,XX1,YY1,XX2,YY2))
    return 1;
if (check_in(x1,y2,XX1,YY1,XX2,YY2))
    return 1;
if (check_in(x2,y1,XX1,YY1,XX2,YY2))
    return 1;
if (check_in(x2,y2,XX1,YY1,XX2,YY2))
    return 1;

if (check_in(XX1,YY1,x1,y1,x2,y2))
    return 1;
if (check_in(XX1,YY2,x1,y1,x2,y2))
    return 1;
if (check_in(XX2,YY1,x1,y1,x2,y2))
    return 1;
if (check_in(XX2,YY2,x1,y1,x2,y2))
    return 1;
//printf("%.2lf  %.2lf  %.2lf  %.2lf %.2lf  %.2lf  %.2lf  %.2lf\n",x1,y1,x2,y2,XX1,YY1,XX2,YY2);
return 0;
}

std::vector< plane*> P;


struct Boom{
    sf::Sprite sprite;
    float scale_f;
    Boom(float x,float y,float in_scale_f){
    scale_f=in_scale_f;
    sprite.setTexture(texture_boom);
    sprite.setTextureRect(sf::IntRect(0, 0, 256,256));
    sprite.scale(sf::Vector2f(scale_f,scale_f));
    sprite.setPosition(x,y);
    }
};
std::vector< Boom* > boom;

void Boom_go(){
for (std::vector<Boom*>::iterator I=boom.begin();I!=boom.end();I++)
    {
        if ((**I).scale_f<1)
            {
                window.draw((**I).sprite);
                (**I).scale_f+=0.01;
                (**I).sprite.scale(1.003,1.003);
            }
        else
        {
            delete((*I));
            boom.erase(I);
            I--;
        }
    }
}
//std::vector< int* > P;

void Plane_go(){
for (std::vector<plane*>::iterator I=P.begin();I!=P.end();I++)
            {
                if ( ( ( **I ).sprite.getPosition().y>0 ) &&((**I).sprite.getPosition().y<window_size_y))
                    {
                        (**I).Go();
                        (**I).fire();

                        float p_x1=me.sprite.getPosition().x; float p_x2=p_x1+me.size_x;
                        float p_y1=me.sprite.getPosition().y; float p_y2=p_y1+me.size_y;

                        float b_x1=(**I).sprite.getPosition().x; float b_x2=b_x1+(**I).size_x;
                        float b_y1=(**I).sprite.getPosition().y; float b_y2=b_y1+(**I).size_y;

                        if (check_impact(b_x1,b_y1,b_x2,b_y2,p_x1,p_y1,p_x2,p_y2))
                            {
                                me.life--;
                                printf("You have %d lives leaved.\n",me.life);
                                if (me.life==0)
                                {
                                    puts("DEAD");
                                    window.close();
                                }
                                Boom *b1=new Boom( p_x1, p_y1 , 0.1f);
                                boom.push_back(b1);
                                (**I).sprite.setPosition(1000,1000);
                                //Sleep(100);
                                boom_muc.play();
                                break;
                            }
                        window.draw((**I).sprite);
                    }
                else
                {
                    delete (*I);
                    P.erase(I);
                    I--;
                }
            }
}


void Bullet_go(){
for (std::vector<bullet*>::iterator I=B_me.begin();I!=B_me.end();I++)
            {
                if (((**I).sprite.getPosition().y>0)&&((**I).sprite.getPosition().y<window_size_y))
                    {
                        for (std::vector<plane*>::iterator J=P.begin();J!=P.end();J++)
                            {
                                float p_x2=(**J).sprite.getPosition().x; float p_x1=p_x2+(**J).size_x;
                                float p_y2=(**J).sprite.getPosition().y; float p_y1=p_y2+(**J).size_y;

                                float b_x1=(**I).sprite.getPosition().x; float b_x2=b_x1+(**I).size_x;
                                float b_y1=(**I).sprite.getPosition().y; float b_y2=b_y1+(**I).size_y;
                                if (check_impact(b_x1,b_y1,b_x2,b_y2,p_x1,p_y1,p_x2,p_y2))
                                    {
                                        (**J).sprite.setPosition(1000,1000);
                                        (**I).sprite.setPosition(1000,1000);
                                        score++;
                                        printf("score: %d",score);
                                        if (score==30*level)
                                        {
                                            level++;
                                            if (level==7)
                                            {
                                                puts("YOU WIN!!");
                                                bo_win=1;
                                                return ;
                                            }
                                            printf("    level:%d\n",level);
                                        }
                                        else
                                            puts("");
                                        Boom* b1=new Boom(p_x1, p_y1 , 0.1f);
                                        boom_muc.play();
                                        boom.push_back(b1);
                                        break;
                                    }
                                //printf("%.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf\n",b_x1,b_y1,b_x2,b_y2,p_x1,p_y1,p_x2,p_y2);
                                //Sleep(100);
                            }
                        (**I).Go();
                        window.draw((**I).sprite);
                    }
                else
                {
                    delete (*I);
                    B_me.erase(I);
                    I--;
                }
            }
for (std::vector<bullet*>::iterator I=B_enemy.begin();I!=B_enemy.end();I++)
            {
                if (((**I).sprite.getPosition().y>0)&&((**I).sprite.getPosition().y<window_size_y))
                    {
                        float p_x1=me.sprite.getPosition().x; float p_x2=p_x1+me.size_x;
                        float p_y1=me.sprite.getPosition().y; float p_y2=p_y1+me.size_y;

                        float b_x2=(**I).sprite.getPosition().x; float b_x1=b_x2+(**I).size_x;
                        float b_y2=(**I).sprite.getPosition().y; float b_y1=b_y2+(**I).size_y;
                        if (check_impact(b_x1,b_y1,b_x2,b_y2,p_x1,p_y1,p_x2,p_y2))
                            {
                                Boom* b1=new Boom(p_x1, p_y1 , 0.1f);
                                boom.push_back(b1);
                                me.life--;
                                printf("You have %d lives leaved.\n",me.life);
                                if (me.life==0)
                                {
                                    puts("DEAD");
                                    window.close();
                                }
                                (**I).sprite.setPosition(1000,1000);
                                //Sleep(100);
                                boom_muc.play();
                                break;
                            }
                        (**I).Go();
                        window.draw((**I).sprite);
                    }
                else
                {
                    //puts("aaaaaaaaaaa");
                    delete (*I);
                    B_enemy.erase(I);
                    I--;
                }
            }
}

int main()
{
    BackGround background;
    background.prepare();
    puts("Music is loading,please wait.");
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("bgm.wav"))
        return -1;
    sf::Sound bgm;
    bgm.setBuffer(buffer);
    bgm.play();

    if (!buffer.loadFromFile("boom.wav"))
        return -1;
    boom_muc.setBuffer(buffer);
    puts("Music has been loaded.");

    texture_plane_me.loadFromFile("me.png");
    texture_plane_me.setSmooth(true);
    texture_plane_enemy.loadFromFile("enemy.png");
    texture_plane_enemy.setSmooth(true);
    texture_bullet.loadFromFile("bullet.png");
    texture_bullet.setSmooth(true);
    texture_boom.loadFromFile("boom.png");
    texture_boom.setSmooth(true);

    me=plane(1,512,512,0.08);
    me.sprite.setPosition(window_size_x/2,window_size_y-me.size_y);
    me.speed=0.5;
    // run the program as long as the window is open
    sf::Time Time1=clock_st.getElapsedTime();
    //sf::Int32 t1=Time1.asMilliseconds();
    int t1=(int)Time1.asMilliseconds();
    //printf("%d\n",t1);

    int sum=0;
    srand((int)time(0));
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        me.Go();
        sf::Time Time2=clock_st.getElapsedTime();
        //sf::Int32 t2=(int)Time2.asMilliseconds();
        int t2=(int)Time2.asMilliseconds();
        //if((t2-t1+rand()%300)%mod[level]==0)
        if(rand()%mod[level]==0)
        //if (sum==1)
        {
            //printf("%d %d\n",t1,t2);
            Sleep(1);
            plane* enemy=new plane(0,512,512,0.07);
            (*enemy).sprite.setPosition((t2+rand()%1000)%((int)window_size_x+(int)(*enemy).size_x)-(*enemy).size_x,(int)(-(*enemy).size_y));
            //(*enemy).sprite.setPosition(223,223);
            (*enemy).sprite.rotate(180);
            //sum++;
            (*enemy).speed=0.3*(1+(level-1)*0.1);
            P.push_back(enemy);
        }
        window.draw(background.sprite);
        window.draw(me.sprite);
        me.fire();
        Plane_go();
        Bullet_go();
        Boom_go();
        //printf("%d\n",score);
        //printf("%d  %d\n",B_me.size(),P.size());
        window.display();
        if (bo_win)
            break;
    }
    system("pause");
    return 0;
}
