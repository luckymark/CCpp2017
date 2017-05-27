#ifndef MUSIC_H
#define MUSIC_H
#include <SFML/Audio.hpp>

class Music
{
    public:
        Music();
        virtual ~Music();
        static sf::Music BGM;
        static void load();

    protected:

    private:
};

#endif // MUSIC_H
