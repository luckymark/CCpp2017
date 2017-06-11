#include "Controller.h"

void Controller::control(Plane &plane){
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (plane.getPosition().y - plane.getTexture()->getSize().y / 2 > 0)){
		plane.move(0, -SPEED);
	}
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (plane.getPosition().y + plane.getTexture()->getSize().y / 2 < 800)){
		plane.move(0, SPEED);
	}

	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (plane.getPosition().x - plane.getTexture()->getSize().x / 2 > 0)){
		plane.move(-SPEED, 0);
	}

	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (plane.getPosition().x + plane.getTexture()->getSize().x / 2 < 480)){
		plane.move(SPEED, 0);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		plane.fire();
	}
}