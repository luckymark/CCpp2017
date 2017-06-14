#ifndef EMITTERNODE_H_
#define EMITTERNODE_H_

#include "SceneNode.h"
#include "Particle.h"

class ParticleNode;

class EmitterNode : public SceneNode
{
	public:
		explicit				EmitterNode(Particle::Type type);

	private:
		virtual void			updateCurrent(sf::Time dt, CommandQueue& commands);

		void					emitParticles(sf::Time dt);

		sf::Time				mAccumulatedTime;
		Particle::Type			mType;
		ParticleNode*			mParticleSystem;
};

#endif // EMITTERNODE_H_
