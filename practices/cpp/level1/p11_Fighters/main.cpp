#include<Windows.h>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include"Game.h"
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	// Program entry point.
	Game game; // Creating our game object.
	while (!game.GetWindow()->IsDone()) {
		// Game loop.
		game.HandleInput();
		game.Update();
		game.Render();
	}
}