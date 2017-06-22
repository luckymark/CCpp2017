#include"Game.h"
Game::Game() : m_window("Fighter on the window", sf::Vector2u(721, 541)) {
	// Setting up class members.
	m_window.setFramerate(60);
	m_fighterTexture.loadFromFile("Images/Shape_74.png");//fighter picture
	m_fighter.setTexture(m_fighterTexture);
	m_fighter.setScale(1.5, 1.5);
	m_fighter.setOrigin(m_fighterTexture.getSize().x/ 2, m_fighterTexture.getSize().y / 2);//set certain
	m_fighter.setPosition(m_window.GetWindowSize().x / 2, m_window.GetWindowSize().y - m_fighterTexture.getSize().y / 2);
	m_backdropTexture.loadFromFile("Images/1.png");
	m_backdrop.setTexture(m_backdropTexture);
	m_backdrop.setScale(1.5, 1.5);
	startT.loadFromFile("Images/Image 361.png");
	startS.setTexture(startT);
	startS.setScale(1.5f, 1.5f);
	startS.setOrigin(startT.getSize().x / 2, startT.getSize().y / 2);
	startS.setPosition(m_window.GetWindowSize().x / 2, m_window.GetWindowSize().y / 2);
	char s1[30];//º”‘ÿ±≥æ∞
	for (int i = 0; i < 6; i++) {
		sprintf(s1, "Images/Shape_%d.png", i + 30);
		backT[i].loadFromFile(s1);
		back2[i].setTexture(backT[i]);
		back2[i].setColor(sf::Color(255, 255, 255, 15));
		back2[i].setScale(1.8, 1.42);
	}
	time=clock.restart();
	for (int i = 0; i < 6; i++)ammo.place[i] = sf::Vector2f(0.f, -52.f);
	shoot = true;
	ct = 0;
	back = 0;
	bct = 0;
	for (int i = 0; i < 152; i++) {
		sprintf(s1, "oput/Vedio (%d).png", i + 1);
		behindT[i].loadFromFile(s1);
		behind[i].setTexture(behindT[i]);
		behind[i].setScale(1.5f, 1.5f);
	}
	next = cloc.restart();
	bT = bc.restart();
	back_2 = 0; 
	for (int i = 0; i < 12; i++) {
		cp[i] = 0;
		BoomTime[i] = BoomClock[i].restart();
	}
	for (int i = 0; i < 12; i++) {
		sprintf(s1, "Images/Shape_%d.png", 85 + 2 * i);
		if (!BoomT[i].loadFromFile(s1))exit(0);
		BoomS[i].setTexture(BoomT[i]);
		BoomS[i].setOrigin(BoomT[i].getSize().x / 2, BoomT[i].getSize().y / 2);
		BoomS[i].setScale(2.f,2.f);
	}
	Sound.playback();
	lives = 5;
	setrest = true;
	restct = 0;
	restT = restC.restart();
	begin = true;
	safeT = safeC.restart();
	Sound.playstart();

	endT.loadFromFile("Images/Image 364.png");
	end_S.setTexture(endT);
	end_S.setScale(1.5, 1.5);
	end_S.setOrigin(endT.getSize().x / 2, endT.getSize().y / 2);
	end_S.setPosition(m_window.GetWindowSize().x / 2, m_window.GetWindowSize().y / 2);
	end = false;
	beginpicture = true;
	end_T = end_C.restart();
}

Game::~Game() {}

void Game::Render() {
	m_window.BeginDraw(); // Clear.
	show_behind();
	m_window.Draw(m_backdrop);
	beshoot();
	boom();
	showEnd();
	if (beginpicture)showBegin();
	if (!end)m_window.Draw(m_fighter);
	showrain();
	for (int i = 0; i < 6; i++) {
		if (ammo.place[i].y > -32) {
			(*ammo.common).setPosition(ammo.place[i]);
			m_window.Draw(*ammo.common);
		}
	}
	score.Render(m_window);
	m_window.EndDraw(); // Display.
}
void Game::Update() {
	m_window.Update(); // Update window events.
}

void Game::HandleInput()
{
	MoveFighter();
	fire();
}

void Game::MoveFighter()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
		&& m_fighter.getPosition().x > m_fighterTexture.getSize().x*1.5 / 2)m_fighter.move(-F_SPEED, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) 
		&& m_fighter.getPosition().x < m_window.GetWindowSize().x - m_fighterTexture.getSize().x*1.5 / 2)m_fighter.move(F_SPEED, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
		&& m_fighter.getPosition().y > m_fighterTexture.getSize().y*1.5 / 2)m_fighter.move(0, -F_SPEED);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
		&& m_fighter.getPosition().y < m_window.GetWindowSize().y - m_fighterTexture.getSize().y*1.5 / 2)m_fighter.move(0, F_SPEED);
	collision();
}

Window* Game::GetWindow()
{
	return &m_window;
}

void Game::fire()
{
	ammo.Dynamic();
	time = clock.getElapsedTime();
	if (time.asMilliseconds() >= 500 && shoot == false) {
		shoot = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
		&& shoot == true){
		if (ct == 6)ct = 0;
		ammo.place[ct++] = sf::Vector2f(m_fighter.getPosition().x - 27, m_fighter.getPosition().y - 10);
		ammo.place[ct++] = sf::Vector2f(m_fighter.getPosition().x + 25, m_fighter.getPosition().y - 10);
		shoot = false;
		time = clock.restart();
		Sound.isShoot();
	}
	for (int i = 0; i < 6; i++) {
		if (ammo.place[i].y > -32)ammo.place[i].y -= 15;
	}
	collision(ammo);
}

void Game::show_behind()
{
	next = cloc.getElapsedTime();
	bT = bc.getElapsedTime();
	m_window.Draw(behind[back]);
	m_window.Draw(back2[back_2]);
	if (next.asMilliseconds() > 90) {
		back++;
		if (back == 152)back = 0;
		next = cloc.restart();
	}
	if (bT.asMilliseconds() > 30) {
		back_2++;
		if (back_2 == 6)back_2 = 0;
		bT = bc.restart();
	}
}

void Game::showrain()
{
	for (int i = 0; i < 15; i++) {
		if (rain.getPos(i).y < 560) {
			rain.setPos(rain.getPos(i));
			m_window.Draw(rain.rainS[(int)rain.getPos(i).y / 160]);
		}
	}
	rain.update();
}

void Game::collision(Ammo &ammo)
{
	for (int i = 0; i < 6; i++) {
		if (ammo.place[i].y < -16)continue;
		for (int j = 0; j < 15; j++) {
			if (rain.getPos(j).y >= 560)continue;
			if (ammo.place[i].x - 12 > rain.getPos(j).x + 8 || ammo.place[i].x + 12 < rain.getPos(j).x - 8
				|| ammo.place[i].y - 24 > rain.getPos(j).y + 12 || ammo.place[i].y + 24 < rain.getPos(j).y-12);
			else {
				cp[bct] = 1;
				boompc[bct] = sf::Vector2f(ammo.place[i].x, ammo.place[i].y - 16);
				BoomTime[bct] = BoomClock[bct].restart();
				bct++;
				if (bct == 12)bct = 0;
				ammo.place[i].y = -33;
				rain.getPos(j).y = 560;
				Sound.playboom();
				score.addScore(10);
				break;
			}
		}
	}
}

void Game::boom()
{
	for (int i = 0; i < 12; i++) {
		if (cp[i]) {
			showboom(i);
		}
	}
}


void Game::showboom(int i)
{
	BoomTime[i] = BoomClock[i].getElapsedTime();
	if (BoomTime[i].asMilliseconds() / 45 >= 12) {
		cp[i] = 0;
		return;
	}
	else {
		BoomS[BoomTime[i].asMilliseconds() / 45].setPosition(boompc[i]);
		m_window.Draw(BoomS[BoomTime[i].asMilliseconds() / 45]);
	}
}

void Game::beshoot()
{
	restT = restC.getElapsedTime();
	if (setrest == true) {
		if (restT.asMilliseconds() / 100 == 0) {
			m_fighter.setColor(sf::Color(255, 255, 255, 50));
		}
		else if (restT.asMilliseconds() / 100 == 1) {
			m_fighter.setColor(sf::Color(255, 255, 255, 255));
		}
		else {
			restT = restC.restart();
			restct++;
		}
		if (restct == 8) {
			setrest = false;
			restct = 0;
		}
	}
}

void Game::collision()
{
	safeT = safeC.getElapsedTime();
	if (safeT.asMilliseconds()>1600)
	for (int j = 0; j < 15; j++) {
		if (rain.getPos(j).y >= 560)continue;
		if (m_fighter.getPosition().x - 25 > rain.getPos(j).x + 8 || m_fighter.getPosition().x + 25 < rain.getPos(j).x - 8
			|| m_fighter.getPosition().y - 25 > rain.getPos(j).y + 12 || m_fighter.getPosition().y + 25 < rain.getPos(j).y - 12);
		else {
			cp[bct] = 1;
			boompc[bct] = sf::Vector2f(m_fighter.getPosition().x, m_fighter.getPosition().y);
			BoomTime[bct] = BoomClock[bct].restart();
			bct++;
			if (bct == 12)bct = 0;
			rain.getPos(j).y = 560;
			Sound.playrest();
			setrest = true;
			score.delive();
			if (!score.getLive())endGame();
			safeT = safeC.restart();
			break;
		}
	}
}

void Game::endGame()
{
	for (int i = 0; i < 6; i++)ammo.place[i].y = -33;
	for (int i = 0; i < 15; i++) {
		cp[bct] = 1;
		boompc[bct] = sf::Vector2f(rain.getPos(i).x, rain.getPos(i).y);
		BoomTime[bct] = BoomClock[bct].restart();
		bct++;
		rain.getPos(i).y = 560;
	}
	end = true;
	rain.setnew(false);
	end_T = end_C.restart();
}

void Game::showEnd()
{
	end_T = end_C.getElapsedTime();
	if (end) {
		if (end_T.asMilliseconds() < 80) {
			m_window.Draw(end_S);
		}
		else if (end_T.asMilliseconds() < 160) {
			end_S.setColor(sf::Color(255, 255, 255, 20));
			m_window.Draw(end_S);
		}
		else if (end_T.asMilliseconds() < 240) {
			end_S.setColor(sf::Color(255, 255, 255, 255));
			m_window.Draw(end_S);
		}
		else if (end_T.asMilliseconds() < 320) {
			end_S.setColor(sf::Color(255, 255, 255, 20));
			m_window.Draw(end_S);
		}
		else if (end_T.asMilliseconds() < 400) {
			end_S.setColor(sf::Color(255, 255, 255, 255));
			m_window.Draw(end_S);
		}
		else if (end_T.asMilliseconds() < 480) {
			end_S.setColor(sf::Color(255, 255, 255, 20));
			m_window.Draw(end_S);
		}
		else {
			end_S.setColor(sf::Color(255, 255, 255, 255));
			m_window.Draw(end_S);
		}
	}
}

void Game::showBegin()
{
	end_T = end_C.getElapsedTime();
	if (beginpicture) {
		if (end_T.asMilliseconds() < 80) {
			m_window.Draw(startS);
		}
		else if (end_T.asMilliseconds() < 160) {
			startS.setColor(sf::Color(255, 255, 255, 20));
			m_window.Draw(startS);
		}
		else if (end_T.asMilliseconds() < 240) {
			startS.setColor(sf::Color(255, 255, 255, 255));
			m_window.Draw(startS);
		}
		else if (end_T.asMilliseconds() < 320) {
			startS.setColor(sf::Color(255, 255, 255, 20));
			m_window.Draw(startS);
		}
		else if (end_T.asMilliseconds() < 400) {
			startS.setColor(sf::Color(255, 255, 255, 255));
			m_window.Draw(startS);
		}
		else if (end_T.asMilliseconds() < 480) {
			startS.setColor(sf::Color(255, 255, 255, 20));
			m_window.Draw(startS);
		}
		else {
			beginpicture = false;
		}
	}
}