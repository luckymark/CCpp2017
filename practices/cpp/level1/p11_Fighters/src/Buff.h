#ifndef BUFF_H_
#define BUFF_H_

#include <SFML/Window.hpp>
#include <cstring>
using namespace std;
enum {speed_up,
      speed_up_ratio,
      life_and_attack,
      life_grow_speed_up,
      magic_power_up,
      magic_power_grow_speed_up,
      silence_time, 
      dizziness_time} buff_type;

struct Buff{
	//0 speed_up;
	//1 speed_up_ratio;
	//2 life_up & attack
	//3 life_grow_speed_up;
	//4 magic_power_up;
	//5 magic_power_grow_speed_up;
	//6 silence_time;
	//7 dizziness_time;

	float w[10];
	sf::Clock clock;
	float duration_time;
	Buff();
	Buff(int key, int val, float duration_time_);
};


#endif
