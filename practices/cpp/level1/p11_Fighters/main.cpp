#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <vector>

//for debug
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int STAGE_X=540;
const int STAGE_Y=720;
const int PLANE_L=64;
const int FIRE_L=32;


void handlePlayerInput(sf::Keyboard::Key, bool);
void update();
void fire();
void spawnEnemy();
void boom(sf::Vector2f);
void fireenemy(sf::Vector2f);

//movement params 
bool isMovingUp=false;
bool isMovingDown=false;
bool isMovingLeft=false;
bool isMovingRight=false;
bool FiringKey=false;

//count
int score=0;
sf::Text counter;
sf::Font font;

int life=3;
int level=1;



sf::Texture t_hero;
sf::Sprite hero;
sf::Texture t_herofire;
sf::Sprite herofire;
sf::Texture t_enemy;
sf::Sprite enemy;
sf::Texture t_enemyfire;
sf::Sprite enemyfire;
sf::Texture t_boom1;
sf::Sprite boom1;
sf::Texture t_boom2;
sf::Sprite boom2;
sf::Music ks;

std::vector<sf::Vector2f> herofirevector;
std::vector<sf::Vector2f>enemyvector;
std::vector< std::pair<sf::Vector2f,int> > boomvector;
std::vector<sf::Vector2f>enemyfirevector;

int main()
{
    sf::RenderWindow window(sf::VideoMode(STAGE_X, STAGE_Y), "SFML works!");

    //load hero
    t_hero.loadFromFile("assets/hero.png");
    hero.setTexture(t_hero);
    hero.setScale(0.5,0.5); //PLANE--------(128,128)*0.5=(64,64)
    hero.setPosition(540*0.5-32,720-64);

    //load herofire
    t_herofire.loadFromFile("assets/herofire.png");
    herofire.setTexture(t_herofire);

    //load enemy
    t_enemy.loadFromFile("assets/enemy.png");
    enemy.setTexture(t_enemy);
    enemy.setScale(0.5,0.5);

    //load enemyfire
    t_enemyfire.loadFromFile("assets/enemyfire.png");
    enemyfire.setTexture(t_enemyfire);

    //load boom
    t_boom1.loadFromFile("assets/boom1.png");
    t_boom2.loadFromFile("assets/boom2.png");
    boom1.setTexture(t_boom1);
    boom2.setTexture(t_boom2);

    //load bgm
    sf::Music bgm;
    bgm.openFromFile("assets/bgm1.ogg");
    bgm.setVolume(20);
    bgm.play();

    //load kill sound
    ks.openFromFile("assets/killed.ogg");
    
    //load font
    font.loadFromFile("assets/arial.ttf"); 

    //set main clock
    sf::Clock spawnclock;
    float interval=0;

    while (window.isOpen())
    {
        //handle event
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
        //level control
        level=1+score/400;
        if(level>8)
        {
            //PASS ALL LEVEL
            break;
        }
        //spawn enemy
        if(spawnclock.getElapsedTime().asSeconds()>interval)
        {
            spawnEnemy();
            srand(time(0));
            interval=2-level*0.1+rand()%(2);
            spawnclock.restart();
        }
        update();
        
        /************************
        *RENDER REGION
        */
        window.clear();
        //draw hero
        window.draw(hero);
        //draw herofire
        for(std::vector<sf::Vector2f>::iterator it=herofirevector.begin();it!=herofirevector.end();it++)
        {
            herofire.setPosition(*(it));
            window.draw(herofire);
        }
        //draw enemy
        for(std::vector<sf::Vector2f>::iterator it=enemyvector.begin();it!=enemyvector.end();it++)
        {
            enemy.setPosition(*(it));
            window.draw(enemy);
        }
        //draw enemyfire
        for(std::vector<sf::Vector2f>::iterator it=enemyfirevector.begin();it!=enemyfirevector.end();it++)
        {
            enemyfire.setPosition(*(it));
            window.draw(enemyfire);
        }
        //renderboom
        for(std::vector< std::pair<sf::Vector2f,int> >::iterator it=boomvector.begin();it!=boomvector.end();)
        {
            if(it->second<=0)
            {
                it=boomvector.erase(it);
                continue;
            }
            if(it->second%2==0)
            {
                boom2.setPosition(it->first);
                window.draw(boom2);
                it->second-=1;
            }
            else if(it->second%2==1)
            {
                boom1.setPosition(it->first);
                window.draw(boom1);
                it->second-=1;
            }
            ++it;
        }

        //write score on screen
        //int sprintf( char *buffer, const char *format, [ argument] … );
        char buf[64];
        sprintf( buf, "Score:%d\nLife:%d\nLevel:%d", score,life,level);
        sf::String text(buf);
        counter.setString(text);
        counter.setFont(font);
        counter.setCharacterSize(20);
        counter.setColor(sf::Color::Blue);
        window.draw(counter);

        //render all
        window.display();
        /*************************
        *REGION END
        */
    }

    return 0;
}

void handlePlayerInput(sf::Keyboard::Key key,bool isPressed)
{
    if (key == sf::Keyboard::W)
        isMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        isMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        isMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        isMovingRight = isPressed;
    else if (key == sf::Keyboard::Space)
    {
        if(isPressed&&!FiringKey)
        {
            FiringKey=1;
            fire();
        }
        else if(!isPressed&&FiringKey)
        {
            FiringKey=0;
        }
    }
}

void update()
{
    //hero move
    sf::Vector2f movement(0.f, 0.f);
    if (isMovingUp&&hero.getPosition().y>0)
        movement.y -= 0.15f;
    if (isMovingDown&&hero.getPosition().y<STAGE_Y-PLANE_L)
        movement.y += 0.15f;
    if (isMovingLeft&&hero.getPosition().x>0)
        movement.x -= 0.15f;
    if (isMovingRight&&hero.getPosition().x<STAGE_X-PLANE_L)
        movement.x += 0.15f;
    hero.move(movement);

    //herofire move
    for(std::vector<sf::Vector2f>::iterator it=herofirevector.begin();it!=herofirevector.end();)
    {
        sf::Vector2f location=*(it);
        if(location.x<0||location.x>STAGE_X||location.y<0||location.y>STAGE_Y)
        {
            it=herofirevector.erase(it);
        }
        else
        {
            sf::Vector2f movement(0,-0.2f);
            *(it)+=movement;
            it++;
        } 
    }
    //enemy move
    for(std::vector<sf::Vector2f>::iterator it=enemyvector.begin();it!=enemyvector.end();)
    {
        sf::Vector2f location=*(it);
        if(location.x<0||location.x+PLANE_L>STAGE_X||location.y<0||location.y>STAGE_Y)
        {
            it=enemyvector.erase(it);
        }
        else
        {
            sf::Vector2f movement(0,0.1f+level*0.02f);
            *(it)+=movement;
            it++;
        }
    }
    //enemyfire move
    for(std::vector<sf::Vector2f>::iterator it=enemyfirevector.begin();it!=enemyfirevector.end();)
    {
        sf::Vector2f location=*(it);
        if(location.x<0||location.x>STAGE_X||location.y<0||location.y>STAGE_Y)
        {
            it=enemyfirevector.erase(it);
        }
        else
        {
            sf::Vector2f movement(0,0.2f+level*0.04f);
            *(it)+=movement;
            it++;
        } 
    }
    //kill enemy
    for(std::vector<sf::Vector2f>::iterator it=herofirevector.begin();it!=herofirevector.end();)
    {
        bool killed=0;
        sf::Vector2f fireett=*(it);
        for(std::vector<sf::Vector2f>::iterator itt=enemyvector.begin();itt!=enemyvector.end();)
        {
            sf::Vector2f enemyett=*(itt);
            if(fireett.x+FIRE_L/2>enemyett.x&&fireett.x+FIRE_L/2<enemyett.x+PLANE_L
            &&fireett.y+FIRE_L/2>enemyett.y&&fireett.y+FIRE_L/2<enemyett.y+PLANE_L)
            {
                boom(enemyett);
                it=herofirevector.erase(it);
                itt=enemyvector.erase(itt);
                killed=1;
                break;
            }
            else
            {
                itt++;
            }
        }
        if(killed==0)
        {
            it++;
        }
    }
    //enemy fire
    for(std::vector<sf::Vector2f>::iterator it=enemyvector.begin();it!=enemyvector.end();it++)
    {
        sf::Vector2f location=*(it);
        if(location.y>=199&&location.y<=200)
            fireenemy(location);
    }
}

void fire()
{
    sf::Vector2f newfire;
    newfire=hero.getPosition();
    newfire.x+=PLANE_L/2-FIRE_L/2;
    newfire.y-=FIRE_L;
    herofirevector.push_back(newfire);
}

void spawnEnemy()
{
    srand(time(0));
    int x=(int)(rand()%(STAGE_X-PLANE_L));
    sf::Vector2f newenemy(x,0);
    enemyvector.push_back(newenemy);
}

void boom(sf::Vector2f pos)
{
    std::pair<sf::Vector2f,int> newboom;
    newboom.first=pos;
    newboom.second=450;
    boomvector.push_back(newboom);
    ks.play();
    score+=20;
}

void fireenemy(sf::Vector2f pos)
{
    sf::Vector2f newfire=pos;
    newfire.x+=PLANE_L/2-FIRE_L/2;
    newfire.y+=PLANE_L;
    enemyfirevector.push_back(newfire);
}