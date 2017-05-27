#ifndef GAME_H
#define GAME_H
#include <SFML/Audio.hpp>
#include "World.h"
#include "Music.h"
#include <SFML/Graphics.hpp>
class Game
{
    public:
        Game(World *world);
        virtual ~Game();
        void init();
        void MainLoop();

    protected:

    private:
        World *world;
        void play_music();
        void pause_music();
        sf::Music &BGM=Music::BGM;
};

#endif // GAME_H
