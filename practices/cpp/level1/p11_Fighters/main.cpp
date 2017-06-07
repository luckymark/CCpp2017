#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <vector>

const int STAGE_X=540;
const int STAGE_Y=720;
const int PLANE_L=64;
const int FIRE_L=32;


void handlePlayerInput(sf::Keyboard::Key, bool);
void update();
void fire();

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

std::vector<sf::Vector2f> herofirevector;

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

    //load bgm
    sf::Music bgm;
    bgm.openFromFile("assets/bgm1.ogg");
    bgm.play();

    

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

        update();
        
        //render
        window.clear();
        window.draw(hero);
        for(std::vector<sf::Vector2f>::iterator it=herofirevector.begin();it!=herofirevector.end();it++)
        {
            herofire.setPosition(*(it));
            window.draw(herofire);
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
    for(std::vector<sf::Vector2f>::iterator it=herofirevector.begin();it!=herofirevector.end();it++)
    {
        sf::Vector2f movement(0,-0.2f);
        *(it)+=movement;
    }
}

void fire()
{
    sf::Vector2f newfire;
    newfire=hero.getPosition();
    newfire.x+=PLANE_L-FIRE_L;
    newfire.y-=FIRE_L;
    herofirevector.push_back(newfire);
}