#include "Item.h"
#include "Director.h"
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	Director director;
	director.set_world("setting");
	//director.new_stuff(10,sf::Vector2f(0,0));
	director.start();
	director.main_loop();
	return 0;
}
