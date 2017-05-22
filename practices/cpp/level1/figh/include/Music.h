#ifndef MUSIC_H
#define MUSIC_H
#include <SFML/Audio.hpp>

class Music
{
    public:
        Music();
        virtual ~Music();
        void play_bgm();

    protected:

    private:
        sf::Music bgm;
};

#endif // MUSIC_H
