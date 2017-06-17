#ifndef BOOK_RESOURCEIDENTIFIERS_HPP
#define BOOK_RESOURCEIDENTIFIERS_HPP


// Forward declaration of SFML classes
namespace sf
{
	class Texture;
	class Font;
	class SoundBuffer;
	class Shader;
}

namespace SoundEffect
{
	enum ID
	{
		AlliedGunfire,
		EnemyGunfire,
		Explosion1,
		Explosion2,
		LaunchMissile,
		CollectPickup,
		Button,
		Upgrade,
		Purchase,
	};
}

namespace Music
{
	enum ID
	{
		IntroTheme,
		BattleTheme1,
		BattleTheme2,
		DefeatedTheme,
		PauseTheme,
	};
}

namespace Textures
{
	enum ID
	{
		Eagle,
		Raptor,
		Avenger,
		Bullet,
		Missile,
		Desert,
		Jungle,
		HealthRefill,
		MissileRefill,
		FireSpread,
		FireRate,
		TitleScreen,
		ButtonNormal,
		ButtonSelected,
		ButtonPressed,
		Explosion,
		Spark,
		Explosion_missile,
		RebornCircle,
		UpCloud,
		DownCloud,
		MidCloud,
	};
}

namespace Shaders
{
	enum ID
	{
		BrightnessPass,
		DownSamplePass,
		GaussianBlurPass,
		AddPass,
	};
}

namespace Fonts
{
	enum ID
	{
		Main,
	};
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID>			TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>					FontHolder;
typedef ResourceHolder<sf::SoundBuffer, SoundEffect::ID>	SoundBufferHolder;
typedef ResourceHolder<sf::Shader, Shaders::ID>				ShaderHolder;
#endif // BOOK_RESOURCEIDENTIFIERS_HPP
