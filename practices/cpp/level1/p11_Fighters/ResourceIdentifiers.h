#ifndef RESOURCEIDENTIFIERS_H_
#define RESOURCEIDENTIFIERS_H_


// Forward declaration of SFML classes
namespace sf
{
	class Texture;
	class Font;
	class Shader;
	class SoundBuffer;
}

namespace Textures
{
	enum ID
	{
		Entities,
		Jungle,
		TitleScreen,
		Explosion,
		Particle,
		FinishLine,
		ButtonNormal,
		ButtonSelected,
		ButtonPressed
		/*Eagle,
		Raptor,
		Avenger,
		Bullet,
		Missile,
		Desert,
		HealthRefill,
		MissileRefill,
		FireSpread,
		FireRate,
		TitleScreen,
		*/
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

namespace Music
{
	enum ID
	{
		MenuTheme,
		MissionTheme,
	};
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
	};
}
// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;
typedef ResourceHolder<sf::Shader, Shaders::ID> ShaderHolder;
typedef ResourceHolder<sf::SoundBuffer, SoundEffect::ID> SoundBufferHolder;
#endif // RESOURCEIDENTIFIERS_H_
