class Console{
    private:
        int last_ac;

        int last_pill_ac;

        int stage, last_change_stage, last_change_charsize;

        int time_condense;

        int last_ready_dynamite;
        bool dynamited;

        int last_upgrade;

        bool ended;

        int last_get_box, box_range, box_type, last_type;
        bool is_box;
        sf::Sprite box;

        std::list<MobileObject>pills;
        std::list<MobileObject>enemy_pills;
        std::list<Ship>enemys;

        sf::RenderWindow* window;

        TextBoard *title, *declaration, *text_begin, *text_lost,
                  *life_point_recovered, *weapon_upgraded, *sparkle_dynamite,
                  *upgrade_left, *elite_coming, *flagship_coming, *boss_coming,
                  *text_win, *speed_up, *bullet_acceralated, *ac_left, *pac_left;

        ScoreBoard* scoreboard;

        sf::Texture pill_pic, background_pic,
                    enemy_pill_pic, box_pic[5], pill_great_pic;

        sf::SoundBuffer bullet_ogg, weapon2_wav;

        SpaceShip* spaceship;
        sf::Sprite *background, *background2;

        sf::Sound bullet_sound, weapon2_sound;
        sf::Music bgm, lost_music, warning_music, reward_music, win_music;

        int last_enemy, enemy_range;

        int last_boss, boss_range;

    public:
        void init_window();
        void init_texts();
        void init_scoreboard();
        void init_pictures();
        void init_musics_and_sounds();
        Console();
        ~Console();
        void make_enemy();
        void make_box();
        void solve_input();
        void draw();
        void update();
        void work();
};
