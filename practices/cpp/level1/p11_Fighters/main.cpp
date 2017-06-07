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

//movement params 
bool isMovingUp=false;
bool isMovingDown=false;
bool isMovingLeft=false;
bool isMovingRight=false;
bool FiringKey=false;


sf::Texture t_hero;
sf::Sprite hero;
sf::Texture t_herofire;
sf::Sprite herofire;
sf::Texture t_enemy;
sf::Sprite enemy;

std::vector<sf::Vector2f> herofirevector;
std::vector<sf::Vector2f>enemyvector;

int main()
{
    sf::RenderWindow window(sf::VideoMode(STAGE_X, STAGE_Y), "SFML works!");

    //load hero
    t_hero.loadFromFile("assets/hero.png");
    hero.setTexture(t_hero);
    hero.setScale(0.5,0.5); //PLANE--------(128,128)*0.5=(64,64)
    hero.setPosition(540*0.5-32,720-64);

    //load fire
    t_herofire.loadFromFile("assets/herofire.png");
    herofire.setTexture(t_herofire);

    //load enemy
    t_enemy.loadFromFile("assets/enemy.png");
    enemy.setTexture(t_enemy);
    enemy.setScale(0.5,0.5);
    enemy.setRotation(180);

    //load bgm
    sf::Music bgm;
    bgm.openFromFile("assets/bgm1.ogg");
    bgm.play();

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

        //spawn enemy
        if(spawnclock.getElapsedTime().asSeconds()>interval)
        {
            spawnEnemy();
            srand(time(0));
            interval=2+rand()%2;
            spawnclock.restart();
        }
        update();
        
        //render
        window.clear();
        window.draw(hero);
        for(std::vector<sf::Vector2f>::iterator it=herofirevector.begin();it!=herofirevector.end();it++)
        {
            herofire.setPosition(*(it));
            window.draw(herofire);
        }
        for(std::vector<sf::Vector2f>::iterator it=enemyvector.begin();it!=enemyvector.end();it++)
        {
            enemy.setPosition(*(it));
            window.draw(enemy);
        }
        window.display();
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
    for(std::vector<sf::Vector2f>::iterator it=herofirevector.begin();it!=herofirevector.end();/*no ++*/)
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
    for(std::vector<sf::Vector2f>::iterator it=enemyvector.begin();it!=enemyvector.end();it++)
    {
        sf::Vector2f movement(0,0.1f);
        *(it)+=movement;
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