#include "Load.h"

Load::Load()
{
    //ctor
}

Load::~Load()
{
    //dtor
}

void Load::loading()
{
    Music::load();
    RTexture::load();
}
