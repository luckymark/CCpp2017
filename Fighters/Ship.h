class Ship: public MobileObject{
    public:
        int lastshooted;
        int status, last;
        int lastshoot, pill_range;
        std::deque<sf::Sound>shooteds;
        std::deque<sf::Sound>self_bombs;
        int hp;
        int type;

        Ship(const sf::Texture &tex, const sf::Color &col, const float &posx, const float &posy, const sf::Vector2f &dir, const float &speed, const int &pill_range, int hp = 0, int type = 0);
        ~Ship();
        float dis(const sf::Vector2f &p);
        bool can_shoot();
        void shoot(std::list<MobileObject> &List, const MobileObject &pill);
        void shooteding();
        void bombing();
        void delete_sounds();
};

typedef std::list<Ship>::iterator ITER_B;
