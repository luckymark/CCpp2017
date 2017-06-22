#include"Score.h"
Score::Score()
{
	char str[25];
	for (int i = 0; i < 10; i++) {
		sprintf(str, "Images/Image %d.png", 230 + 2 * i);
		digit_T[i].loadFromFile(str);
		digit_S[i].setTexture(digit_T[i]);
		digit_S[i].setScale(1.7f, 1.7f);
	}
	sign_T.loadFromFile("Images/Shape_252.png");
	sign_S.setTexture(sign_T);
	sign_S.setScale(1.7f, 1.7f);
	sign_S.setPosition(10, 10);//头像位置

	score_T.loadFromFile("Images/Shape_256.png");//设置分数字样
	score_S.setTexture(score_T);
	score_S.setPosition(82, 11);
	score_S.setScale(1.7, 1.7);

	live_T.loadFromFile("Images/Shape_254.png");//设置生命值字样
	live_S.setTexture(live_T);
	live_S.setPosition(82, 42);
	live_S.setScale(1.7, 1.7);

	lives = 5;
	m_score = 0;
	setScore();
}
void Score::addScore(int m_add) { m_score += m_add; }

void Score::delive() { lives--; }

int Score::getLive() { return lives; }

Score::~Score() {}

void Score::Render(Window &l_window)
{
	l_window.Draw(sign_S);
	l_window.Draw(score_S);
	setScore();
	for (int i = 0; i < 8; i++) {    //显示分数
		digit_S[score[i]].setPosition(sf::Vector2f(160 + i * 18, 13));//设置显示位置
		l_window.Draw(digit_S[score[i]]);
	}
	digit_S[lives].setPosition(sf::Vector2f(160, 43));
	l_window.Draw(live_S);
	l_window.Draw(digit_S[lives]);
}

void Score::restart()
{
	lives = 5;
	for (int i = 0; i < 8; ++i)score[i] = 0;
}


void Score::setScore()
{
	int temp = m_score;
	for (int i = 7; i >= 0; --i) {
		score[i] = temp % 10;
		temp /= 10;
	}
}