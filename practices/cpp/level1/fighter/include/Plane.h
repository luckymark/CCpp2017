#ifndef PLANE_H
#define PLANE_H
#include <SFML/Graphics.hpp>
#include "RTexture.h"
#include "Music.h"
#include "Action.h"
class World;
class Plane:public Action
{
    public:
        Plane(World *world);
        virtual ~Plane();

    protected:
        World *world;

    private:
};

#endif // PLANE_H
