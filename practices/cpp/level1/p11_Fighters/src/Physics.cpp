#include "Physics.h"
#include <cmath>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

float Physics::get_max_power_ratio(){
	return max_power_ratio;
}

void Physics::set_mu(float m){
	max_mu = m;
}

void Physics::set_self_move_ratio(float x){
	mu = max_mu * x;
}

void Physics::set_max_power_ratio(float m){
	max_power_ratio = m;
}

void Physics::set_max_force(float mx){
	max_force = mx;
}

void Physics::set_position(sf::Vector2f pos){
	position = pos;
}

Physics::Physics(){
	mass = 0;
	position = speed = motivation = force = sf::Vector2f(0,0);
}
void Physics::add_force(sf::Vector2f f){
	force += f;
}
void Physics::add_motivation(sf::Time dt){
	motivation += force * dt.asSeconds();
}

void Physics::add_motivation(sf::Vector2f mo){
	motivation += mo;
}

void Physics::update_speed(){
	if(mass < 1e-5) mass = 1e-5;
	speed = motivation / mass;
}

void Physics::set_mass(float m){
	mass = m;
}

float Physics::get_length_of_vector(sf::Vector2f vec){
	return sqrt(vec.x*vec.x+vec.y*vec.y);
}

sf::Vector2f Physics::make_one(sf::Vector2f vec){
	float tmp = get_length_of_vector(vec);
	if(tmp < 1e-5) tmp = 1e-5;
	vec /= tmp;
	return vec;
}

void Physics::general_friction(float mu){
	if(get_length_of_vector(speed) >= 1e-5){
		sf::Vector2f dir = make_one(speed);
		add_force(dir * mass * g * mu * (float)(-1));// f = mu*G = mu*m*g = mu*10*g
	}else {
		float tmp = get_length_of_vector(force);
		if(tmp > 0 && tmp <= mass * g * mu){
			add_force(force * float(-1));
		}else if(tmp > mass * g * mu){
			if(tmp < 1e-5) tmp = 1e-5;
			add_force(force/tmp * mass * g * mu);
		}
	}

}
void Physics::update_position(sf::Time dt){
	position += speed * dt.asSeconds();
}
void Physics::clear(){
	force = sf::Vector2f(0,0);
}
void Physics::next(sf::Time dt){
	general_friction(mu);
	add_motivation(dt);
	update_speed();
	update_position(dt);
	clear();
}

void Physics::set_speed(sf::Vector2f sp){
	speed = sp;
}

sf::Vector2f Physics::get_position(){
	return position;
}

void Physics::add_power_ratio(sf::Vector2f pr,sf::Time dt){// self
	sf::Vector2f fm = make_one(pr) * max_force;
	float pr2 = get_length_of_vector(pr);
	pr2 *= pr2; //	pr^2
	float cur = fm.x * speed.x + fm.y * speed.y;
	if(cur > pr2){
		if(abs(speed.x) < 1e-5) speed.x = 1e-5;
		if(abs(speed.y) < 1e-5) speed.y = 1e-5;

		pr.x /= speed.x;
		pr.y /= speed.y;
		add_force(pr);
	}else {
		add_force(fm);
	}
}

sf::Vector2f Physics::get_speed(){
	return speed;
}

