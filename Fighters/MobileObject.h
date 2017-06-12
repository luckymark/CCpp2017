class MobileObject{
    public:
        sf::Sprite sprite;
        sf::Vector2f p;
        sf::Vector2f dir;
        float speed;

        MobileObject(const sf::Texture &tex, const float &posx, const float &posy, const sf::Vector2f &dir, const float &speed);
        void move(const float &dx, const float &dy);
        void move();
};

typedef std::list<MobileObject>::iterator ITER_A;
