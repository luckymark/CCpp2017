#include "Back.h"

Back::Back()
{
   texture.loadFromFile("resource/image/back.jpg");

}

Back::~Back()
{
    //dtor
}

void Back::view_back()
{
    sprite.setTexture(texture);
}
sf::Sprite Back::Get_sprite()
{
    return sprite;
}
