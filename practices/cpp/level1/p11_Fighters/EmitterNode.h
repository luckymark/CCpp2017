
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


	private:
		sf::Time				mAccumulatedTime;
		Particle::Type			mType;
		ParticleNode*			mParticleSystem;
};

