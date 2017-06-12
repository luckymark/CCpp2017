#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H


class EnemyPlane
{
    public:
        /*sf::SoundBuffer explosion_soundBuffer_1;
        sf::Sound soundExplosion_1;
        sf::SoundBuffer explosion_soundBuffer_2;
        sf::Sound soundExplosion_2;*/
        EnemyPlane();
        sf::Sprite sprite_enemyPlane;
        sf::Texture texture_enemyPlane;
        sf::Sprite spriteExplosion1;
        sf::Sprite spriteExplosion2;
        sf::Sprite spriteExplosion3;
        sf::Sprite spriteExplosion4;
        sf::Texture textureExplosion1;
        sf::Texture textureExplosion2;
        sf::Texture textureExplosion3;
        sf::Texture textureExplosion4;
        Fire enemyfire[50];
        sf::Clock clock_enemyFire;
        virtual ~EnemyPlane();
        void load_enemyPlane();
        void move_enemyPlane();
        void on_off();
        void reset();
        void explosion(int positionExplosion_x,int positionExplosion_y);
        void controlExplosion();
        sf::Sprite get_enemyPlaneSprite();
        struct Enemy_Plane
        {
            int position_enemyPlane_x;
            int position_enemyPlane_y;
            bool active;
        };
        Enemy_Plane enemyPlane;
        int explosion_status;
        float level_enemyPlane;
    protected:
        int count_explosion;
        int temp;
    private:
};

#endif // ENEMYPLANE_H

