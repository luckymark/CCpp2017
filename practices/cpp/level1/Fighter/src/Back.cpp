#include "Back.h"

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
