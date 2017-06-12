#include "DateTables.h"
#include "Aircraft.h"
#include "Projectile.h"
#include "Pickup.h"
#include "Particle.h"

using namespace std::placeholders;
std::vector<AircraftData> initializeAircraftData()
{
	std::vector<AircraftData> data(Aircraft::TypeCount);
	data[Aircraft::Eagle].hitpoints = INT_MAX/2;
	data[Aircraft::Eagle].speed = 400.f;
	data[Aircraft::Eagle].texture = Textures::Entities;
	data[Aircraft::Eagle].textureRect = sf::IntRect(0, 0, 48, 64);
	data[Aircraft::Eagle].fireInterval = sf::seconds(1.f);
	data[Aircraft::Eagle].hasRollAnimation = true;

	data[Aircraft::Raptor].hitpoints = 40;
	data[Aircraft::Raptor].speed = 1.f;
	data[Aircraft::Raptor].texture = Textures::Entities;
	data[Aircraft::Raptor].textureRect = sf::IntRect(144, 0, 84, 64);
	data[Aircraft::Raptor].directions.push_back(Direction(+45.f, 80.f));
	data[Aircraft::Raptor].directions.push_back(Direction(-45.f, 160.f));
	data[Aircraft::Raptor].directions.push_back(Direction(+45.f, 80.f));
	data[Aircraft::Avenger].fireInterval = sf::seconds(5);

	data[Aircraft::Avenger].hitpoints = 40;
	data[Aircraft::Avenger].speed = 1.f;
	data[Aircraft::Avenger].texture = Textures::Entities;
	data[Aircraft::Avenger].textureRect = sf::IntRect(228, 0, 60, 59);
	data[Aircraft::Avenger].directions.push_back(Direction(+45.f, 50.f));
	data[Aircraft::Avenger].directions.push_back(Direction(0.f, 50.f));
	data[Aircraft::Avenger].directions.push_back(Direction(-45.f, 100.f));
	data[Aircraft::Avenger].directions.push_back(Direction(0.f, 50.f));
	data[Aircraft::Avenger].directions.push_back(Direction(+45.f, 50.f));
	data[Aircraft::Avenger].fireInterval = sf::seconds(5);

	return data;
}

std::vector<ProjectileData> initializeProjectileData()
{
	std::vector<ProjectileData> data(Projectile::TypeCount);

	data[Projectile::AlliedBullet].damage = 20;
	data[Projectile::AlliedBullet].speed = 2500.f;
	data[Projectile::AlliedBullet].texture = Textures::Entities;
	data[Projectile::AlliedBullet].textureRect = sf::IntRect(175, 64, 3, 14);

	data[Projectile::EnemyBullet].damage = 20;
	data[Projectile::EnemyBullet].speed = 200.f;
	data[Projectile::EnemyBullet].texture = Textures::Entities;
	data[Projectile::EnemyBullet].textureRect = sf::IntRect(178, 64, 3, 14);

	data[Projectile::Missile].damage = INT_MAX;
	data[Projectile::Missile].speed = 650.f;
	data[Projectile::Missile].texture = Textures::Entities;
	data[Projectile::Missile].textureRect = sf::IntRect(160, 64, 15, 32);

	return data;
}

std::vector<PickupData> initializePickupData()
{
	std::vector<PickupData> data(Pickup::TypeCount);

	data[Pickup::HealthRefill].texture = Textures::Entities;
	data[Pickup::HealthRefill].textureRect = sf::IntRect(0, 64, 40, 40);
	data[Pickup::HealthRefill].action = [](Aircraft& a) { a.repair(25); };

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

	data[Particle::Smoke].color = sf::Color::Red;//sf::Color(50, 50, 50);
	data[Particle::Smoke].lifetime = sf::seconds(0.f);

	return data;
}