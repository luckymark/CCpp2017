#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
using namespace sf;
using namespace std;
class AMMO
{
    private:
        Sprite pic;
        bool live;
    public:
        AMMO(const Texture & texture)
        {
            pic.setTexture(texture);
            live=false;
        }
        
};
int main()
{
    float speed;
    RenderWindow window(VideoMode(1920,1080), "SFML works!");

    //RenderTexture background;
    //background.create(800,800);
    window.setFramerateLimit(120);
    bool exit=false;
    Texture texture,back1;
    Image image;
    CircleShape circle(4.f,1000);
    image.loadFromFile("test.png");
    texture.loadFromImage(image,IntRect(0,0,50,50));
    circle.setFillColor(Color::Black);
    back1.loadFromFile("test.png");
    back1.setRepeated(true);
    //circle.setTextureRect(IntRect(800,800,1000,1000));
    Music music;
    music.openFromFile("xi-Dst[ick]orv.ogg");
    music.setVolume(50);
    music.setLoop(true);
    //music.play();
    Sprite sprite(texture);
    sprite.setPosition(200.f,200.f);
    //sprite.setScale(0.5,0.5);
    Sprite back;
    back.setTexture(back1);
    Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if(Keyboard::isKeyPressed(Keyboard::LShift))speed=0.5;
        else speed=5;
        if(Keyboard::isKeyPressed(Keyboard::S))if(sprite.getPosition().y+speed+100<1080)sprite.move(0,speed);
        if(Keyboard::isKeyPressed(Keyboard::D))if(sprite.getPosition().x+speed+100<1920) sprite.move(speed,0);
        if(Keyboard::isKeyPressed(Keyboard::A))if(sprite.getPosition().x+speed>100)sprite.move(-speed,0);
        if(Keyboard::isKeyPressed(Keyboard::W))if(sprite.getPosition().y+speed>100)sprite.move(0,-speed);
        if(Keyboard::isKeyPressed(Keyboard::J))
        {
            exit=true;
            circle.setPosition(sprite.getPosition().x,sprite.getPosition().y);
        }
        if(exit==true)circle.move(5,0);
        else exit=false;
        //background.clear(Color::Red);
       // background.draw(back);
        //background.display();

        window.clear();
        window.draw(back);
        window.draw(sprite);
        if(circle.getPosition().x!=1920.f+2.f||circle.getPosition().y!=1080.f+2.f)window.draw(circle);
        window.display();
    }

    return 0;
}