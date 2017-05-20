#include "Item.h"
#include "Director.h"
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	Director director;
	director.set_world("setting");

	director.new_stuff(2,sf::Vector2f(50,50),sf::Vector2f(0,0));
	director.new_stuff(0,sf::Vector2f(400.0,400.0),sf::Vector2f(0,0));
	//director.new_stuff(3,sf::Vector2f(200.0,200.0),sf::Vector2f(0,0));

	director.main_loop();
	return 0;


}
