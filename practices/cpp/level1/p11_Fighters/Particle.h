#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

struct Particle
{
	enum Type
	{
		Propellant,
		Smoke,
		ParticleCount
	};

	sf::Vector2f	position;
	sf::Color		color;
	sf::Time		lifetime;
};

#endif // PARTICLE_H_
