#include<SFML/Graphics.hpp>
class Game{
    public:
        Game();
        void run();
        void pause();
        void resume();
    private:
        void processEvents();
        void update(sf::Time deltaTime);
        void render();
        void handlePlayerInput(sf::Keyboard::Key,bool isPressed);
    private:
        sf::RenderWindow Window;

        sf::Texture surfaceofflight;
        sf::Sprite Player;

        sf::Texture rmdht;
        sf::Sprite background;

        bool IsMovingUp=false;
        bool IsMovingDown;
        bool IsMovingLeft;
        bool IsMovingRight;

};
