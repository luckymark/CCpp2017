#ifndef FIRE_H
#define FIRE_H


class Fire
{
    public:
        Fire();
        virtual ~Fire();
        sf::Texture texture_enemyFire;
        sf::Sprite sprite_enemyFire;
        void on_off();
        void load_enemyFire(int enemy_firePosition_x,int enemy_firePosition_y);
        sf::Sprite get_enemyShootSprite();
        void move_enemyShoot();
        bool enemy_active;
        float level_enemyShoot;
    protected:
        int position_enemyBullet_x;
        int position_enemtBullet_y;


    private:
};

#endif // FIRE_H
