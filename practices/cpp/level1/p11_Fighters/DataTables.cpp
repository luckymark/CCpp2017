#include "DataTables.h"
#include "Aircraft.h"
#include "Projectile.h"
#include "Pickup.h"
#include "Particle.h"

using namespace std::placeholders;

std::vector<AircraftData> initializeAircraftData()
{
	std::vector<AircraftData> data(Aircraft::TypeCount);
	data[Aircraft::Hero].hitpoints = 100;
	data[Aircraft::Hero].speed = 200.f;
	data[Aircraft::Hero].fireInterval = sf::seconds(1);
	data[Aircraft::Hero].texture = Textures::Entities;
	data[Aircraft::Hero].textureRect = sf::IntRect(0, 0, 48, 64);
	data[Aircraft::Hero].hasRollAnimation = true;

	data[Aircraft::Enemy1].hitpoints = 20;
	data[Aircraft::Enemy1].speed = 80.f;
	data[Aircraft::Enemy1].texture = Textures::Entities;
	data[Aircraft::Enemy1].textureRect = sf::IntRect(144, 0, 84, 64);
	data[Aircraft::Enemy1].directions.push_back(Direction(+45.f, 80.f));
	data[Aircraft::Enemy1].directions.push_back(Direction(-45.f, 160.f));
	data[Aircraft::Enemy1].directions.push_back(Direction(+45.f, 80.f));
	data[Aircraft::Enemy1].fireInterval = sf::Time::Zero;
	data[Aircraft::Enemy1].hasRollAnimation = false;

	data[Aircraft::Enemy2].hitpoints = 40;
	data[Aircraft::Enemy2].speed = 50.f;
	data[Aircraft::Enemy2].texture = Textures::Entities;
	data[Aircraft::Enemy2].textureRect = sf::IntRect(228, 0, 60, 59);
	data[Aircraft::Enemy2].directions.push_back(Direction(+45.f,  50.f));
	data[Aircraft::Enemy2].directions.push_back(Direction(  0.f,  50.f));
	data[Aircraft::Enemy2].directions.push_back(Direction(-45.f, 100.f));
	data[Aircraft::Enemy2].directions.push_back(Direction(  0.f,  50.f));
	data[Aircraft::Enemy2].directions.push_back(Direction(+45.f,  50.f));
	data[Aircraft::Enemy2].fireInterval = sf::seconds(2);
	data[Aircraft::Enemy2].hasRollAnimation = false;

	return data;
}

std::vector<ProjectileData> initializeProjectileData()
{
	std::vector<ProjectileData> data(Projectile::TypeCount);

	data[Projectile::AlliedBullet].damage = 10;
	data[Projectile::AlliedBullet].speed = 300.f;
	data[Projectile::AlliedBullet].texture = Textures::Entities;
	data[Projectile::AlliedBullet].textureRect = sf::IntRect(175, 64, 3, 14);

	data[Projectile::EnemyBullet].damage = 10;
	data[Projectile::EnemyBullet].speed = 300.f;
	data[Projectile::EnemyBullet].texture = Textures::Entities;
	data[Projectile::EnemyBullet].textureRect = sf::IntRect(178, 64, 3, 14);

	data[Projectile::Missile].damage = 200;
	data[Projectile::Missile].speed = 150.f;
	data[Projectile::Missile].texture = Textures::Entities;
	data[Projectile::Missile].textureRect = sf::IntRect(160, 64, 15, 32);

	return data;
}

std::vector<PickupData> initializePickupData()
{
	std::vector<PickupData> data(Pickup::TypeCount);

	data[Pickup::HealthRefill].texture = Textures::Entities;
	data[Pickup::HealthRefill].textureRect = sf::IntRect(0, 64, 40, 40);
	data[Pickup::HealthRefill].action = std::bind(&Aircraft::repair, _1, 25);

	data[Pickup::MissileRefill].texture = Textures::Entities;
	data[Pickup::MissileRefill].textureRect = sf::IntRect(40, 64, 40, 40);
	data[Pickup::MissileRefill].action = std::bind(&Aircraft::collectMissiles, _1, 3);

	data[Pickup::FireSpread].texture = Textures::Entities;
	data[Pickup::FireSpread].textureRect = sf::IntRect(80, 64, 40, 40);
	data[Pickup::FireSpread].action = std::bind(&Aircraft::increaseSpread, _1);

	data[Pickup::FireRate].texture = Textures::Entities;
	data[Pickup::FireRate].textureRect = sf::IntRect(120, 64, 40, 40);
	data[Pickup::FireRate].action = std::bind(&Aircraft::increaseFireRate, _1);

	return data;
}

std::vector<ParticleData> initializeParticleData()
{
	std::vector<ParticleData> data(Particle::ParticleCount);

	data[Particle::Propellant].color = sf::Color(255, 255, 50);
	data[Particle::Propellant].lifetime = sf::seconds(0.6f);

	data[Particle::Smoke].color = sf::Color(50, 50, 50);
	data[Particle::Smoke].lifetime = sf::seconds(4.f);

	return data;
}
