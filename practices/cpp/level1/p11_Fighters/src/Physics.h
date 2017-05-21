#ifndef PHYSICS_H_
#define PHYSICS_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

const float g = 10;

class Physics{
	private:
		float mass;
		float max_force; //max_force_with_no_speed
		float max_power_ratio;
		float mu;
		float max_mu;
		sf::Vector2f position;
		sf::Vector2f speed;
		sf::Vector2f motivation;
		sf::Vector2f force;

	public:
		Physics();
		void set_max_force(float mx);
		void set_position(sf::Vector2f pos);
		void set_speed(sf::Vector2f sp);
		void set_self_move_ratio(float x);

		void set_mass(float m);
		void set_max_power_ratio(float m);
		void set_mu(float m);

		sf::Vector2f get_position();
		sf::Vector2f get_speed();
		float get_max_power_ratio();
		float get_mass();

		void add_motivation(sf::Time dt);
		void add_motivation(sf::Vector2f mo);
		void add_force(sf::Vector2f f);
		float get_length_of_vector(sf::Vector2f vec);
		void add_power_ratio(sf::Vector2f pr,sf::Time dt);

		void update_speed();
		void update_position(sf::Time dt);

		sf::Vector2f make_one(sf::Vector2f vec);
		void next(sf::Time dt);
		void general_friction(float mu);
		void clear();
};


#endif
