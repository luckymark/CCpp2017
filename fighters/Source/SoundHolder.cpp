#include"Include\SoundHolder.hpp"

SoundHolder::SoundHolder()
{
	mSounds.load(SoundEffect::AlliedGunfire, "Media/Sound/AlliedGunfire.wav");
	mSounds.load(SoundEffect::EnemyGunfire, "Media/Sound/EnemyGunfire.wav");
	mSounds.load(SoundEffect::Explosion1, "Media/Sound/Explosion1.wav");
	mSounds.load(SoundEffect::Explosion2, "Media/Sound/Explosion2.wav");
	mSounds.load(SoundEffect::LaunchMissile, "Media/Sound/LaunchMissile.wav");
	mSounds.load(SoundEffect::CollectPickup, "Media/Sound/CollectPickup.wav");
	mSounds.load(SoundEffect::Upgrade, "Media/Sound/Upgrade.wav");
	mSounds.load(SoundEffect::Purchase, "Media/Sound/Purchase.wav");
}

void SoundHolder::play(SoundEffect::ID type)
{
	sf::Sound toQueue;
	toQueue.setBuffer(mSounds.get(type));
	soundQueue.push(toQueue);

	sf::Sound& sound = soundQueue.back();
	sound.play();

}
void SoundHolder::emptyQueue()
{
	if (!soundQueue.empty())
	{
		if (soundQueue.front().getStatus() == sf::Sound::Stopped)
		{
			soundQueue.pop();
		}
	}

}
