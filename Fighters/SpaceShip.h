class SpaceShip: public Ship{
    public:
        std::list<sf::Sprite>gun_fires;
        sf::Texture gun_fire_pic, spaceship_pic[4];
        sf::SoundBuffer spaceship_ogg;
        sf::Sound spaceship_sound;
        sf::Time spaceship_sound_time_tag,
                 spaceship_sound_time_tag_2;

        SpaceShip(const sf::Texture &tex, const sf::Color &col, const float &posx, const float &posy, const sf::Vector2f &dir, const float &speed, const int &pill_range);
        ~SpaceShip();
        void reset_spaceship_sound();
        void set_spaceship_sound();
        void moveB(const float &dx, const float &dy);
        void create_gun_fires();
        void update();
};
