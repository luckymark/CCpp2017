#ifndef SCORE_H_
#define SCORE_H_
#include"window.h"
class Score{
private:
	sf::Sprite digit_S[10];
	sf::Texture digit_T[10];
	sf::Sprite live_S;
	sf::Texture live_T;
	sf::Sprite sign_S;
	sf::Texture sign_T;
	sf::Sprite score_S;
	sf::Texture score_T;
	int lives;
	int score[8];
	int m_score;
public:
	Score();
	~Score();
	void setScore();
	void addScore(int m_add);
	void Render(Window &l_window);
	void delive();
	void restart();
	int getLive();
};
#endif // !TEXT_H_