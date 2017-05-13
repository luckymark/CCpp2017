#include "Plane.h"
#include <SFML/Graphics.hpp>

Plane::Plane()
{
    //ctor
}

Plane::~Plane()
{
    //dtor
}

void Plane::displayPlane()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");

    sf::ConvexShape convex;
    sf::ConvexShape convex1;
    sf::ConvexShape convex2;
    sf::ConvexShape convex3;
    sf::ConvexShape convex4;
    convex.setPointCount(6);
    convex.setPoint(0, sf::Vector2f(450, 500));
    convex.setPoint(1, sf::Vector2f(452, 500));
    convex.setPoint(2, sf::Vector2f(471, 560));
    convex.setPoint(3, sf::Vector2f(466, 680));
    convex.setPoint(4, sf::Vector2f(436, 680));
    convex.setPoint(5, sf::Vector2f(431, 560));
    convex1.setPointCount(3);
    convex1.setPoint(0, sf::Vector2f(431, 560));
    convex1.setPoint(1, sf::Vector2f(441, 590));
    convex1.setPoint(2, sf::Vector2f(371, 620));
    convex2.setPointCount(3);
    convex2.setPoint(0, sf::Vector2f(471, 560));
    convex2.setPoint(1, sf::Vector2f(461, 590));
    convex2.setPoint(2, sf::Vector2f(531, 620));
    convex3.setPointCount(3);
    convex3.setPoint(0, sf::Vector2f(436, 660));
    convex3.setPoint(1, sf::Vector2f(451, 680));
    convex3.setPoint(2, sf::Vector2f(406, 700));
    convex4.setPointCount(3);
    convex4.setPoint(0, sf::Vector2f(466, 660));
    convex4.setPoint(1, sf::Vector2f(451, 680));
    convex4.setPoint(2, sf::Vector2f(496, 700));

    convex.setFillColor(sf::Color::White);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(convex);
        window.draw(convex1);
        window.draw(convex2);
        window.draw(convex3);
        window.draw(convex4);
        window.display();
    }

}
