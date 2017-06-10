#ifndef PLANE_H
#define PLANE_H


class Plane
{
    public:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Clock clock_1;

        sf::Sprite spriteShoot[200];
        sf::Texture textureShoot;

        sf::SoundBuffer bullet_soundBuffer;
        sf::Sound soundBullet;
        Plane();
        struct Bullet
        {
            int positionBullet_x;
            int positionBullet_y;
            bool active;
        };
        Bullet bullet[200];

        int HP;
        std::string int_to_string(int n);
        virtual ~Plane();
        void loadPlane();
        void movePlane();
        void playMusic();
        void loadShoot();
        void moveShoot(sf::RenderWindow* window);
    protected:

            int temp;

    private:
};

#endif // PLANE_H
