#ifndef _AUDIO_H_
#define _AUDIO_H_
class Audio {
public:
	static Audio* getInstance();
	void playBGM();
	void playEnemy1();
	void playEnemy2();
	void playEnemy3();
	void playBullet();
	void playBomb();
	void prepare();
private:
	static Audio* m_instance;
};
#endif
