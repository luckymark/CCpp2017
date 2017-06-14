#ifndef PICKUP_H_
#define PICKUP_H_

#include "Entity.h"
#include "Command.h"
#include "ResourceIdentifiers.h"
#include <SFML/Graphics.hpp>

class Aircraft;

class Pickup : public Entity
{
	public:
		enum Type
		{
			HealthRefill,
			MissileRefill,
			FireSpread,
			FireRate,
			TypeCount
		};

								Pickup(Type type, const TextureHolder& textures);

		virtual unsigned int	getCategory() const;
		virtual sf::FloatRect	getBoundingRect() const;

		void 					apply(Aircraft& player) const;

	protected:
		virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		Type 					mType;
		sf::Sprite				mSprite;
};

#endif // PICKUP_H_
