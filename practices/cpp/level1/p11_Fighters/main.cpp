#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


void handlePlayerInput(sf::Keyboard::Key, bool);
void update();

//movement params
bool isMovingUp=false;
bool isMovingDown=false;
bool isMovingLeft=false;
bool isMovingRight=false;

sf::Texture t_hero;
sf::Sprite hero;

int main()
{
    sf::RenderWindow window(sf::VideoMode(540, 720), "SFML works!");

    //load hero
    t_hero.loadFromFile("assets/hero.png");
    hero.setTexture(t_hero);
    hero.setScale(0.5,0.5); //PLANE--------(128,128)*0.5=(64,64)
    hero.setPosition(540*0.5-32,720-64);

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
        

        window.clear();
        window.draw(hero);
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
}

void update()
{
    sf::Vector2f movement(0.f, 0.f);
    if (isMovingUp)
        movement.y -= 0.4f;
    if (isMovingDown)
        movement.y += 0.4f;
    if (isMovingLeft)
        movement.x -= 0.4f;
    if (isMovingRight)
        movement.x += 0.4f;
    hero.move(movement);
}
