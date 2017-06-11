#include "Sky.h"
Sky::Sky(){
	score = 0;
	level = 1;
	ss_Score.str("");
	ss_Score << score;
	string_Score = ss_Score.str();
	text_Score.setString("Score : " + string_Score);
	font.loadFromFile("resource/fonts/myTTF.ttf");
	text_Score.setFont(font);
	text_Score.setPosition(5, 5);
	text_Score.setColor(sf::Color::Black);
	text_Score.setCharacterSize(24);

	text_Level.setFont(font);
	text_Level.setPosition((480 / 2) - 34 * 2 , 800 / 2);
	text_Level.setColor(sf::Color::Black);
	text_Level.setCharacterSize(34);
	levelClock.restart();
	backgroundClock.restart();
	ifStart = false;
}
void Sky::add(sf::Sprite &sprite){
	if(((Plane*)(&sprite))->getType() == HERO){
		//std::cout << "add Plane\n";
		spriteVector.push_back(&sprite);
		return;
	}
	if(((Plane*)(&sprite))->getType() == ENEMY_1){
		//std::cout << "add enemy\n";
		enemy_1Vector.push_back(&sprite);
		return;
	}
	animationVector.push_back(&sprite);
	//std::cout << "add other\n";
}
void Sky::add(Bullet *bullet){
	if (bullet->getType() == HERO_BULLET){
		std::cout << "add hero bullet\n";
		herobulletVector.push_back(bullet);
		return;
	}
	if (bullet->getType() == ENEMY_BULLET){
		std::cout << "add enemy bullet\n";
		enemybulletVector.push_back(bullet);
		return;
	}
}

void Sky::draw(sf::RenderWindow &window){
	// move all
	this->moveAll();
	// check
	check();
	// draw the hero
	for (int i = 0 ; i != spriteVector.size() ; i ++){
		window.draw(*spriteVector.at(i));
	}
	// draw the hero bullet
	for (int i = 0 ; i != herobulletVector.size() ; i ++){
		window.draw(*herobulletVector.at(i));
	}
	// draw the enemy
	for (int i = 0 ; i != enemy_1Vector.size() ; i ++){
		window.draw(*enemy_1Vector.at(i));
	}
	// draw enemy bullet
	for (int i = 0 ; i != enemybulletVector.size() ; i ++){
		window.draw(*enemybulletVector.at(i));
	}
	// draw the score
	window.draw(text_Score);
	// draw the level
	if (levelClock.getElapsedTime().asSeconds() < sf::seconds(1.5f).asSeconds()){
		window.draw(text_Level);
	}


}
void Sky::moveAll(){
	// move hero bullets
	int i = 0;
	while (i < herobulletVector.size()){
		if(herobulletVector.at(i)->getPosition().y + herobulletVector.at(i)->getTexture()->getSize().y / 2 < 0){
			// erase the bullet
			delete herobulletVector.at(i);
			herobulletVector.erase(herobulletVector.begin() + i);
			continue;
		}
		herobulletVector.at(i)->move(0, -5);
		i ++;
	}
	// move enemybullet
	i = 0;
	while (i < enemybulletVector.size()){
		if(enemybulletVector.at(i)->getPosition().y - enemybulletVector.at(i)->getTexture()->getSize().y / 2 > 800){
			// erase the bullet
			delete enemybulletVector.at(i);
			enemybulletVector.erase(enemybulletVector.begin() + i);
			continue;
		}
		enemybulletVector.at(i)->move(0 , 5);
		i++;
	}
	// move enemy
	i = 0;
	while(i < enemy_1Vector.size()){
		if((enemy_1Vector.at(i)->getPosition().y - enemy_1Vector.at(i)->getTexture()->getSize().y / 2 > 800)||(((Plane*)enemy_1Vector.at(i))->ifCouldErase())){
			// erase the enemy
			delete enemy_1Vector.at(i);
			enemy_1Vector.erase(enemy_1Vector.begin()+i);
			continue;
		}
		((Plane*)enemy_1Vector.at(i))->moveThis();
		i ++;
	}
}
void Sky::check(){
	int i = 0;
	bool tmp = false;
	while(i < herobulletVector.size()){
		for(int j = 0 ; j < enemy_1Vector.size() ; j ++){
			if (herobulletVector.at(i)->getGlobalBounds().intersects(enemy_1Vector.at(j)->getGlobalBounds()) && !((Plane*)enemy_1Vector.at(j))->ifkill()){
				// kill the enemy
				((Plane*)enemy_1Vector.at(j))->kill(this);
				delete herobulletVector.at(i);
				herobulletVector.erase(herobulletVector.begin() + i);
				tmp = true;
				score += 10;
				ss_Score.str("");
				ss_Score << score;
				string_Score = ss_Score.str();
				text_Score.setString("Score : " + string_Score);
				if(level != (score / 100) + 1){
					// change the level
					level = score / 100 + 1;
					ss_Level.str("");
				ss_Level << level;
				string_Level = ss_Level.str();
				text_Level.setString("Level " + string_Level);
				levelClock.restart();
				}
				break;
			}
		}
		if (tmp){
			tmp = false;
			continue;
		}
		i++;
	}
}
int Sky::getLevel(){
	return level;
}
void Sky::guiChu(){
	if (ifStart){
		if (backgroundStartClock.getElapsedTime().asSeconds() > sf::seconds(0.5f).asSeconds()){
			ifStart = false;
			backgroundClock.restart();
			return;
		}

	}
}
