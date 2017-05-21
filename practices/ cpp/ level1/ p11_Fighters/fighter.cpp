#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#define move_speed 0.5
#define window_length 1280
#define window_width 960
#define missile_speed 1
class MISSILE{
private:
public:
sf::Texture tex_missile;
sf::Sprite missile;

    MISSILE()
    {
if (!tex_missile.loadFromFile("missile.jpg")){
    // 未找到文件的情况
    }
    missile.setTexture(tex_missile);
    missile.setScale(0.6f,0.6f);
        missile.setOrigin(62.5,62.5);
    }
};
void move_aircraft(sf::Sprite &duixiang)
{
    sf::Vector2f position = duixiang.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&(position.x>53)){
    duixiang.move(-move_speed, 0);       //左移
    }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&(position.x<window_length-53)){
    duixiang.move(move_speed, 0);        //右移
    }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&(position.y>0+75)){
    duixiang.move(0,-move_speed);        //上移
    }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&(position.y<window_width-75)){
    duixiang.move(0, move_speed);        //下移
    }
}

int main()
{
    sf::Music music;
    //播放背景音乐
    if (!music.openFromFile("Sight.wav")){
    return -1;
    }
    //设置音量
    music.setVolume(10);
    music.play();
    //循环背景音乐
    music.setLoop(true);

    sf::Texture tex_aircraft;
    if (!tex_aircraft.loadFromFile("aircraft2.jpg")){
    // 未找到文件的情况
    }
    tex_aircraft.setSmooth(true);
    sf::Sprite aircraft;
    aircraft.setTexture(tex_aircraft);
    aircraft.setOrigin(106, 150);
    aircraft.setPosition(sf::Vector2f(window_length/2, window_width-150)); // 定义图像初始位置
    aircraft.setScale(sf::Vector2f(0.5f, 0.5f)); // 定义显示的图像相对于源文件的比例
    sf::RenderWindow window(sf::VideoMode(window_length,window_width), "SFML works!");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

move_aircraft(aircraft);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
    MISSILE*p=new MISSILE;
    sf::Vector2f position = aircraft.getPosition();
    p->missile.setPosition(position.x,position.y-100);
    sf::Vector2f position_missile=p->missile.getPosition();
    while(position_missile.y>0){

        p->missile.move(0,-missile_speed);
        position_missile=p->missile.getPosition();
     move_aircraft(aircraft);
       window.draw(p->missile);
        window.display();
        window.clear(sf::Color::White);
        window.draw(aircraft);
    }
    delete p;
  }


        window.clear(sf::Color::White);
        window.draw(aircraft);
        window.display();
    }
    return 0;
}
