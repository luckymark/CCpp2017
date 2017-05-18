#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
# include<iostream>
#define BulMoveSpeed  0.7
#define PlaMoveSpeed   0.6
# include<time.h>
//子弹的类
class EnemyAircraft{
public :
        sf::Texture ene_aircraft_texture;
        sf::Sprite ene_aircraft;
        EnemyAircraft()
            {
                    if (!ene_aircraft_texture.loadFromFile("diji9.jfif"))
                        {

                        }
                    ene_aircraft.setTexture(ene_aircraft_texture);
                    ene_aircraft.setScale(1.0f,1.0f);
            }
        ~EnemyAircraft()
            {

            }
};
//敌机的类
class Bullet{
public:
        sf::Texture bullet_texture;
        sf::Sprite bullet;

        Bullet()
            {
                    if (!bullet_texture.loadFromFile("paodan8.jpg"))
                        {

                        }
                    bullet.setTexture(bullet_texture);
                    bullet.setScale(0.2f,0.2f);
            }
        ~Bullet()
            {

            }

};

int MoveSprite(sf::Sprite &myplane)
{
            sf::Vector2f position = myplane.getPosition();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&position.x>0)
                {
                            // left key is pressed: move our character
                            myplane.move(-PlaMoveSpeed,0);
                }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&position.x<1272.2)
                {
                            // left key is pressed: move our character
                            myplane.move(PlaMoveSpeed,0);
                }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                            myplane.move(0,-PlaMoveSpeed);
                }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&position.y<720)
                {
                            myplane.move(0,PlaMoveSpeed);
                }
            return 0;
}

int main()
{
             srand(time(0));
             int num_ene_aircraft = (rand()%18)+1;
             int pst_ene_aircraft = rand()%1326;

            //设置飞机位置，大小，窗口
            sf::RenderWindow window(sf::VideoMode(1400,900),"The plane!");
            sf::Texture myplane_texture;
            if (!myplane_texture.loadFromFile("flightimage3.jpg"))
                {
                            return -1;
                }
            sf::Sprite myplane;
            myplane.setTexture(myplane_texture);
            myplane.setPosition(600,600);
            myplane.setScale(0.6f,0.6f);


            //设置背景音乐
            sf::Music background_music;
            if (!background_music.openFromFile("OpeningTitles.ogg"))
                {
                            return -1;      // error
                }
            background_music.play();
            background_music.setLoop(true);




        //设置输出窗口
        while (window.isOpen())
        {

                    sf::Event event;
                    while (window.pollEvent(event))
                        {
                                if (event.type == sf::Event::Closed)
                                    window.close();
                        }

                    //移动飞机
                    MoveSprite(myplane);
                    window.clear(sf::Color::White);
                    window.draw(myplane);

                    //声明子弹，并且设置子弹的位置，显示子弹
                   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Home))
                    {

                                // 产 生三个子弹
                                Bullet *p = new Bullet[3];
                                sf::Vector2f position = myplane.getPosition();
                                p[1].bullet.setPosition(position.x+41.4,position.y-45);
                                p[0].bullet.setPosition(position.x-5,position.y-30);
                                p[2].bullet.setPosition(position.x+87.8,position.y-30);

                                sf::Vector2f  position_bu = p[1].bullet.getPosition();
                                while(position_bu.y>0)
                                    {

                                                p[1].bullet.move(0,-BulMoveSpeed);
                                                p[0].bullet.move(0,-BulMoveSpeed);
                                                p[2].bullet.move(0,-BulMoveSpeed);
                                                position_bu = p[1].bullet.getPosition();

                                                window.draw(p[1].bullet);
                                                window.draw(p[0].bullet);
                                                window.draw(p[2].bullet);
                                                window.display();

                                                window.clear(sf::Color::White);
                                                window.draw(myplane);

                                    }

                        delete[] p;
                   }


                    //声明敌机
                    EnemyAircraft enemy_aircra;
                    enemy_aircra.ene_aircraft.setPosition(pst_ene_aircraft,0);

                    sf::Vector2f position_ene_air = enemy_aircra.ene_aircraft.getPosition();
                    while(position_ene_air.y<900){

                            enemy_aircra.ene_aircraft.move(0,-BulMoveSpeed);
                            window.draw(enemy_aircra.ene_aircraft);
                            window.display();

                            window.clear(sf::Color::White);
                            window.draw(myplane);
                    }

                    window.draw(enemy_aircra.ene_aircraft);
                    window.display();

        }

        return 0;
}

