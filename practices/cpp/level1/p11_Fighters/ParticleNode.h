#pragma once
#ifndef PARTICLENODE_H_
#define PARTICLENODE_H_
#include "Particle.h"
#include "DateTables.h"
#include "SceneNode.h"
#include "Category.h"
#include "CommandQueue.h"
#include "Foreach.h"
class ParticleNode :public SceneNode
{
public:
	ParticleNode(Particle::Type type, const TextureHolder& textures);
	void addParticle(sf::Vector2f position);
	Particle::Type getParticleType() const { return mType; };
	virtual unsigned int getCategory() const { return Category::ParticleSystem; };
private:
	virtual void updateCurrent(sf::Time dt, CommandQueue& command);
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	void addVertex(float worldX, float worldY, float texCoordX, float texCoordY, const sf::Color& color) const;
	void computeVertices() const;
private:
	std::deque<Particle> mParticles;
	const sf::Texture& mTexture;
	Particle::Type mType;

	mutable sf::VertexArray mVertexArray;
	mutable bool mNeedsVertexUpdate;
};
#endif // !PARTICLENODE_H_
