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

        sf::Sprite sprite_myPlaneExplosion1;
        sf::Sprite sprite_myPlaneExplosion2;
        sf::Sprite sprite_myPlaneExplosion3;
        sf::Sprite sprite_myPlaneExplosion4;
        sf::Texture texture_myPlaneExplosion1;
        sf::Texture texture_myPlaneExplosion2;
        sf::Texture texture_myPlaneExplosion3;
        sf::Texture texture_myPlaneExplosion4;

        Plane();
        struct Bullet
        {
            int positionBullet_x;
            int positionBullet_y;
            bool active;
        };
        Bullet bullet[200];

        int HP;
        int explosion_status;
        int count_explosion;
        int myPlane_status;
        std::string int_to_string(int n);
        virtual ~Plane();
        void loadPlane();
        void movePlane();
        void playMusic();
        void loadShoot();
        void moveShoot(sf::RenderWindow* window);
        void explosion(int position_explosion_x,int position_explosion_y);
        void controlExplosion();
    protected:

            int temp;

    private:
};

#endif // PLANE_H
