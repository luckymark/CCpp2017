#include "Back.h"

sf::Texture Back::texture;
sf::Sprite Back::sprite;

Back::Back()
{
   texture.loadFromFile("resource/image/back.jpg");
   sprite.setTexture(texture);
}



Back::~Back()
{
    //dtor
}

sf::Sprite Back::Get_sprite()
{
    return sprite;
}
